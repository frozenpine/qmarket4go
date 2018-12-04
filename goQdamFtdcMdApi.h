#include "QdamFtdcMdApi.h"

class MdApiWrapper: public CQdamFtdcMduserSpi
{
private:
    CQdamFtdcMduserApi *api;
public:
    MdApiWrapper();
    ~MdApiWrapper();

    virtual void OnFrontConnected();

    virtual void OnFrontDisconnected(int nReason);

    virtual void OnHeartBeatWarning(int nTimeLapse);

    virtual void OnPackageStart(int nTopicID, int nSequenceNo);

    virtual void OnPackageEnd(int nTopicID, int nSequenceNo);

    virtual void  OnMultiHeartbeat(char *CurrTime,char *MultiCastIP);

    virtual void UdpMarketData(CQdamFtdcDepthMarketDataField *qmdata);

    virtual void OnRspError(CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    virtual void OnRspUserLogin(CQdamFtdcRspUserLoginField *pRspUserLogin, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    virtual void OnRspUserLogout(CQdamFtdcRspUserLogoutField *pRspUserLogout, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    virtual void OnRtnDepthMarketData(CQdamFtdcDepthMarketDataField *pDepthMarketData);

    virtual void OnRtnMultiDepthMarketData(CQdamFtdcDepthMarketDataField *pDepthMarketData);

    virtual void OnRspSubMarketData(CQdamFtdcSpecificInstrumentField *pSpecificInstrument, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    virtual void OnRspUnSubMarketData(CQdamFtdcSpecificInstrumentField *pSpecificInstrument, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    virtual void OnRtnMBLMarketData(CQdamFtdcMBLMarketDataField *pMBLMarketData);

    virtual void OnRtnQmdInstrumentStatu(CQdamFtdcQmdInstrumentStateField *pQmdInstrumentState);

    virtual void OnRspSubscribeTopic(CQdamFtdcDisseminationField *pDissemination, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    virtual void OnRspQryTopic(CQdamFtdcDisseminationField *pDissemination, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    virtual void OnRspQryMarketData(CQdamFtdcRspMarketDataField *pRspMarketData, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    void CreateFtdcMduserApi(const char *pszFlowPath = "");

    char* GetVersion();

    void Release();

    void SetMultiCast(bool bMultiCast=false);

    void RegTopicMultiAddr(char *pMultiAddr);

    void Init();

    int Join();

    char* GetTradingDay();

    void RegisterFront(char *pszFrontAddress);

    void RegisterNameServer(char *pszNsAddress);

    void SubscribeMarketDataTopic(int nTopicID, QDAM_TE_RESUME_TYPE nResumeType);

    int SubMarketData(char *ppInstrumentID[], int nCount);

    int UnSubMarketData(char *ppInstrumentID[], int nCount);

    void SetHeartbeatTimeout(unsigned int timeout);

    void ShmMarketData(CQdamFtdcShmDepthMarketDataField *reqfield,CQdamFtdcDepthMarketDataField *defdata);

    void setudpchannel(char *udpip);

    int ReqUserLogin(CQdamFtdcReqUserLoginField *pReqUserLogin, int nRequestID);

    int ReqUserLogout(CQdamFtdcReqUserLogoutField *pReqUserLogout, int nRequestID);

    int ReqSubMarketData(CQdamFtdcSpecificInstrumentField *pSpecificInstrument, int nRequestID);

    int ReqUnSubMarketData(CQdamFtdcSpecificInstrumentField *pSpecificInstrument, int nRequestID);

    int ReqSubscribeTopic(CQdamFtdcDisseminationField *pDissemination, int nRequestID);

    int ReqQryTopic(CQdamFtdcDisseminationField *pDissemination, int nRequestID);

    int ReqQryMarketData(CQdamFtdcQryMarketDataField *pQryMarketData, int nRequestID);

    void ActiveMultiMarketData(char * TradingDay);
};