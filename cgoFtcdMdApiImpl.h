#ifndef CGOFTDCMDAPIIMPL_H
#define CGOFTDCMDAPIIMPL_H

#include "FtdcMdApiImpl.h"

/*
Adapter Functions:
function name with prefix "cgo" used to be registered for C callback & passthrough callback event data to functions with prefix "go";
function name with prefix "go" defined in go code file and transform C callback data structure to go structure;
*/

void cgoOnFrontConnected();
extern void goOnFrontConnected();

void cgoOnFrontDisconnected(int);
extern void goOnFrontDisconnected(int);

void cgoOnHeartBeatWarning(int);
extern void goOnHeartBeatWarning(int);

void cgoOnPackageStart(int, int);
extern void goOnPackageStart(int, int);

void cgoOnPackageEnd(int, int);
extern void goOnPackageEnd(int, int);

void cgoOnMultiHeartbeat(char *, char *);
extern void goOnMultiHeartbeat(char *, char *);

void cgoOnStopMultiTopic(int);
extern void goOnStopMultiTopic(int);

void cgoUDPMarketData(CQdamFtdcDepthMarketDataField*);
extern void goUDPMarketData(CQdamFtdcDepthMarketDataField *);

void cgoOnRspError(CQdamFtdcRspInfoField*, int, bool);
extern void goOnRspError(CQdamFtdcRspInfoField*, int, bool);

void cgoOnRspUserLogin(CQdamFtdcRspUserLoginField*, CQdamFtdcRspInfoField*, int, bool);
extern void goOnRspUserLogin(CQdamFtdcRspUserLoginField*, CQdamFtdcRspInfoField*, int, bool);

void cgoOnRspUserLogout(CQdamFtdcRspUserLogoutField*, CQdamFtdcRspInfoField*, int, bool);
extern void goOnRspUserLogout(CQdamFtdcRspUserLogoutField*, CQdamFtdcRspInfoField*, int, bool);

void cgoOnRtnDepthMarketData(CQdamFtdcDepthMarketDataField*);
extern void goOnRtnDepthMarketData(CQdamFtdcDepthMarketDataField*);

void cgoOnRtnMultiDepthMarketData(CQdamFtdcDepthMarketDataField*);
extern void goOnRtnMultiDepthMarketData(CQdamFtdcDepthMarketDataField*);

void cgoOnRspSubMarketData(CQdamFtdcSpecificInstrumentField*, CQdamFtdcRspInfoField*, int, bool);
extern void goOnRspSubMarketData(CQdamFtdcSpecificInstrumentField*, CQdamFtdcRspInfoField*, int, bool);

void cgoOnRspUnSubMarketData(CQdamFtdcSpecificInstrumentField*, CQdamFtdcRspInfoField*, int, bool);
extern void goOnRspUnSubMarketData(CQdamFtdcSpecificInstrumentField*, CQdamFtdcRspInfoField*, int, bool);

void cgoOnRspUnSubMarketData(CQdamFtdcSpecificInstrumentField*, CQdamFtdcRspInfoField*, int, bool);
extern void goOnRspUnSubMarketData(CQdamFtdcSpecificInstrumentField*, CQdamFtdcRspInfoField*, int, bool);

void cgoOnRtnMBLMarketData(CQdamFtdcMBLMarketDataField*);
extern void goOnRtnMBLMarketData(CQdamFtdcMBLMarketDataField*);

void cgoOnRtnQmdInstrumentStatu(CQdamFtdcQmdInstrumentStateField*);
extern void goOnRtnQmdInstrumentStatu(CQdamFtdcQmdInstrumentStateField*);

void cgoOnRspSubscribeTopic(CQdamFtdcDisseminationField*, CQdamFtdcRspInfoField*, int, bool);
extern void goOnRspSubscribeTopic(CQdamFtdcDisseminationField*, CQdamFtdcRspInfoField*, int, bool);

void cgoOnRspQryTopic(CQdamFtdcDisseminationField*, CQdamFtdcRspInfoField*, int, bool);
extern void goOnRspQryTopic(CQdamFtdcDisseminationField*, CQdamFtdcRspInfoField*, int, bool);

void cgoOnRspQryMarketData(CQdamFtdcRspMarketDataField*, CQdamFtdcRspInfoField*, int, bool);
extern void goOnRspQryMarketData(CQdamFtdcRspMarketDataField*, CQdamFtdcRspInfoField*, int, bool);
#endif