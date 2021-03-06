package qmarket4go

/*
#cgo CFLAGS: -I${SRCDIR} -fPIC
#cgo LDFLAGS: -L${SRCDIR} -lcqdammdapi

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "cgoFtcdMdApiImpl.h"
*/
import "C"
import (
	"fmt"
	"log"
	"os"
	"strconv"
	"sync/atomic"
	"time"
	"unsafe"

	iconv "github.com/djimenez/iconv-go"
)

// QMdAPICallback 行情API回调接口
type QMdAPICallback interface {
	OnFrontConnected()
	OnFrontDisConnected(reason int)
	OnHeartBeatWarning(time int)
	OnPackageStart(topicID, sequenceNO int)
	OnPackageEnd(topicID, sequenceNO int)
	OnMultiHeartbeat(currTime, multiCastIP string)
	OnStopMultiTopic(topicID int)
	UDPMarketData(rtn *GoQdamFtdcDepthMarketDataField)
	OnRspError(err *GoQdamFtdcRspInfoField, reqID int, isLast bool)
	OnRspUserLogin(rsp *GoQdamFtdcRspUserLoginField, err *GoQdamFtdcRspInfoField, reqID int, isLast bool)
	OnRspUserLogout(rsp *GoQdamFtdcRspUserLogoutField, err *GoQdamFtdcRspInfoField, reqID int, isLast bool)
	OnRtnDepthMarketData(rtn *GoQdamFtdcDepthMarketDataField)
	OnRtnMultiDepthMarketData(rtn *GoQdamFtdcDepthMarketDataField)
	OnRspSubMarketData(rsp *GoQdamFtdcSpecificInstrumentField, err *GoQdamFtdcRspInfoField, reqID int, isLast bool)
	OnRspUnSubMarketData(rsp *GoQdamFtdcSpecificInstrumentField, err *GoQdamFtdcRspInfoField, reqID int, isLast bool)
	OnRtnMBLMarketData(rtn *GoQdamFtdcMBLMarketDataField)
	OnRtnQmdInstrumentStatu(rtn *GoQdamFtdcQmdInstrumentStateField)
	OnRspSubscribeTopic(rsp *GoQdamFtdcDisseminationField, err *GoQdamFtdcRspInfoField, reqID int, isLast bool)
	OnRspQryTopic(rsp *GoQdamFtdcDisseminationField, err *GoQdamFtdcRspInfoField, reqID int, isLast bool)
	OnRspQryMarketData(rsp *GoQdamFtdcRspMarketDataField, err *GoQdamFtdcRspInfoField, reqID int, isLast bool)
}

