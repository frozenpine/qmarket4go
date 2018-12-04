package qmarket4go

/*
#cgo CFLAGS: -I${SRCDIR} -fPIC
#cgo LDFLAGS: -L${SRCDIR} -lcqdammdapi

#include <stdlib.h>
#include <string.h>

#include "cgoFtcdMdApiImpl.h"
*/
import "C"
import (
	"fmt"
	"log"
	"strconv"
	"sync"
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

	now := time.Now()
	updateTime, _ := time.Parse("2006-01-02 03:04:05", fmt.Sprintf("%d-%d-%d %s", now.Year(), now.Month(), now.Day(), C.GoString(&qmdata.UpdateTime[0])))
	data.UpdateTime = time.Unix(updateTime.Unix(), int64(int(qmdata.UpdateMillisec)*1000000))

	data.ExchangeID = C.GoString(&qmdata.ExchangeID[0])
	data.VolumeAskLot = int(qmdata.VolumeAskLot)
	data.VolumeBidLot = int(qmdata.VolumeBidLot)
	data.InstrumentStatus = byte(qmdata.InstrumentStatus)

	{
		if qmdata.AskVolume1 != 0 {
			data.Asks = append(data.Asks, priceItem{Price: float64(qmdata.AskPrice1), Volume: int(qmdata.AskVolume1)})
		}
		if qmdata.AskVolume2 != 0 {
			data.Asks = append(data.Asks, priceItem{Price: float64(qmdata.AskPrice2), Volume: int(qmdata.AskVolume2)})
		}
		if qmdata.AskVolume3 != 0 {
			data.Asks = append(data.Asks, priceItem{Price: float64(qmdata.AskPrice3), Volume: int(qmdata.AskVolume3)})
		}
		if qmdata.AskVolume4 != 0 {
			data.Asks = append(data.Asks, priceItem{Price: float64(qmdata.AskPrice4), Volume: int(qmdata.AskVolume4)})
		}
		if qmdata.AskVolume5 != 0 {
			data.Asks = append(data.Asks, priceItem{Price: float64(qmdata.AskPrice5), Volume: int(qmdata.AskVolume5)})
		}
		if qmdata.AskVolume6 != 0 {
			data.Asks = append(data.Asks, priceItem{Price: float64(qmdata.AskPrice6), Volume: int(qmdata.AskVolume6)})
		}
		if qmdata.AskVolume7 != 0 {
			data.Asks = append(data.Asks, priceItem{Price: float64(qmdata.AskPrice7), Volume: int(qmdata.AskVolume7)})
		}
		if qmdata.AskVolume8 != 0 {
			data.Asks = append(data.Asks, priceItem{Price: float64(qmdata.AskPrice8), Volume: int(qmdata.AskVolume8)})
		}
		if qmdata.AskVolume9 != 0 {
			data.Asks = append(data.Asks, priceItem{Price: float64(qmdata.AskPrice9), Volume: int(qmdata.AskVolume9)})
		}
		if qmdata.AskVolume10 != 0 {
			data.Asks = append(data.Asks, priceItem{Price: float64(qmdata.AskPrice10), Volume: int(qmdata.AskVolume10)})
		}

		if qmdata.BidVolume1 != 0 {
			data.Bids = append(data.Bids, priceItem{Price: float64(qmdata.BidPrice1), Volume: int(qmdata.BidVolume1)})
		}
		if qmdata.BidVolume2 != 0 {
			data.Bids = append(data.Bids, priceItem{Price: float64(qmdata.BidPrice2), Volume: int(qmdata.BidVolume2)})
		}
		if qmdata.BidVolume3 != 0 {
			data.Bids = append(data.Bids, priceItem{Price: float64(qmdata.BidPrice3), Volume: int(qmdata.BidVolume3)})
		}
		if qmdata.BidVolume4 != 0 {
			data.Bids = append(data.Bids, priceItem{Price: float64(qmdata.BidPrice4), Volume: int(qmdata.BidVolume4)})
		}
		if qmdata.BidVolume5 != 0 {
			data.Bids = append(data.Bids, priceItem{Price: float64(qmdata.BidPrice5), Volume: int(qmdata.BidVolume5)})
		}
		if qmdata.BidVolume6 != 0 {
			data.Bids = append(data.Bids, priceItem{Price: float64(qmdata.BidPrice6), Volume: int(qmdata.BidVolume6)})
		}
		if qmdata.BidVolume7 != 0 {
			data.Bids = append(data.Bids, priceItem{Price: float64(qmdata.BidPrice7), Volume: int(qmdata.BidVolume7)})
		}
		if qmdata.BidVolume8 != 0 {
			data.Bids = append(data.Bids, priceItem{Price: float64(qmdata.BidPrice8), Volume: int(qmdata.BidVolume8)})
		}
		if qmdata.BidVolume9 != 0 {
			data.Bids = append(data.Bids, priceItem{Price: float64(qmdata.BidPrice9), Volume: int(qmdata.BidVolume9)})
		}
		if qmdata.BidVolume10 != 0 {
			data.Bids = append(data.Bids, priceItem{Price: float64(qmdata.BidPrice10), Volume: int(qmdata.BidVolume10)})
		}
	}

	return &data
}

