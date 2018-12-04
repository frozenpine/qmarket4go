/////////////////////////////////////////////////////////////////////////
///@system QuantDo Platform
///@company 上海量投网络科技有限公司
///@file FtdcMdApiImpl.h
///@brief 定义了客户端c接口
///@history
///20160918	范春阳	创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef FTDCMDAPIIMPL_H
#define FTDCMDAPIIMPL_H

#ifdef __GNUC__
    #define MDUSER_API_EXPORT __attribute__ ((dllimport))
#else
    #define MDUSER_API_EXPORT __declspec(dllimport)
#endif

#ifndef _WIN32
#define __stdcall
#endif
#define APPWINAPI __stdcall

#include <stdbool.h>
#include "QdamFtdcUserApiStruct.h"

typedef int ClientID;

#ifdef __cplusplus
extern "C" {
#endif

//=============================[设置回调函数]================================
///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
typedef void (APPWINAPI *FunOnFrontConnected)();//回调函数
MDUSER_API_EXPORT int SetCallbackFunOnFrontConnected(ClientID client,FunOnFrontConnected funHandle);//调用回调函数的指针

///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
///@param nReason 错误原因
///        0x1001 网络读失败
///        0x1002 网络写失败
///        0x2001 接收心跳超时
///        0x2002 发送心跳失败
///        0x2003 收到错误报文
typedef void (APPWINAPI *FunOnFrontDisconnected)(int nReason);
MDUSER_API_EXPORT int SetCallbackFunOnFrontDisconnected(ClientID client,FunOnFrontDisconnected funHandle);

///心跳超时警告。当长时间未收到报文时，该方法被调用。
///@param nTimeLapse 距离上次接收报文的时间
typedef void (APPWINAPI *FunOnHeartBeatWarning)(int nTimeLapse);
MDUSER_API_EXPORT int SetCallbackFunOnHeartBeatWarning(ClientID client,FunOnHeartBeatWarning funHandle);

///报文回调开始通知。当API收到一个报文后，首先调用本方法，然后是各数据域的回调，最后是报文回调结束通知。
///@param nID 主题代码（如私有流、公共流、行情流等）
///@param nSequenceNo 报文序号
typedef void (APPWINAPI *FunOnPackageStart)(int nTopicID, int nSequenceNo);
MDUSER_API_EXPORT int SetCallbackFunOnPackageStart(ClientID client,FunOnPackageStart funHandle);

///报文回调结束通知。当API收到一个报文后，首先调用报文回调开始通知，然后是各数据域的回调，最后调用本方法。
///@param nTopicID 主题代码（如私有流、公共流、行情流等）
///@param nSequenceNo 报文序号
typedef void (APPWINAPI *FunOnPackageEnd)(int nTopicID, int nSequenceNo);
MDUSER_API_EXPORT int SetCallbackFunOnPackageEnd(ClientID client,FunOnPackageEnd funHandle);

///新增多播心跳接口
typedef void (APPWINAPI *FunOnMultiHeartbeat)(char *CurrTime,char *MultiCastIP);
MDUSER_API_EXPORT int SetCallbackFunOnMultiHeartbeat(ClientID client,FunOnMultiHeartbeat funHandle);

///订阅多播主题
typedef void (APPWINAPI *FunOnStopMultiTopic)(int nTopicID);
MDUSER_API_EXPORT int SetCallbackFunOnStopMultiTopic(ClientID client,FunOnStopMultiTopic funHandle);

typedef void (APPWINAPI *FunUdpMarketData)(CQdamFtdcDepthMarketDataField *qmdata);
MDUSER_API_EXPORT int SetCallbackFunUdpMarketData(ClientID client,FunUdpMarketData funHandle);
///错误应答
typedef void (APPWINAPI *FunOnRspError)(CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
MDUSER_API_EXPORT int SetCallbackFunOnRspError(ClientID client,FunOnRspError funHandle);
///用户登录应答
typedef void (APPWINAPI *FunOnRspUserLogin)(CQdamFtdcRspUserLoginField *pRspUserLogin, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
MDUSER_API_EXPORT int SetCallbackFunOnRspUserLogin(ClientID client,FunOnRspUserLogin funHandle);
///用户退出应答
typedef void (APPWINAPI *FunOnRspUserLogout)(CQdamFtdcRspUserLogoutField *pRspUserLogout, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
MDUSER_API_EXPORT int SetCallbackFunOnRspUserLogout(ClientID client,FunOnRspUserLogout funHandle);
///深度行情通知
typedef void (APPWINAPI *FunOnRtnDepthMarketData)(CQdamFtdcDepthMarketDataField* pDepthMarketData);
MDUSER_API_EXPORT int SetCallbackFunOnRtnDepthMarketData(ClientID client,FunOnRtnDepthMarketData funHandle);
///深度行情通知
typedef void (APPWINAPI *FunOnRtnMultiDepthMarketData)(CQdamFtdcDepthMarketDataField* pDepthMarketData);
MDUSER_API_EXPORT int SetCallbackFunOnRtnMultiDepthMarketData(ClientID client,FunOnRtnMultiDepthMarketData funHandle);
///订阅合约的相关信息
typedef void (APPWINAPI *FunOnRspSubMarketData)(CQdamFtdcSpecificInstrumentField *pSpecificInstrument, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
MDUSER_API_EXPORT int SetCallbackFunOnRspSubMarketData(ClientID client,FunOnRspSubMarketData funHandle);
///退订合约的相关信息
typedef void (APPWINAPI *FunOnRspUnSubMarketData)(CQdamFtdcSpecificInstrumentField *pSpecificInstrument, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
MDUSER_API_EXPORT int SetCallbackFunOnRspUnSubMarketData(ClientID client,FunOnRspUnSubMarketData funHandle);
///分价行情
typedef void (APPWINAPI *FunOnRtnMBLMarketData)(CQdamFtdcMBLMarketDataField *pMBLMarketData);
MDUSER_API_EXPORT int SetCallbackFunOnRtnMBLMarketData(ClientID client,FunOnRtnMBLMarketData funHandle);
///郑州合约状态
typedef void (APPWINAPI *FunOnRtnQmdInstrumentStatu)(CQdamFtdcQmdInstrumentStateField *pQmdInstrumentState);
MDUSER_API_EXPORT int SetCallbackFunOnRtnQmdInstrumentStatu(ClientID client,FunOnRtnQmdInstrumentStatu funHandle);
///订阅主题应答
typedef void (APPWINAPI *FunOnRspSubscribeTopic)(CQdamFtdcDisseminationField *pDissemination, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
MDUSER_API_EXPORT int SetCallbackFunOnRspSubscribeTopic(ClientID client,FunOnRspSubscribeTopic funHandle);
///主题查询应答
typedef void (APPWINAPI *FunOnRspQryTopic)(CQdamFtdcDisseminationField *pDissemination, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
MDUSER_API_EXPORT int SetCallbackFunOnRspQryTopic(ClientID client,FunOnRspQryTopic funHandle);
///合约行情应答
typedef void (APPWINAPI *FunOnRspQryMarketData)(CQdamFtdcRspMarketDataField *pRspMarketData, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
MDUSER_API_EXPORT int SetCallbackFunOnRspQryMarketData(ClientID client,FunOnRspQryMarketData funHandle);
//==================================================================================================

///初始化环境
MDUSER_API_EXPORT void Init(ClientID client);

MDUSER_API_EXPORT int Join(ClientID client);

///释放API
MDUSER_API_EXPORT void Release(ClientID client);

MDUSER_API_EXPORT int InitApi(const char *pszFlowPath);

///获取当前交易日
///@retrun 获取到的交易日
///@remark 只有登录成功后,才能得到正确的交易日
MDUSER_API_EXPORT const char *GetTradingDay(ClientID client);

///多播设置开关
MDUSER_API_EXPORT void SetMultiCast(ClientID client,bool bMultiCast);

//注册多播地址
MDUSER_API_EXPORT void RegTopicMultiAddr(ClientID client,char *pMultiAddr);

///注册前置机网络地址
///@param pszFrontAddress：前置机网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。 
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
MDUSER_API_EXPORT void RegisterFront(ClientID client,char *pszFrontAddress);

///注册名字服务器网络地址
///@param pszNsAddress：名字服务器网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。 
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
///@remark RegisterFront优先于RegisterNameServer
MDUSER_API_EXPORT void RegisterNameServer(ClientID client,char *pszNsAddress);

///订阅市场行情。
///@param nTopicID 市场行情主题  
///@param nResumeType 市场行情重传方式  
///        QDAM_TERT_RESTART:从本交易日开始重传
///        QDAM_TERT_RESUME:从上次收到的续传(非订阅全部合约时，不支持续传模式)
///        QDAM_TERT_QUICK:先传送当前行情快照,再传送登录后市场行情的内容
///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
MDUSER_API_EXPORT void SubscribeMarketDataTopic(ClientID client,int nTopicID, QDAM_TE_RESUME_TYPE nResumeType);

///订阅合约行情。
///@param ppInstrumentID 合约ID  
///@param nCount 要订阅/退订行情的合约个数
///@remark 
MDUSER_API_EXPORT void SubMarketData(ClientID client,char *ppInstrumentID[], int nCount);

///退订合约行情。
///@param ppInstrumentID 合约ID  
///@param nCount 要订阅/退订行情的合约个数
///@remark
MDUSER_API_EXPORT void UnSubMarketData(ClientID client,char *ppInstrumentID[], int nCount);

///设置心跳超时时间。
///@param timeout 心跳超时时间(秒)  
MDUSER_API_EXPORT void SetHeartbeatTimeout(ClientID client,unsigned int timeout);

///共享内存取值
///@param CQdamFtdcShmDepthMarketDataField  传入参数
///@param CQdamFtdcDepthMarketDataField 查询到的行情值
///@return 0 操作成功
///@return -1 打开日志文件失败
MDUSER_API_EXPORT void ShmMarketData(ClientID client,CQdamFtdcShmDepthMarketDataField *reqfield,CQdamFtdcDepthMarketDataField *defdata);

///建立UDP连接
///@param  udpip广播地址
///@return 0 操作成功
///@return -1 读取UDP失败
MDUSER_API_EXPORT void setudpchannel(ClientID client,char *udpip);

///用户登录请求
MDUSER_API_EXPORT int ReqUserLogin(ClientID client,CQdamFtdcReqUserLoginField *pReqUserLogin, int nRequestID);

///用户退出请求
MDUSER_API_EXPORT int ReqUserLogout(ClientID client,CQdamFtdcReqUserLogoutField *pReqUserLogout, int nRequestID);

///订阅合约的相关信息
MDUSER_API_EXPORT int ReqSubMarketData(ClientID client,CQdamFtdcSpecificInstrumentField *pSpecificInstrument, int nRequestID);

///退订合约的相关信息
MDUSER_API_EXPORT int ReqUnSubMarketData(ClientID client,CQdamFtdcSpecificInstrumentField *pSpecificInstrument, int nRequestID);

///订阅主题请求
MDUSER_API_EXPORT int ReqSubscribeTopic(ClientID client,CQdamFtdcDisseminationField *pDissemination, int nRequestID);

///主题查询请求
MDUSER_API_EXPORT int ReqQryTopic(ClientID client,CQdamFtdcDisseminationField *pDissemination, int nRequestID);

///合约行情查询
MDUSER_API_EXPORT int ReqQryMarketData(ClientID client,CQdamFtdcQryMarketDataField *pQryMarketData, int nRequestID);

MDUSER_API_EXPORT void ActiveMultiMarketData(ClientID client,char *TradingDay);

#ifdef __cplusplus
}
#endif

#endif