func convertDepthMarketData(qmdata *C.CQdamFtdcDepthMarketDataField) *GoQdamFtdcDepthMarketDataField {
	data := GoQdamFtdcDepthMarketDataField{}

	data.TradingDay = C.GoString(&qmdata.TradingDay[0])
	data.PreSettlementPrice = float64(qmdata.PreSettlementPrice)
	data.PreClosePrice = float64(qmdata.PreClosePrice)
	data.PreOpenInterest = float64(qmdata.PreOpenInterest)
	data.PreDelta = float64(qmdata.PreDelta)
	data.OpenPrice = float64(qmdata.OpenPrice)
	data.HighestPrice = float64(qmdata.HighestPrice)
	data.LowestPrice = float64(qmdata.LowestPrice)
	data.ClosePrice = float64(qmdata.ClosePrice)
	data.UpperLimitPrice = float64(qmdata.UpperLimitPrice)
	data.LowerLimitPrice = float64(qmdata.LowerLimitPrice)
	data.SettlementPrice = float64(qmdata.SettlementPrice)
	data.CurrDelta = float64(qmdata.CurrDelta)
	data.LastPrice = float64(qmdata.LastPrice)
	data.Volume = int(qmdata.Volume)
	data.Turnover = float64(qmdata.Turnover)
	data.OpenInterest = float64(qmdata.OpenInterest)
	data.InstrumentID = C.GoString(&qmdata.InstrumentID[0])

	timeString := fmt.Sprintf("%s %s.%03d", time.Now().Format("2006-01-02"), C.GoString(&qmdata.UpdateTime[0]), qmdata.UpdateMillisec)
	updateTime, _ := time.Parse("2006-01-02 15:04:05.000", timeString)
	data.UpdateTime = updateTime

	data.ExchangeID = C.GoString(&qmdata.ExchangeID[0])
	data.VolumeAskLot = int(qmdata.VolumeAskLot)
	data.VolumeBidLot = int(qmdata.VolumeBidLot)

	status, _ := strconv.ParseInt(string(qmdata.InstrumentStatus), 10, 32)
	data.InstrumentStatus = insStatus(status)

	data.Asks = make([]priceItem, 0, 5)
	data.Bids = make([]priceItem, 0, 5)

	if qmdata.AskVolume1 > 0 {
		data.Asks = append(data.Asks, priceItem{Price: float64(qmdata.AskPrice1), Volume: int(qmdata.AskVolume1)})

		if qmdata.AskVolume2 > 0 {
			data.Asks = append(data.Asks, priceItem{Price: float64(qmdata.AskPrice2), Volume: int(qmdata.AskVolume2)})

			if qmdata.AskVolume3 > 0 {
				data.Asks = append(data.Asks, priceItem{Price: float64(qmdata.AskPrice3), Volume: int(qmdata.AskVolume3)})

				if qmdata.AskVolume4 > 0 {
					data.Asks = append(data.Asks, priceItem{Price: float64(qmdata.AskPrice4), Volume: int(qmdata.AskVolume4)})

					if qmdata.AskVolume5 > 0 {
						data.Asks = append(data.Asks, priceItem{Price: float64(qmdata.AskPrice5), Volume: int(qmdata.AskVolume5)})
					}
				}
			}
		}
	}

	if qmdata.BidVolume1 > 0 {
		data.Bids = append(data.Bids, priceItem{Price: float64(qmdata.BidPrice1), Volume: int(qmdata.BidVolume1)})

		if qmdata.BidVolume2 > 0 {
			data.Bids = append(data.Bids, priceItem{Price: float64(qmdata.BidPrice2), Volume: int(qmdata.BidVolume2)})

			if qmdata.BidVolume3 > 0 {
				data.Bids = append(data.Bids, priceItem{Price: float64(qmdata.BidPrice3), Volume: int(qmdata.BidVolume3)})

				if qmdata.BidVolume4 > 0 {
					data.Bids = append(data.Bids, priceItem{Price: float64(qmdata.BidPrice4), Volume: int(qmdata.BidVolume4)})

					if qmdata.BidVolume5 > 0 {
						data.Bids = append(data.Bids, priceItem{Price: float64(qmdata.BidPrice5), Volume: int(qmdata.BidVolume5)})
					}
				}
			}
		}
	}

	if C.isLevel2() == 1 {
		if qmdata.AskVolume6 > 0 {
			data.Asks = append(data.Asks, priceItem{Price: float64(qmdata.AskPrice6), Volume: int(qmdata.AskVolume6)})

			if qmdata.AskVolume7 > 0 {
				data.Asks = append(data.Asks, priceItem{Price: float64(qmdata.AskPrice7), Volume: int(qmdata.AskVolume7)})

				if qmdata.AskVolume8 > 0 {
					data.Asks = append(data.Asks, priceItem{Price: float64(qmdata.AskPrice8), Volume: int(qmdata.AskVolume8)})

					if qmdata.AskVolume9 > 0 {
						data.Asks = append(data.Asks, priceItem{Price: float64(qmdata.AskPrice9), Volume: int(qmdata.AskVolume9)})

						if qmdata.AskVolume10 > 0 {
							data.Asks = append(data.Asks, priceItem{Price: float64(qmdata.AskPrice10), Volume: int(qmdata.AskVolume10)})
						}
					}
				}
			}
		}

		if qmdata.BidVolume6 > 0 {
			data.Bids = append(data.Bids, priceItem{Price: float64(qmdata.BidPrice6), Volume: int(qmdata.BidVolume6)})

			if qmdata.BidVolume7 > 0 {
				data.Bids = append(data.Bids, priceItem{Price: float64(qmdata.BidPrice7), Volume: int(qmdata.BidVolume7)})

				if qmdata.BidVolume8 > 0 {
					data.Bids = append(data.Bids, priceItem{Price: float64(qmdata.BidPrice8), Volume: int(qmdata.BidVolume8)})

					if qmdata.BidVolume9 > 0 {
						data.Bids = append(data.Bids, priceItem{Price: float64(qmdata.BidPrice9), Volume: int(qmdata.BidVolume9)})

						if qmdata.BidVolume10 > 0 {
							data.Bids = append(data.Bids, priceItem{Price: float64(qmdata.BidPrice10), Volume: int(qmdata.BidVolume10)})
						}
					}
				}
			}
		}
	}

	return &data
}

func convertRspInfo(pRspInfo *C.CQdamFtdcRspInfoField) *GoQdamFtdcRspInfoField {
	data := GoQdamFtdcRspInfoField{}

	if pRspInfo == nil {
		return &data
	}

	if pRspInfo.ErrorID != 0 {
		data.ErrorID = int(pRspInfo.ErrorID)
	}
	msg, _ := iconv.ConvertString(C.GoString(&pRspInfo.ErrorMsg[0]), "gbk", "utf-8")
	data.ErrorMsg = msg

	return &data
}