func convertRspInfo(pRspInfo *C.CQdamFtdcRspInfoField) *GoQdamFtdcRspInfoField {
	data := GoQdamFtdcRspInfoField{}

	data.ErrorID = int(pRspInfo.ErrorID)
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

	return &data
}

func convertBLMarketData(pMBLMarketData *C.CQdamFtdcMBLMarketDataField) *GoQdamFtdcMBLMarketDataField {
	data := GoQdamFtdcMBLMarketDataField{}

	return &data
}

func convertQmdInstrumentState(pQmdInstrumentState *C.CQdamFtdcQmdInstrumentStateField) *GoQdamFtdcQmdInstrumentStateField {
	data := GoQdamFtdcQmdInstrumentStateField{}

	return &data
}

func convertDissemination(pDissemination *C.CQdamFtdcDisseminationField) *GoQdamFtdcDisseminationField {
	data := GoQdamFtdcDisseminationField{}

	return &data
}

func convertRspMarketData(pRspMarketData *C.CQdamFtdcRspMarketDataField) *GoQdamFtdcRspMarketDataField {
	data := GoQdamFtdcRspMarketDataField{}

	return &data
}

// QMdAPI 行情API数据封装
type QMdAPI struct {
	clientID   int
	FrontAddr  string
	FensAddr   string
	Connected  bool
	UserInfo   GoQdamFtdcReqUserLoginField
	Logged     bool
	reqID      int64
	reqIDMutex sync.Mutex
}

var callback QMdAPICallback

//export goOnFrontConnected
func goOnFrontConnected() {
	if callback != nil {
		callback.OnFrontConnected()
	}
}

//export goOnFrontDisconnected
func goOnFrontDisconnected(nReason C.int) {
	if callback != nil {
		callback.OnFrontDisConnected(int(nReason))
	}
}

//export goOnHeartBeatWarning
func goOnHeartBeatWarning(nTimeLapse C.int) {
	if callback != nil {
		callback.OnHeartBeatWarning(int(nTimeLapse))
	}
}

//export goOnPackageStart
func goOnPackageStart(nTopicID C.int, nSequenceNo C.int) {
	if callback != nil {
		callback.OnPackageStart(int(nTopicID), int(nSequenceNo))
	}
}

//export goOnPackageEnd
func goOnPackageEnd(nTopicID C.int, nSequenceNo C.int) {
	if callback != nil {
		callback.OnPackageEnd(int(nTopicID), int(nSequenceNo))
	}
}

//export goOnMultiHeartbeat
func goOnMultiHeartbeat(CurrTime *C.char, MultiCastIP *C.char) {
	if callback != nil {
		callback.OnMultiHeartbeat(C.GoString(CurrTime), C.GoString(MultiCastIP))
	}
}

//export goOnStopMultiTopic
func goOnStopMultiTopic(nTopicID C.int) {
	if callback != nil {
		callback.OnStopMultiTopic(int(nTopicID))
	}
}

//export goUDPMarketData
func goUDPMarketData(qmdata *C.CQdamFtdcDepthMarketDataField) {
	if callback != nil {
		callback.UDPMarketData(convertDepthMarketData(qmdata))
	}
}

//export goOnRspError
func goOnRspError(pRspInfo *C.CQdamFtdcRspInfoField, nRequestID C.int, bIsLast C.bool) {
	if callback != nil {
		callback.OnRspError(convertRspInfo(pRspInfo), int(nRequestID), bool(bIsLast))
	}
}

//export goOnRspUserLogin
func goOnRspUserLogin(pRspUserLogin *C.CQdamFtdcRspUserLoginField, pRspInfo *C.CQdamFtdcRspInfoField, nRequestID C.int, bIsLast C.bool) {
	if callback != nil {
		callback.OnRspUserLogin(convertRspUserLogin(pRspUserLogin), convertRspInfo(pRspInfo), int(nRequestID), bool(bIsLast))
	}
}

