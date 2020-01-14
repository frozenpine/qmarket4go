#ifndef CGOFTDCMDAPIIMPL_H
#define CGOFTDCMDAPIIMPL_H

#include "FtdcMdApiImpl.h"

/*
Adapter Functions:
function name with prefix "cgo" used to be registered for C callback & passthrough callback event data to functions with prefix "go";
function name with prefix "go" defined in go code file and transform C callback data structure to go structure;
*/

char* strnlast(char*, int);

int isLevel2();

// Instruments that should be ignored will return true
bool insFilter(CQdamFtdcDepthMarketDataField *);

void cgoOnFrontConnected(int);
extern void goOnFrontConnected(int);

void cgoOnFrontDisconnected(int, int);
extern void goOnFrontDisconnected(int, int);

void cgoOnHeartBeatWarning(int, int);
extern void goOnHeartBeatWarning(int, int);

void cgoOnPackageStart(int, int, int);
extern void goOnPackageStart(int, int, int);

void cgoOnPackageEnd(int, int, int);
extern void goOnPackageEnd(int, int, int);

void cgoOnMultiHeartbeat(int, char *, char *);
extern void goOnMultiHeartbeat(int, char *, char *);

void cgoOnStopMultiTopic(int, int);
extern void goOnStopMultiTopic(int, int);

void cgoUDPMarketData(int, CQdamFtdcDepthMarketDataField*);
extern void goUDPMarketData(int, CQdamFtdcDepthMarketDataField *);

void cgoOnRspError(int, CQdamFtdcRspInfoField*, int, bool);
extern void goOnRspError(int, CQdamFtdcRspInfoField*, int, bool);

void cgoOnRspUserLogin(int, CQdamFtdcRspUserLoginField*, CQdamFtdcRspInfoField*, int, bool);
extern void goOnRspUserLogin(int, CQdamFtdcRspUserLoginField*, CQdamFtdcRspInfoField*, int, bool);

void cgoOnRspUserLogout(int, CQdamFtdcRspUserLogoutField*, CQdamFtdcRspInfoField*, int, bool);
extern void goOnRspUserLogout(int, CQdamFtdcRspUserLogoutField*, CQdamFtdcRspInfoField*, int, bool);

void cgoOnRtnDepthMarketData(int, CQdamFtdcDepthMarketDataField*);
extern void goOnRtnDepthMarketData(int, CQdamFtdcDepthMarketDataField*);

void cgoOnRtnMultiDepthMarketData(int, CQdamFtdcDepthMarketDataField*);
extern void goOnRtnMultiDepthMarketData(int, CQdamFtdcDepthMarketDataField*);

void cgoOnRspSubMarketData(int, CQdamFtdcSpecificInstrumentField*, CQdamFtdcRspInfoField*, int, bool);
extern void goOnRspSubMarketData(int, CQdamFtdcSpecificInstrumentField*, CQdamFtdcRspInfoField*, int, bool);

void cgoOnRspUnSubMarketData(int, CQdamFtdcSpecificInstrumentField*, CQdamFtdcRspInfoField*, int, bool);
extern void goOnRspUnSubMarketData(int, CQdamFtdcSpecificInstrumentField*, CQdamFtdcRspInfoField*, int, bool);

void cgoOnRspUnSubMarketData(int, CQdamFtdcSpecificInstrumentField*, CQdamFtdcRspInfoField*, int, bool);
extern void goOnRspUnSubMarketData(int, CQdamFtdcSpecificInstrumentField*, CQdamFtdcRspInfoField*, int, bool);

void cgoOnRtnMBLMarketData(int, CQdamFtdcMBLMarketDataField*);
extern void goOnRtnMBLMarketData(int, CQdamFtdcMBLMarketDataField*);

void cgoOnRtnQmdInstrumentStatu(int, CQdamFtdcQmdInstrumentStateField*);
extern void goOnRtnQmdInstrumentStatu(int, CQdamFtdcQmdInstrumentStateField*);

void cgoOnRspSubscribeTopic(int, CQdamFtdcDisseminationField*, CQdamFtdcRspInfoField*, int, bool);
extern void goOnRspSubscribeTopic(int, CQdamFtdcDisseminationField*, CQdamFtdcRspInfoField*, int, bool);

void cgoOnRspQryTopic(int, CQdamFtdcDisseminationField*, CQdamFtdcRspInfoField*, int, bool);
extern void goOnRspQryTopic(int, CQdamFtdcDisseminationField*, CQdamFtdcRspInfoField*, int, bool);

void cgoOnRspQryMarketData(int, CQdamFtdcRspMarketDataField*, CQdamFtdcRspInfoField*, int, bool);
extern void goOnRspQryMarketData(int, CQdamFtdcRspMarketDataField*, CQdamFtdcRspInfoField*, int, bool);
#endif