func convertRspUserLogin(pRspUserLogin *C.CQdamFtdcRspUserLoginField) *GoQdamFtdcRspUserLoginField {
	data := GoQdamFtdcRspUserLoginField{}

	data.TradingDay = C.GoString(&pRspUserLogin.TradingDay[0])
	data.BrokerID = C.GoString(&pRspUserLogin.BrokerID[0])
	data.UserID = C.GoString(&pRspUserLogin.UserID[0])

	loginTime, _ := time.Parse("15:04:05", C.GoString(&pRspUserLogin.LoginTime[0]))
	data.LoginTime = loginTime

	maxLocalID, _ := strconv.Atoi(C.GoString(&pRspUserLogin.MaxOrderLocalID[0]))
	data.MaxOrderLocalID = maxLocalID

	data.TradingSystemName = C.GoString(&pRspUserLogin.TradingSystemName[0])
	data.DataCenterID = int(pRspUserLogin.DataCenterID)
	data.PrivateFlowSize = int(pRspUserLogin.PrivateFlowSize)
	data.UserFlowSize = int(pRspUserLogin.UserFlowSize)
	data.LoginInfo = C.GoString(&pRspUserLogin.LoginInfo[0])
	data.SessionID = int(pRspUserLogin.SessionID)
	data.FrontID = int(pRspUserLogin.FrontID)

	return &data
}

func convertRspUserLogout(pRspUserLogout *C.CQdamFtdcRspUserLogoutField) *GoQdamFtdcRspUserLogoutField {
	data := GoQdamFtdcRspUserLogoutField{}

	data.UserID = C.GoString(&pRspUserLogout.UserID[0])
	data.BrokerID = C.GoString(&pRspUserLogout.BrokerID[0])

	return &data
}

func convertSpecificInstrument(pSpecificInstrument *C.CQdamFtdcSpecificInstrumentField) *GoQdamFtdcSpecificInstrumentField {
	data := GoQdamFtdcSpecificInstrumentField{}

	data.InstrumentID = C.GoString(&pSpecificInstrument.InstrumentID[0])

	return &data
}

func convertBLMarketData(pMBLMarketData *C.CQdamFtdcMBLMarketDataField) *GoQdamFtdcMBLMarketDataField {
	data := GoQdamFtdcMBLMarketDataField{}

	data.InstrumentID = C.GoString(&pMBLMarketData.InstrumentID[0])

	d, _ := strconv.ParseInt(string(pMBLMarketData.Direction), 10, 32)
	data.Direction = direction(d)

	data.Price = float64(pMBLMarketData.Price)
	data.Volume = int(pMBLMarketData.Volume)

	timeString := fmt.Sprintf("%s %s.%03d", time.Now().Format("2006-01-02"), C.GoString(&pMBLMarketData.UpdateTime[0]), pMBLMarketData.UpdateMillisec)
	updateTime, _ := time.Parse("2006-01-02 15:04:05.000", timeString)
	data.UpdateTime = updateTime

	return &data
}

func convertQmdInstrumentState(pQmdInstrumentState *C.CQdamFtdcQmdInstrumentStateField) *GoQdamFtdcQmdInstrumentStateField {
	data := GoQdamFtdcQmdInstrumentStateField{}

	data.ExchangeID = C.GoString(&pQmdInstrumentState.ExchangeID[0])
	data.InstrumentID = C.GoString(&pQmdInstrumentState.InstrumentID[0])

	status, _ := strconv.ParseInt(string(pQmdInstrumentState.InstrumentStatus), 10, 32)
	data.InstrumentStatus = insStatus(status)

	return &data
}

func convertDissemination(pDissemination *C.CQdamFtdcDisseminationField) *GoQdamFtdcDisseminationField {
	data := GoQdamFtdcDisseminationField{}

	data.SequenceNo = int(pDissemination.SequenceNo)
	data.SequenceSeries = int(pDissemination.SequenceSeries)

	return &data
}