//export goOnRspUserLogout
func goOnRspUserLogout(pRspUserLogout *C.CQdamFtdcRspUserLogoutField, pRspInfo *C.CQdamFtdcRspInfoField, nRequestID C.int, bIsLast C.bool) {
	if callback != nil {
		callback.OnRspUserLogout(convertRspUserLogout(pRspUserLogout), convertRspInfo(pRspInfo), int(nRequestID), bool(bIsLast))
	}
}

//export goOnRtnDepthMarketData
func goOnRtnDepthMarketData(pDepthMarketData *C.CQdamFtdcDepthMarketDataField) {
	if callback != nil {
		callback.OnRtnDepthMarketData(convertDepthMarketData(pDepthMarketData))
	}
}

//export goOnRtnMultiDepthMarketData
func goOnRtnMultiDepthMarketData(pDepthMarketData *C.CQdamFtdcDepthMarketDataField) {
	if callback != nil {
		callback.OnRtnMultiDepthMarketData(convertDepthMarketData(pDepthMarketData))
	}
}

//export goOnRspSubMarketData
func goOnRspSubMarketData(pSpecificInstrument *C.CQdamFtdcSpecificInstrumentField, pRspInfo *C.CQdamFtdcRspInfoField, nRequestID C.int, bIsLast C.bool) {
	if callback != nil {
		callback.OnRspSubMarketData(convertSpecificInstrument(pSpecificInstrument), convertRspInfo(pRspInfo), int(nRequestID), bool(bIsLast))
	}
}

//export goOnRspUnSubMarketData
func goOnRspUnSubMarketData(pSpecificInstrument *C.CQdamFtdcSpecificInstrumentField, pRspInfo *C.CQdamFtdcRspInfoField, nRequestID C.int, bIsLast C.bool) {
	if callback != nil {
		callback.OnRspUnSubMarketData(convertSpecificInstrument(pSpecificInstrument), convertRspInfo(pRspInfo), int(nRequestID), bool(bIsLast))
	}
}

//export goOnRtnMBLMarketData
func goOnRtnMBLMarketData(pMBLMarketData *C.CQdamFtdcMBLMarketDataField) {
	if callback != nil {
		callback.OnRtnMBLMarketData(convertBLMarketData(pMBLMarketData))
	}
}

//export goOnRtnQmdInstrumentStatu
func goOnRtnQmdInstrumentStatu(pQmdInstrumentState *C.CQdamFtdcQmdInstrumentStateField) {
	if callback != nil {
		callback.OnRtnQmdInstrumentStatu(convertQmdInstrumentState(pQmdInstrumentState))
	}
}

//export goOnRspSubscribeTopic
func goOnRspSubscribeTopic(pDissemination *C.CQdamFtdcDisseminationField, pRspInfo *C.CQdamFtdcRspInfoField, nRequestID C.int, bIsLast C.bool) {
	if callback != nil {
		callback.OnRspSubscribeTopic(convertDissemination(pDissemination), convertRspInfo(pRspInfo), int(nRequestID), bool(bIsLast))
	}
}

//export goOnRspQryTopic
func goOnRspQryTopic(pDissemination *C.CQdamFtdcDisseminationField, pRspInfo *C.CQdamFtdcRspInfoField, nRequestID C.int, bIsLast C.bool) {
	if callback != nil {
		callback.OnRspQryTopic(convertDissemination(pDissemination), convertRspInfo(pRspInfo), int(nRequestID), bool(bIsLast))
	}
}

//export goOnRspQryMarketData
func goOnRspQryMarketData(pRspMarketData *C.CQdamFtdcRspMarketDataField, pRspInfo *C.CQdamFtdcRspInfoField, nRequestID C.int, bIsLast C.bool) {
	if callback != nil {
		callback.OnRspQryMarketData(convertRspMarketData(pRspMarketData), convertRspInfo(pRspInfo), int(nRequestID), bool(bIsLast))
	}
}

// InitAPI 初始化行情API
func (api *QMdAPI) InitAPI(flowPath string) {
	clientID := int(C.InitApi(C.CString(flowPath)))
	api.clientID = clientID
}

