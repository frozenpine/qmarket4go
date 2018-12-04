#ifdef _DEBUG
#include <stdio.h>
#endif
#include "cgoFtcdMdApiImpl.h"

void cgoOnFrontConnected() {
	#ifdef _DEBUG
	printf("OnFrontConnected callback in cgo.\n");
	#endif
	goOnFrontConnected();
}

void cgoOnFrontDisconnected(int nReason) {
	#ifdef _DEBUG
	printf("OnFrontDisconnected callback in cgo.\n");
	#endif
	goOnFrontDisconnected(nReason);
}

void cgoOnHeartBeatWarning(int nTimeLapse) {
	#ifdef _DEBUG
	printf("OnHeartBeatWarning callback in cgo.\n");
	#endif
	goOnHeartBeatWarning(nTimeLapse);
}

void cgoOnPackageStart(int nTopicID, int nSequenceNo) {
	#ifdef _DEBUG
	printf("OnPackageStart callback in cgo.\n");
	#endif
	goOnPackageStart(nTopicID, nSequenceNo);
}

void cgoOnPackageEnd(int nTopicID, int nSequenceNo) {
	#ifdef _DEBUG
	printf("OnPackageEnd callback in cgo.\n");
	#endif
	goOnPackageEnd(nTopicID, nSequenceNo);
}

void cgoOnMultiHeartbeat(char *CurrTime,char *MultiCastIP) {
	#ifdef _DEBUG
	printf("OnMultiHeartbeat callback in cgo.\n");
	#endif
	goOnMultiHeartbeat(CurrTime, MultiCastIP);
}

void cgoOnStopMultiTopic(int nTopicID) {
	#ifdef _DEBUG
	printf("OnStopMultiTopic callback in cgo.\n");
	#endif
	goOnStopMultiTopic(nTopicID);
}

void cgoUDPMarketData(CQdamFtdcDepthMarketDataField *qmdata) {
	#ifdef _DEBUG
	printf("UDPMarketData callback in cgo.\n");
	#endif
	goUDPMarketData(qmdata);
}

void cgoOnRspError(CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	#ifdef _DEBUG
	printf("OnRspError callback in cgo.\n");
	#endif
	goOnRspError(pRspInfo, nRequestID, bIsLast);
}

void cgoOnRspUserLogin(CQdamFtdcRspUserLoginField *pRspUserLogin, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	#ifdef _DEBUG
	printf("OnRspUserLogin callback in cgo.\n");
	#endif
	goOnRspUserLogin(pRspUserLogin, pRspInfo, nRequestID, bIsLast);
}

void cgoOnRspUserLogout(CQdamFtdcRspUserLogoutField *pRspUserLogout, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	#ifdef _DEBUG
	printf("OnRspUserLogout callback in cgo.\n");
	#endif
	goOnRspUserLogout(pRspUserLogout, pRspInfo, nRequestID, bIsLast);
}

void cgoOnRtnDepthMarketData(CQdamFtdcDepthMarketDataField* pDepthMarketData) {
	#ifdef _DEBUG
	printf("OnRtnDepthMarketData callback in cgo.\n");
	#endif
	goOnRtnDepthMarketData(pDepthMarketData);
}

void cgoOnRtnMultiDepthMarketData(CQdamFtdcDepthMarketDataField* pDepthMarketData) {
	#ifdef _DEBUG
	printf("OnRtnMultiDepthMarketData callback in cgo.\n");
	#endif
	goOnRtnMultiDepthMarketData(pDepthMarketData);
}

void cgoOnRspSubMarketData(CQdamFtdcSpecificInstrumentField *pSpecificInstrument, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	#ifdef _DEBUG
	printf("OnRspSubMarketData callback in cgo.\n");
	#endif
	goOnRspSubMarketData(pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
}

void cgoOnRspUnSubMarketData(CQdamFtdcSpecificInstrumentField *pSpecificInstrument, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	#ifdef _DEBUG
	printf("OnRspUnSubMarketData callback in cgo.\n");
	#endif
	goOnRspUnSubMarketData(pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
}

void cgoOnRtnMBLMarketData(CQdamFtdcMBLMarketDataField *pMBLMarketData) {
	#ifdef _DEBUG
	printf("OnRtnMBLMarketData callback in cgo.\n");
	#endif
	goOnRtnMBLMarketData(pMBLMarketData);
}

void cgoOnRtnQmdInstrumentStatu(CQdamFtdcQmdInstrumentStateField *pQmdInstrumentState) {
	#ifdef _DEBUG
	printf("OnRtnQmdInstrumentStatu callback in cgo.\n");
	#endif
	goOnRtnQmdInstrumentStatu(pQmdInstrumentState);
}

void cgoOnRspSubscribeTopic(CQdamFtdcDisseminationField *pDissemination, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	#ifdef _DEBUG
	printf("OnRspSubscribeTopic callback in cgo.\n");
	#endif
	goOnRspSubscribeTopic(pDissemination, pRspInfo, nRequestID, bIsLast);
}

void cgoOnRspQryTopic(CQdamFtdcDisseminationField *pDissemination, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	#ifdef _DEBUG
	printf("OnRspQryTopic callback in cgo.\n");
	#endif
	goOnRspQryTopic(pDissemination, pRspInfo, nRequestID, bIsLast);
}

void cgoOnRspQryMarketData(CQdamFtdcRspMarketDataField *pRspMarketData, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	#ifdef _DEBUG
	printf("OnRspQryMarketData callback in cgo.\n");
	#endif
	goOnRspQryMarketData(pRspMarketData, pRspInfo, nRequestID, bIsLast);
}