func convertRspMarketData(pRspMarketData *C.CQdamFtdcRspMarketDataField) *GoQdamFtdcRspMarketDataField {
	data := GoQdamFtdcRspMarketDataField{}

	data.ExchangeID = C.GoString(&pRspMarketData.ExchangeID[0])
	data.TradingDay = C.GoString(&pRspMarketData.TradingDay[0])
	data.PreSettlementPrice = float64(pRspMarketData.PreSettlementPrice)
	data.PreClosePrice = float64(pRspMarketData.PreClosePrice)
	data.PreOpenInterest = float64(pRspMarketData.PreOpenInterest)
	data.PreDelta = float64(pRspMarketData.PreDelta)
	data.OpenPrice = float64(pRspMarketData.OpenPrice)
	data.HighestPrice = float64(pRspMarketData.HighestPrice)
	data.LowestPrice = float64(pRspMarketData.LowestPrice)
	data.ClosePrice = float64(pRspMarketData.ClosePrice)
	data.UpperLimitPrice = float64(pRspMarketData.UpperLimitPrice)
	data.LowerLimitPrice = float64(pRspMarketData.LowerLimitPrice)
	data.SettlementPrice = float64(pRspMarketData.SettlementPrice)
	data.CurrDelta = float64(pRspMarketData.CurrDelta)
	data.LastPrice = float64(pRspMarketData.LastPrice)
	data.Volume = int(pRspMarketData.Volume)
	data.Turnover = float64(pRspMarketData.Turnover)
	data.OpenInterest = float64(pRspMarketData.OpenInterest)
	data.BidPrice = float64(pRspMarketData.BidPrice1)
	data.BidVolume = int(pRspMarketData.BidVolume1)
	data.AskPrice = float64(pRspMarketData.AskPrice1)
	data.AskVolume = int(pRspMarketData.AskVolume1)
	data.InstrumentID = C.GoString(&pRspMarketData.InstrumentID[0])

	timeString := fmt.Sprintf("%s %s.%03d", time.Now().Format("2006-01-02"), C.GoString(&pRspMarketData.UpdateTime[0]), pRspMarketData.UpdateMillisec)
	updateTime, _ := time.Parse("2006-01-02 15:04:05.000", timeString)
	data.UpdateTime = updateTime

	return &data
}

// QMdAPI 行情API数据封装
type QMdAPI struct {
	clientID  int
	FrontAddr string
	FensAddr  string
	Connected bool
	UserInfo  GoQdamFtdcReqUserLoginField
	Logged    bool
	reqID     int64
}

var callbacks map[int]QMdAPICallback

//export goOnFrontConnected
func goOnFrontConnected(client C.int) {
	callback, exist := callbacks[int(client)]

	if exist {
		callback.OnFrontConnected()
	}
}

//export goOnFrontDisconnected
func goOnFrontDisconnected(client C.int, nReason C.int) {
	callback, exist := callbacks[int(client)]

	if exist {
		callback.OnFrontDisConnected(int(nReason))
	}
}

//export goOnHeartBeatWarning
func goOnHeartBeatWarning(client C.int, nTimeLapse C.int) {
	callback, exist := callbacks[int(client)]

	if exist {
		callback.OnHeartBeatWarning(int(nTimeLapse))
	}
}

//export goOnPackageStart
func goOnPackageStart(client C.int, nTopicID C.int, nSequenceNo C.int) {
	callback, exist := callbacks[int(client)]

	if exist {
		callback.OnPackageStart(int(nTopicID), int(nSequenceNo))
	}
}

//export goOnPackageEnd
func goOnPackageEnd(client C.int, nTopicID C.int, nSequenceNo C.int) {
	callback, exist := callbacks[int(client)]

	if exist {
		callback.OnPackageEnd(int(nTopicID), int(nSequenceNo))
	}
}

//export goOnMultiHeartbeat
func goOnMultiHeartbeat(client C.int, CurrTime *C.char, MultiCastIP *C.char) {
	callback, exist := callbacks[int(client)]

	if exist {
		callback.OnMultiHeartbeat(C.GoString(CurrTime), C.GoString(MultiCastIP))
	}
}

//export goOnStopMultiTopic
func goOnStopMultiTopic(client C.int, nTopicID C.int) {
	callback, exist := callbacks[int(client)]

	if exist {
		callback.OnStopMultiTopic(int(nTopicID))
	}
}

//export goUDPMarketData
func goUDPMarketData(client C.int, qmdata *C.CQdamFtdcDepthMarketDataField) {
	callback, exist := callbacks[int(client)]

	if exist {
		callback.UDPMarketData(convertDepthMarketData(qmdata))
	}
}

//export goOnRspError
func goOnRspError(client C.int, pRspInfo *C.CQdamFtdcRspInfoField, nRequestID C.int, bIsLast C.bool) {
	callback, exist := callbacks[int(client)]

	if exist {
		callback.OnRspError(convertRspInfo(pRspInfo), int(nRequestID), bool(bIsLast))
	}
}

//export goOnRspUserLogin
func goOnRspUserLogin(client C.int, pRspUserLogin *C.CQdamFtdcRspUserLoginField, pRspInfo *C.CQdamFtdcRspInfoField, nRequestID C.int, bIsLast C.bool) {
	callback, exist := callbacks[int(client)]

	if exist {
		callback.OnRspUserLogin(convertRspUserLogin(pRspUserLogin), convertRspInfo(pRspInfo), int(nRequestID), bool(bIsLast))
	}
}