// RegisterCallback 注册用户回调接口
func (api *QMdAPI) RegisterCallback(cb QMdAPICallback) {
	if api.clientID == 0 {
		panic("Please call function InitApi first.")
	}

	callback = cb

	C.SetCallbackFunOnFrontConnected(C.int(api.clientID), (C.FunOnFrontConnected)(unsafe.Pointer(C.cgoOnFrontConnected)))
	C.SetCallbackFunOnFrontDisconnected(C.int(api.clientID), (C.FunOnFrontDisconnected)(unsafe.Pointer(C.cgoOnFrontDisconnected)))

	C.SetCallbackFunOnHeartBeatWarning(C.int(api.clientID), (C.FunOnHeartBeatWarning)(unsafe.Pointer(C.cgoOnHeartBeatWarning)))
	C.SetCallbackFunOnPackageStart(C.int(api.clientID), (C.FunOnPackageStart)(unsafe.Pointer(C.cgoOnPackageStart)))
	C.SetCallbackFunOnPackageEnd(C.int(api.clientID), (C.FunOnPackageStart)(unsafe.Pointer(C.cgoOnPackageEnd)))

	C.SetCallbackFunUdpMarketData(C.int(api.clientID), (C.FunUdpMarketData)(unsafe.Pointer(C.cgoUDPMarketData)))

	C.SetCallbackFunOnRspError(C.int(api.clientID), (C.FunOnRspError)(unsafe.Pointer(C.cgoOnRspError)))

	C.SetCallbackFunOnRspUserLogin(C.int(api.clientID), (C.FunOnRspUserLogin)(unsafe.Pointer(C.cgoOnRspUserLogin)))
	C.SetCallbackFunOnRspUserLogout(C.int(api.clientID), (C.FunOnRspUserLogout)(unsafe.Pointer(C.cgoOnRspUserLogout)))

	C.SetCallbackFunOnRtnDepthMarketData(C.int(api.clientID), (C.FunOnRtnDepthMarketData)(unsafe.Pointer(C.cgoOnRtnDepthMarketData)))
	C.SetCallbackFunOnRtnMultiDepthMarketData(C.int(api.clientID), (C.FunOnRtnMultiDepthMarketData)(unsafe.Pointer(C.cgoOnRtnMultiDepthMarketData)))

	C.SetCallbackFunOnRspSubMarketData(C.int(api.clientID), (C.FunOnRspSubMarketData)(unsafe.Pointer(C.cgoOnRspSubMarketData)))
	C.SetCallbackFunOnRspUnSubMarketData(C.int(api.clientID), (C.FunOnRspUnSubMarketData)(unsafe.Pointer(C.cgoOnRspUnSubMarketData)))

	C.SetCallbackFunOnRtnMBLMarketData(C.int(api.clientID), (C.FunOnRtnMBLMarketData)(unsafe.Pointer(C.cgoOnRtnMBLMarketData)))

	C.SetCallbackFunOnRtnQmdInstrumentStatu(C.int(api.clientID), (C.FunOnRtnQmdInstrumentStatu)(unsafe.Pointer(C.cgoOnRtnQmdInstrumentStatu)))

	C.SetCallbackFunOnRspSubscribeTopic(C.int(api.clientID), (C.FunOnRspSubscribeTopic)(unsafe.Pointer(C.cgoOnRspSubscribeTopic)))
	C.SetCallbackFunOnRspQryTopic(C.int(api.clientID), (C.FunOnRspQryTopic)(unsafe.Pointer(C.cgoOnRspQryTopic)))
	C.SetCallbackFunOnRspQryMarketData(C.int(api.clientID), (C.FunOnRspQryMarketData)(unsafe.Pointer(C.cgoOnRspQryMarketData)))
}

// RegisterFront API注册前置地址
func (api *QMdAPI) RegisterFront(frontAddr string) {
	api.FrontAddr = frontAddr
	C.RegisterFront(C.int(api.clientID), C.CString(frontAddr))
}

// RegisterNameServer 注册Fens地址
func (api *QMdAPI) RegisterNameServer(fensAddr string) {
	api.FensAddr = fensAddr
	C.RegisterNameServer(C.int(api.clientID), C.CString(fensAddr))
}

// SubscribeMarketDataTopic 订阅行情Topic
func (api *QMdAPI) SubscribeMarketDataTopic(topicID, resumeType int) {
	C.SubscribeMarketDataTopic(C.int(api.clientID), C.int(topicID), C.QDAM_TE_RESUME_TYPE(resumeType))
}

// Init 初始化行情API连接
func (api *QMdAPI) Init() {
	C.Init(C.int(api.clientID))
}

// Release 释放行情API资源
func (api *QMdAPI) Release() {
	C.Release(C.int(api.clientID))
}

