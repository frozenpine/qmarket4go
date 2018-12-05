#ifdef _DEBUG
#include <stdio.h>
#endif
#include <string.h>
#include "cgoFtcdMdApiImpl.h"

void cgoOnFrontConnected(int client) {
	#ifdef _DEBUG
	printf("OnFrontConnected callback in cgo.\n");
	#endif
	goOnFrontConnected(client);
}

void cgoOnFrontDisconnected(int client, int nReason) {
	#ifdef _DEBUG
	printf("OnFrontDisconnected callback in cgo.\n");
	#endif
	goOnFrontDisconnected(client, nReason);
}

void cgoOnHeartBeatWarning(int client, int nTimeLapse) {
	#ifdef _DEBUG
	printf("OnHeartBeatWarning callback in cgo.\n");
	#endif
	goOnHeartBeatWarning(client, nTimeLapse);
}

void cgoOnPackageStart(int client, int nTopicID, int nSequenceNo) {
	#ifdef _DEBUG
	printf("OnPackageStart callback in cgo.\n");
	#endif
	goOnPackageStart(client, nTopicID, nSequenceNo);
}

void cgoOnPackageEnd(int client, int nTopicID, int nSequenceNo) {
	#ifdef _DEBUG
	printf("OnPackageEnd callback in cgo.\n");
	#endif
	goOnPackageEnd(client, nTopicID, nSequenceNo);
}

void cgoOnMultiHeartbeat(int client, char *CurrTime,char *MultiCastIP) {
	#ifdef _DEBUG
	printf("OnMultiHeartbeat callback in cgo.\n");
	#endif
	goOnMultiHeartbeat(client, CurrTime, MultiCastIP);
}

void cgoOnStopMultiTopic(int client, int nTopicID) {
	#ifdef _DEBUG
	printf("OnStopMultiTopic callback in cgo.\n");
	#endif
	goOnStopMultiTopic(client, nTopicID);
}

void cgoUDPMarketData(int client, CQdamFtdcDepthMarketDataField *qmdata) {
	#ifdef _DEBUG
	printf("UDPMarketData callback in cgo.\n");
	#endif

	if (strcmp(qmdata->ExchangeID, "") == 0 || strcmp(qmdata->TradingDay, "") == 0) {
		return;
	}

	goUDPMarketData(client, qmdata);
}

void cgoOnRspError(int client, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	#ifdef _DEBUG
	printf("OnRspError callback in cgo.\n");
	#endif
	goOnRspError(client, pRspInfo, nRequestID, bIsLast);
}

void cgoOnRspUserLogin(int client, CQdamFtdcRspUserLoginField *pRspUserLogin, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	#ifdef _DEBUG
	printf("OnRspUserLogin callback in cgo.\n");
	#endif
	goOnRspUserLogin(client, pRspUserLogin, pRspInfo, nRequestID, bIsLast);
}

void cgoOnRspUserLogout(int client, CQdamFtdcRspUserLogoutField *pRspUserLogout, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	#ifdef _DEBUG
	printf("OnRspUserLogout callback in cgo.\n");
	#endif
	goOnRspUserLogout(client, pRspUserLogout, pRspInfo, nRequestID, bIsLast);
}

void cgoOnRtnDepthMarketData(int client, CQdamFtdcDepthMarketDataField* pDepthMarketData) {
	#ifdef _DEBUG
	printf("OnRtnDepthMarketData callback in cgo.\n");
	#endif

	if (strcmp(pDepthMarketData->ExchangeID, "") == 0 || strcmp(pDepthMarketData->TradingDay, "") == 0) {
		return;
	}
	
	goOnRtnDepthMarketData(client, pDepthMarketData);
}

void cgoOnRtnMultiDepthMarketData(int client, CQdamFtdcDepthMarketDataField* pDepthMarketData) {
	#ifdef _DEBUG
	printf("OnRtnMultiDepthMarketData callback in cgo.\n");
	#endif

	if (strcmp(pDepthMarketData->ExchangeID, "") == 0 || strcmp(pDepthMarketData->TradingDay, "") == 0) {
		return;
	}

	goOnRtnMultiDepthMarketData(client, pDepthMarketData);
}

void cgoOnRspSubMarketData(int client, CQdamFtdcSpecificInstrumentField *pSpecificInstrument, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	#ifdef _DEBUG
	printf("OnRspSubMarketData callback in cgo.\n");
	#endif
	goOnRspSubMarketData(client, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
}

void cgoOnRspUnSubMarketData(int client, CQdamFtdcSpecificInstrumentField *pSpecificInstrument, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	#ifdef _DEBUG
	printf("OnRspUnSubMarketData callback in cgo.\n");
	#endif
	goOnRspUnSubMarketData(client, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
}

void cgoOnRtnMBLMarketData(int client, CQdamFtdcMBLMarketDataField *pMBLMarketData) {
	#ifdef _DEBUG
	printf("OnRtnMBLMarketData callback in cgo.\n");
	#endif
	goOnRtnMBLMarketData(client, pMBLMarketData);
}

void cgoOnRtnQmdInstrumentStatu(int client, CQdamFtdcQmdInstrumentStateField *pQmdInstrumentState) {
	#ifdef _DEBUG
	printf("OnRtnQmdInstrumentStatu callback in cgo.\n");
	#endif
	goOnRtnQmdInstrumentStatu(client, pQmdInstrumentState);
}

void cgoOnRspSubscribeTopic(int client, CQdamFtdcDisseminationField *pDissemination, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	#ifdef _DEBUG
	printf("OnRspSubscribeTopic callback in cgo.\n");
	#endif
	goOnRspSubscribeTopic(client, pDissemination, pRspInfo, nRequestID, bIsLast);
}

void cgoOnRspQryTopic(int client, CQdamFtdcDisseminationField *pDissemination, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	#ifdef _DEBUG
	printf("OnRspQryTopic callback in cgo.\n");
	#endif
	goOnRspQryTopic(client, pDissemination, pRspInfo, nRequestID, bIsLast);
}

void cgoOnRspQryMarketData(int client, CQdamFtdcRspMarketDataField *pRspMarketData, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	#ifdef _DEBUG
	printf("OnRspQryMarketData callback in cgo.\n");
	#endif
	goOnRspQryMarketData(client, pRspMarketData, pRspInfo, nRequestID, bIsLast);
}