//export goOnRspUserLogout
func goOnRspUserLogout(client C.int, pRspUserLogout *C.CQdamFtdcRspUserLogoutField, pRspInfo *C.CQdamFtdcRspInfoField, nRequestID C.int, bIsLast C.bool) {
	callback, exist := callbacks[int(client)]

	if exist {
		callback.OnRspUserLogout(convertRspUserLogout(pRspUserLogout), convertRspInfo(pRspInfo), int(nRequestID), bool(bIsLast))
	}
}

//export goOnRtnDepthMarketData
func goOnRtnDepthMarketData(client C.int, pDepthMarketData *C.CQdamFtdcDepthMarketDataField) {
	callback, exist := callbacks[int(client)]

	if exist {
		callback.OnRtnDepthMarketData(convertDepthMarketData(pDepthMarketData))
	}
}

//export goOnRtnMultiDepthMarketData
func goOnRtnMultiDepthMarketData(client C.int, pDepthMarketData *C.CQdamFtdcDepthMarketDataField) {
	callback, exist := callbacks[int(client)]

	if exist {
		callback.OnRtnMultiDepthMarketData(convertDepthMarketData(pDepthMarketData))
	}
}

//export goOnRspSubMarketData
func goOnRspSubMarketData(client C.int, pSpecificInstrument *C.CQdamFtdcSpecificInstrumentField, pRspInfo *C.CQdamFtdcRspInfoField, nRequestID C.int, bIsLast C.bool) {
	callback, exist := callbacks[int(client)]

	if exist {
		callback.OnRspSubMarketData(convertSpecificInstrument(pSpecificInstrument), convertRspInfo(pRspInfo), int(nRequestID), bool(bIsLast))
	}
}

//export goOnRspUnSubMarketData
func goOnRspUnSubMarketData(client C.int, pSpecificInstrument *C.CQdamFtdcSpecificInstrumentField, pRspInfo *C.CQdamFtdcRspInfoField, nRequestID C.int, bIsLast C.bool) {
	callback, exist := callbacks[int(client)]

	if exist {
		callback.OnRspUnSubMarketData(convertSpecificInstrument(pSpecificInstrument), convertRspInfo(pRspInfo), int(nRequestID), bool(bIsLast))
	}
}

//export goOnRtnMBLMarketData
func goOnRtnMBLMarketData(client C.int, pMBLMarketData *C.CQdamFtdcMBLMarketDataField) {
	callback, exist := callbacks[int(client)]

	if exist {
		callback.OnRtnMBLMarketData(convertBLMarketData(pMBLMarketData))
	}
}

//export goOnRtnQmdInstrumentStatu
func goOnRtnQmdInstrumentStatu(client C.int, pQmdInstrumentState *C.CQdamFtdcQmdInstrumentStateField) {
	callback, exist := callbacks[int(client)]

	if exist {
		callback.OnRtnQmdInstrumentStatu(convertQmdInstrumentState(pQmdInstrumentState))
	}
}

//export goOnRspSubscribeTopic
func goOnRspSubscribeTopic(client C.int, pDissemination *C.CQdamFtdcDisseminationField, pRspInfo *C.CQdamFtdcRspInfoField, nRequestID C.int, bIsLast C.bool) {
	callback, exist := callbacks[int(client)]

	if exist {
		callback.OnRspSubscribeTopic(convertDissemination(pDissemination), convertRspInfo(pRspInfo), int(nRequestID), bool(bIsLast))
	}
}

//export goOnRspQryTopic
func goOnRspQryTopic(client C.int, pDissemination *C.CQdamFtdcDisseminationField, pRspInfo *C.CQdamFtdcRspInfoField, nRequestID C.int, bIsLast C.bool) {
	callback, exist := callbacks[int(client)]

	if exist {
		callback.OnRspQryTopic(convertDissemination(pDissemination), convertRspInfo(pRspInfo), int(nRequestID), bool(bIsLast))
	}
}

//export goOnRspQryMarketData
func goOnRspQryMarketData(client C.int, pRspMarketData *C.CQdamFtdcRspMarketDataField, pRspInfo *C.CQdamFtdcRspInfoField, nRequestID C.int, bIsLast C.bool) {
	callback, exist := callbacks[int(client)]

	if exist {
		callback.OnRspQryMarketData(convertRspMarketData(pRspMarketData), convertRspInfo(pRspInfo), int(nRequestID), bool(bIsLast))
	}
}

func pathExists(path string) (bool, error) {
	_, err := os.Stat(path)
	if err == nil {
		return true, nil
	}
	if os.IsNotExist(err) {
		return false, nil
	}
	return false, err
}

// InitAPI 初始化行情API
func (api *QMdAPI) InitAPI(flowPath string) {
	exist, _ := pathExists(flowPath)
	if !exist {
		os.Mkdir(flowPath, os.ModePerm)
	}

	clientID := int(C.InitApi(C.CString(flowPath)))
	api.clientID = clientID
}