func (api *QMdAPI) nextReqID() int64 {
	api.reqIDMutex.Lock()
	defer api.reqIDMutex.Unlock()

	currReqID := api.reqID
	api.reqID++

	return currReqID
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

	rtn := C.ReqUserLogin(C.int(api.clientID), &loginReq, C.int(api.nextReqID()))

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

	C.SubMarketData(C.int(api.clientID), &cStrings[0], C.int(count))
}

// UnSubMarketData 取消合约行情订阅
func (api *QMdAPI) UnSubMarketData(instruments ...string) {
	count := len(instruments)
	cStrings := make([]*C.char, count)

	for idx := 0; idx < count; idx++ {
		cStrings[idx] = C.CString(instruments[idx])
	}

	C.UnSubMarketData(C.int(api.clientID), &cStrings[0], C.int(count))
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
	log.Printf("[%s] %X: Ask[%f], Bid[%f], Last[%f]\n", rtn.InstrumentID, rtn.InstrumentStatus, rtn.Asks[0].Price, rtn.Bids[0].Price, rtn.LastPrice)
}

// OnRspError 错误应答消息
func (api *QMdAPI) OnRspError(err *GoQdamFtdcRspInfoField, reqID int, isLast bool) {}

// OnRspUserLogin 用户登录消息
func (api *QMdAPI) OnRspUserLogin(rsp *GoQdamFtdcRspUserLoginField, err *GoQdamFtdcRspInfoField, reqID int, isLast bool) {
	if err.ErrorID != 0 {
		log.Fatalf("User[%s] login failed: %s\n", rsp.UserID, err.ErrorMsg)
	} else {
		api.Logged = true
		log.Printf("User[%s] login success\n", rsp.UserID)
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
	log.Printf("[%s] %X: Ask[%f], Bid[%f], Last[%f]\n", rtn.InstrumentID, rtn.InstrumentStatus, rtn.Asks[0].Price, rtn.Bids[0].Price, rtn.LastPrice)
}

// OnRtnMultiDepthMarketData 多播行情通知
func (api *QMdAPI) OnRtnMultiDepthMarketData(rtn *GoQdamFtdcDepthMarketDataField) {
	log.Printf("[%s] %X: Ask[%f], Bid[%f], Last[%f]\n", rtn.InstrumentID, rtn.InstrumentStatus, rtn.Asks[0].Price, rtn.Bids[0].Price, rtn.LastPrice)
}

// OnRspSubMarketData 行情订阅应答
func (api *QMdAPI) OnRspSubMarketData(rsp *GoQdamFtdcSpecificInstrumentField, err *GoQdamFtdcRspInfoField, reqID int, isLast bool) {
	if err.ErrorID != 0 {
		log.Fatalf("[%s] subscribe failed: %s\n", rsp.InstrumentID, err.ErrorMsg)
	} else {
		log.Printf("[%s] subscribed successfully\n", rsp.InstrumentID)
	}
}

// OnRspUnSubMarketData 行情退订应答
func (api *QMdAPI) OnRspUnSubMarketData(rsp *GoQdamFtdcSpecificInstrumentField, err *GoQdamFtdcRspInfoField, reqID int, isLast bool) {
	if err.ErrorID != 0 {
		log.Fatalf("[%s] unsubscribe failed: %s\n", rsp.InstrumentID, err.ErrorMsg)
	} else {
		log.Printf("[%s] unsubscribed successfully\n", rsp.InstrumentID)
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
	} else {
		log.Printf("Topic[%d] subscribed successfully\n", rsp.SequenceSeries)
	}
}

// OnRspQryTopic 主题查询应答
func (api *QMdAPI) OnRspQryTopic(rsp *GoQdamFtdcDisseminationField, err *GoQdamFtdcRspInfoField, reqID int, isLast bool) {
	if err.ErrorID != 0 {
		log.Fatalf("Query topic failed: %s\n", err.ErrorMsg)
	} else {
		log.Printf("Available topic: %d\n", rsp.SequenceSeries)
	}
}

// OnRspQryMarketData 行情查询应答
func (api *QMdAPI) OnRspQryMarketData(rsp *GoQdamFtdcRspMarketDataField, err *GoQdamFtdcRspInfoField, reqID int, isLast bool) {
	if err.ErrorID != 0 {
		log.Fatalf("Query marketdata failed: %s", err.ErrorMsg)
	} else {
		log.Printf("Available instrument: %s", rsp.InstrumentID)
	}
}
