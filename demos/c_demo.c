#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

#include "FtdcMdApiImpl.h"

int clientID = 0;

void OnFrontConnected(int client) {
    printf("Front connected.\n");

    CQdamFtdcReqUserLoginField user;
    memset(&user, 0, sizeof(CQdamFtdcReqUserLoginField));

    strncpy(&user.UserID[0], "230855", sizeof(TQdamFtdcUserIDType)-1);
    strncpy(&user.BrokerID[0], "0001", sizeof(TQdamFtdcBrokerIDType)-1);
    strncpy(&user.Password[0], "230855", sizeof(TQdamFtdcPasswordType)-1);

    ReqUserLogin(clientID, &user, 0);
}

void OnRspUserLogin(int client, CQdamFtdcRspUserLoginField *pRspUserLogin, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    if (pRspInfo->ErrorID == 0) {
        printf("User[%s] login successfully: %s\n", pRspUserLogin->UserID, pRspInfo->ErrorMsg);
        
        char *instruments[2] = {"fu1901", "rb1901"};
        
        SubMarketData(clientID, (char **)&instruments[0], 2);
    } else {
        printf("%s\n", pRspInfo->ErrorMsg);
    }
}

void OnRtnDepthMarketData(int client, CQdamFtdcDepthMarketDataField* pDepthMarketData) {
    printf("[%s.%s]: Ask[%f], Bid[%f], L[%f]\n", pDepthMarketData->ExchangeID, pDepthMarketData->InstrumentID, pDepthMarketData->AskPrice1, pDepthMarketData->BidPrice1, pDepthMarketData->LastPrice);
}

int main() {
    mkdir("flow");
    
    clientID = InitApi("./flow/");

    SetCallbackFunOnFrontConnected(clientID, &OnFrontConnected);
    SetCallbackFunOnRspUserLogin(clientID, &OnRspUserLogin);
    SetCallbackFunOnRtnDepthMarketData(clientID, &OnRtnDepthMarketData);

    RegisterFront(clientID, "tcp://122.144.129.233:30027");

    Init(clientID);

    while(true) {
        nanosleep((const struct timespec[]){{0, 1000000000L}}, NULL);
    }
}