// RegisterCallback 注册用户回调接口
func (api *QMdAPI) RegisterCallback(cb QMdAPICallback) {
	if api.clientID == 0 {
		panic("Please call function InitApi first.")
	}

	if callbacks == nil {
		callbacks = make(map[int]QMdAPICallback)
	}

	callbacks[api.clientID] = cb

	C.SetCallbackFunOnFrontConnected(C.ClientID(api.clientID), (C.FunOnFrontConnected)(unsafe.Pointer(C.cgoOnFrontConnected)))
	C.SetCallbackFunOnFrontDisconnected(C.ClientID(api.clientID), (C.FunOnFrontDisconnected)(unsafe.Pointer(C.cgoOnFrontDisconnected)))

	C.SetCallbackFunOnHeartBeatWarning(C.ClientID(api.clientID), (C.FunOnHeartBeatWarning)(unsafe.Pointer(C.cgoOnHeartBeatWarning)))
	C.SetCallbackFunOnPackageStart(C.ClientID(api.clientID), (C.FunOnPackageStart)(unsafe.Pointer(C.cgoOnPackageStart)))
	C.SetCallbackFunOnPackageEnd(C.ClientID(api.clientID), (C.FunOnPackageStart)(unsafe.Pointer(C.cgoOnPackageEnd)))

	C.SetCallbackFunUdpMarketData(C.ClientID(api.clientID), (C.FunUdpMarketData)(unsafe.Pointer(C.cgoUDPMarketData)))

	C.SetCallbackFunOnRspError(C.ClientID(api.clientID), (C.FunOnRspError)(unsafe.Pointer(C.cgoOnRspError)))

	C.SetCallbackFunOnRspUserLogin(C.ClientID(api.clientID), (C.FunOnRspUserLogin)(unsafe.Pointer(C.cgoOnRspUserLogin)))
	C.SetCallbackFunOnRspUserLogout(C.ClientID(api.clientID), (C.FunOnRspUserLogout)(unsafe.Pointer(C.cgoOnRspUserLogout)))

	C.SetCallbackFunOnRtnDepthMarketData(C.ClientID(api.clientID), (C.FunOnRtnDepthMarketData)(unsafe.Pointer(C.cgoOnRtnDepthMarketData)))
	C.SetCallbackFunOnRtnMultiDepthMarketData(C.ClientID(api.clientID), (C.FunOnRtnMultiDepthMarketData)(unsafe.Pointer(C.cgoOnRtnMultiDepthMarketData)))

	C.SetCallbackFunOnRspSubMarketData(C.ClientID(api.clientID), (C.FunOnRspSubMarketData)(unsafe.Pointer(C.cgoOnRspSubMarketData)))
	C.SetCallbackFunOnRspUnSubMarketData(C.ClientID(api.clientID), (C.FunOnRspUnSubMarketData)(unsafe.Pointer(C.cgoOnRspUnSubMarketData)))

	C.SetCallbackFunOnRtnMBLMarketData(C.ClientID(api.clientID), (C.FunOnRtnMBLMarketData)(unsafe.Pointer(C.cgoOnRtnMBLMarketData)))

	C.SetCallbackFunOnRtnQmdInstrumentStatu(C.ClientID(api.clientID), (C.FunOnRtnQmdInstrumentStatu)(unsafe.Pointer(C.cgoOnRtnQmdInstrumentStatu)))

	C.SetCallbackFunOnRspSubscribeTopic(C.ClientID(api.clientID), (C.FunOnRspSubscribeTopic)(unsafe.Pointer(C.cgoOnRspSubscribeTopic)))
	C.SetCallbackFunOnRspQryTopic(C.ClientID(api.clientID), (C.FunOnRspQryTopic)(unsafe.Pointer(C.cgoOnRspQryTopic)))
	C.SetCallbackFunOnRspQryMarketData(C.ClientID(api.clientID), (C.FunOnRspQryMarketData)(unsafe.Pointer(C.cgoOnRspQryMarketData)))
}

// RegisterFront API注册前置地址
func (api *QMdAPI) RegisterFront(frontAddr string) {
	api.FrontAddr = frontAddr
	C.RegisterFront(C.ClientID(api.clientID), C.CString(frontAddr))
}

// RegisterNameServer 注册Fens地址
func (api *QMdAPI) RegisterNameServer(fensAddr string) {
	api.FensAddr = fensAddr
	C.RegisterNameServer(C.ClientID(api.clientID), C.CString(fensAddr))
}

// SubscribeMarketDataTopic 订阅行情Topic
func (api *QMdAPI) SubscribeMarketDataTopic(topicID, resumeType int) {
	C.SubscribeMarketDataTopic(C.ClientID(api.clientID), C.int(topicID), C.QDAM_TE_RESUME_TYPE(resumeType))
}

// Init 初始化行情API连接
func (api *QMdAPI) Init() {
	C.Init(C.ClientID(api.clientID))
}

// Release 释放行情API资源
func (api *QMdAPI) Release() {
	C.Release(C.ClientID(api.clientID))
}

func (api *QMdAPI) getReqID() int64 {
	return atomic.AddInt64(&api.reqID, 1)
}

// Login 用户登录请求
func (api *QMdAPI) Login(login *GoQdamFtdcReqUserLoginField) int {
	api.UserInfo = *login

	loginReq := C.CQdamFtdcReqUserLoginField{}

	cUserID := C.CString(login.UserID)
	C.strncpy(&loginReq.UserID[0], cUserID, C.sizeof_TQdamFtdcUserIDType-1)

	cBrokerID := C.CString(login.BrokerID)
	C.strncpy(&loginReq.BrokerID[0], cBrokerID, C.sizeof_TQdamFtdcBrokerIDType-1)

	cPassword := C.CString(login.Password)
	C.strncpy(&loginReq.Password[0], cPassword, C.sizeof_TQdamFtdcPasswordType-1)

	rtn := C.ReqUserLogin(C.ClientID(api.clientID), &loginReq, C.int(api.getReqID()))

	return int(rtn)
}

// ReLogin 用户重登录
func (api *QMdAPI) ReLogin() {
	api.Login(&api.UserInfo)
}

// SubMarketData 订阅合约行情
func (api *QMdAPI) SubMarketData(instruments ...string) {
	count := len(instruments)
	cStrings := make([]*C.char, count)

	for idx := 0; idx < count; idx++ {
		cStrings[idx] = C.CString(instruments[idx])
	}

	C.SubMarketData(C.ClientID(api.clientID), &cStrings[0], C.int(count))
}

// UnSubMarketData 取消合约行情订阅
func (api *QMdAPI) UnSubMarketData(instruments ...string) {
	count := len(instruments)
	cStrings := make([]*C.char, count)

	for idx := 0; idx < count; idx++ {
		cStrings[idx] = C.CString(instruments[idx])
	}

	C.UnSubMarketData(C.ClientID(api.clientID), &cStrings[0], C.int(count))
}

// OnFrontConnected 前置连接消息
func (api *QMdAPI) OnFrontConnected() {
	api.Connected = true
	log.Printf("Front[%s] connected.\n", api.FrontAddr)
}

// OnFrontDisConnected 前置断连消息
func (api *QMdAPI) OnFrontDisConnected(reason int) {
	api.Connected = false
	log.Printf("Front[%s] disconnected\n", api.FrontAddr)
}

// OnHeartBeatWarning 心跳失败消息
func (api *QMdAPI) OnHeartBeatWarning(time int) {
	log.Printf("Missing heartbeat in %d seconds\n", time)
}

// OnPackageStart 系列数据包开始消息
func (api *QMdAPI) OnPackageStart(topicID, sequenceNO int) {}

// OnPackageEnd 系列数据包结束消息
func (api *QMdAPI) OnPackageEnd(topicID, sequenceNO int) {}

// OnMultiHeartbeat 多播心跳消息
func (api *QMdAPI) OnMultiHeartbeat(currTime, multiCastIP string) {}

// OnStopMultiTopic 多播停止消息
func (api *QMdAPI) OnStopMultiTopic(topicID int) {}

// UDPMarketData UDP行情通知
func (api *QMdAPI) UDPMarketData(rtn *GoQdamFtdcDepthMarketDataField) {
	var ask, bid, last string

	if len(rtn.Asks) > 0 {
		ask = fmt.Sprintf("Ask[%d@%f]", rtn.Asks[0].Volume, rtn.Asks[0].Price)
	} else {
		ask = "Ask[]"
	}

	if len(rtn.Bids) > 0 {
		bid = fmt.Sprintf("Bid[%d@%f]", rtn.Bids[0].Volume, rtn.Bids[0].Price)
	} else {
		bid = "Bid[]"
	}

	if rtn.Volume > 0 {
		last = fmt.Sprintf("Last[%d@%f]", rtn.Volume, rtn.LastPrice)
	} else {
		last = "Last[]"
	}

	log.Printf("[%5s.%-6s] %s: %s, %s, %s\n", rtn.ExchangeID, rtn.InstrumentID, rtn.UpdateTime.Format("15:04:05.000"), ask, bid, last)
}

// OnRspError 错误应答消息
func (api *QMdAPI) OnRspError(err *GoQdamFtdcRspInfoField, reqID int, isLast bool) {
	log.Printf("Error[%d] occoured: %s", err.ErrorID, err.ErrorMsg)
}

// OnRspUserLogin 用户登录消息
func (api *QMdAPI) OnRspUserLogin(rsp *GoQdamFtdcRspUserLoginField, err *GoQdamFtdcRspInfoField, reqID int, isLast bool) {
	if err.ErrorID != 0 {
		log.Printf("User[%s] login failed: %s\n", rsp.UserID, err.ErrorMsg)
	} else {
		api.Logged = true
		log.Printf("User[%s] login success: %s@%v\n", rsp.UserID, rsp.TradingDay, rsp.LoginTime)
	}
}

// OnRspUserLogout 用户登出消息
func (api *QMdAPI) OnRspUserLogout(rsp *GoQdamFtdcRspUserLogoutField, err *GoQdamFtdcRspInfoField, reqID int, isLast bool) {
	if err.ErrorID != 0 {
		log.Fatalf("User[%s] logout failed: %s\n", rsp.UserID, err.ErrorMsg)
	} else {
		log.Printf("User[%s] logout success\n", rsp.UserID)
	}
}

// OnRtnDepthMarketData 深度行情通知
func (api *QMdAPI) OnRtnDepthMarketData(rtn *GoQdamFtdcDepthMarketDataField) {
	printDepthMarketData(rtn)
}

// OnRtnMultiDepthMarketData 多播行情通知
func (api *QMdAPI) OnRtnMultiDepthMarketData(rtn *GoQdamFtdcDepthMarketDataField) {
	printDepthMarketData(rtn)
}

// OnRspSubMarketData 行情订阅应答
func (api *QMdAPI) OnRspSubMarketData(rsp *GoQdamFtdcSpecificInstrumentField, err *GoQdamFtdcRspInfoField, reqID int, isLast bool) {
	if err.ErrorID != 0 {
		log.Printf("[%s] subscribe failed: %s\n", rsp.InstrumentID, err.ErrorMsg)
	}
}

// OnRspUnSubMarketData 行情退订应答
func (api *QMdAPI) OnRspUnSubMarketData(rsp *GoQdamFtdcSpecificInstrumentField, err *GoQdamFtdcRspInfoField, reqID int, isLast bool) {
	if err.ErrorID != 0 {
		log.Printf("[%s] unsubscribe failed: %s\n", rsp.InstrumentID, err.ErrorMsg)
	}
}

// OnRtnMBLMarketData 分价行情通知
func (api *QMdAPI) OnRtnMBLMarketData(rtn *GoQdamFtdcMBLMarketDataField) {
	log.Printf("[%s]: P[%f], V[%d]\n", rtn.InstrumentID, rtn.Price, rtn.Volume)
}

// OnRtnQmdInstrumentStatu 合约状态通知
func (api *QMdAPI) OnRtnQmdInstrumentStatu(rtn *GoQdamFtdcQmdInstrumentStateField) {
	log.Printf("[%s]: %X\n", rtn.InstrumentID, rtn.InstrumentStatus)
}

// OnRspSubscribeTopic 主题订阅应答
func (api *QMdAPI) OnRspSubscribeTopic(rsp *GoQdamFtdcDisseminationField, err *GoQdamFtdcRspInfoField, reqID int, isLast bool) {
	if err.ErrorID != 0 {
		log.Fatalf("Topic[%d] subscribe failed: %s\n", rsp.SequenceSeries, err.ErrorMsg)
	}
}

// OnRspQryTopic 主题查询应答
func (api *QMdAPI) OnRspQryTopic(rsp *GoQdamFtdcDisseminationField, err *GoQdamFtdcRspInfoField, reqID int, isLast bool) {
	if err.ErrorID == 0 {
		log.Printf("Available topic: %d\n", rsp.SequenceSeries)
	}
}

// OnRspQryMarketData 行情查询应答
func (api *QMdAPI) OnRspQryMarketData(rsp *GoQdamFtdcRspMarketDataField, err *GoQdamFtdcRspInfoField, reqID int, isLast bool) {
	if err.ErrorID == 0 {
		log.Printf("Available instrument: %s", rsp.InstrumentID)
	}
}

func printDepthMarketData(data *GoQdamFtdcDepthMarketDataField) {
	var ask, bid, last string

	if len(data.Asks) > 0 {
		ask = fmt.Sprintf("Ask[%d@%f]", data.Asks[0].Volume, data.Asks[0].Price)
	} else {
		ask = "Ask[]"
	}

	if len(data.Bids) > 0 {
		bid = fmt.Sprintf("Bid[%d@%f]", data.Bids[0].Volume, data.Bids[0].Price)
	} else {
		bid = "Bid[]"
	}

	if data.Volume > 0 {
		last = fmt.Sprintf("Last[%d@%f]", data.Volume, data.LastPrice)
	} else {
		last = "Last[]"
	}

	log.Printf(
		"[%5s.%-6s] %s: %s, %s, %s\n",
		data.ExchangeID, data.InstrumentID, data.UpdateTime.Format("15:04:05.000"),
		ask, bid, last)
}
