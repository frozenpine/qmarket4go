/////////////////////////////////////////////////////////////////////////
///@system QuantDo Platform
///@company 上海量投网络科技有限公司
///@file QdamFtdcMduserApi.h
///@brief 定义了客户端接口
///@history 
///20130520	徐忠华	创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef QDAM_FTDCMDUSERAPI_H
#define QDAM_FTDCMDUSERAPI_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QdamFtdcUserApiStruct.h"

#if defined(ISLIB) && defined(WIN32)
#ifdef LIB_MDUSER_API_EXPORT
#define MDUSER_API_EXPORT __declspec(dllexport)
#else
#define MDUSER_API_EXPORT __declspec(dllimport)
#endif
#else
#define MDUSER_API_EXPORT 
#endif

class CQdamFtdcMduserSpi
{
public:
	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	virtual void OnFrontConnected(){};
	
	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	///@param nReason 错误原因
	///        0x1001 网络读失败
	///        0x1002 网络写失败
	///        0x2001 接收心跳超时
	///        0x2002 发送心跳失败
	///        0x2003 收到错误报文
	virtual void OnFrontDisconnected(int nReason){};
		
	///心跳超时警告。当长时间未收到报文时，该方法被调用。
	///@param nTimeLapse 距离上次接收报文的时间
	virtual void OnHeartBeatWarning(int nTimeLapse){};
	
	///报文回调开始通知。当API收到一个报文后，首先调用本方法，然后是各数据域的回调，最后是报文回调结束通知。
	///@param nTopicID 主题代码（如私有流、公共流、行情流等）
	///@param nSequenceNo 报文序号
	virtual void OnPackageStart(int nTopicID, int nSequenceNo){};
	
	///报文回调结束通知。当API收到一个报文后，首先调用报文回调开始通知，然后是各数据域的回调，最后调用本方法。
	///@param nTopicID 主题代码（如私有流、公共流、行情流等）
	///@param nSequenceNo 报文序号
	virtual void OnPackageEnd(int nTopicID, int nSequenceNo){};

	//新增多播心跳接口 add by zbz 20150304
	virtual void  OnMultiHeartbeat(char *CurrTime,char *MultiCastIP) {};
	
	//当广播收到值得时候，回调函数被调用，返回qmdata
	virtual void UdpMarketData(CQdamFtdcDepthMarketDataField *qmdata){};

	///错误应答
	virtual void OnRspError(CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户登录应答
	virtual void OnRspUserLogin(CQdamFtdcRspUserLoginField *pRspUserLogin, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户退出应答
	virtual void OnRspUserLogout(CQdamFtdcRspUserLogoutField *pRspUserLogout, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///深度行情通知
	virtual void OnRtnDepthMarketData(CQdamFtdcDepthMarketDataField *pDepthMarketData) {};

	///深度行情通知
	virtual void OnRtnMultiDepthMarketData(CQdamFtdcDepthMarketDataField *pDepthMarketData) {};

	///订阅合约的相关信息
	virtual void OnRspSubMarketData(CQdamFtdcSpecificInstrumentField *pSpecificInstrument, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///退订合约的相关信息
	virtual void OnRspUnSubMarketData(CQdamFtdcSpecificInstrumentField *pSpecificInstrument, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///分价行情
	virtual void OnRtnMBLMarketData(CQdamFtdcMBLMarketDataField *pMBLMarketData) {};

	///郑州合约状态
	virtual void OnRtnQmdInstrumentStatu(CQdamFtdcQmdInstrumentStateField *pQmdInstrumentState) {};

	///订阅主题应答
	virtual void OnRspSubscribeTopic(CQdamFtdcDisseminationField *pDissemination, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///主题查询应答
	virtual void OnRspQryTopic(CQdamFtdcDisseminationField *pDissemination, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///合约行情应答
	virtual void OnRspQryMarketData(CQdamFtdcRspMarketDataField *pRspMarketData, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
};

class MDUSER_API_EXPORT CQdamFtdcMduserApi
{
public:
	///创建MduserApi
	///@param pszFlowPath 存贮订阅信息文件的目录，默认为当前目录
	///@return 创建出的UserApi
	static CQdamFtdcMduserApi *CreateFtdcMduserApi(const char *pszFlowPath = "");
	
	///获取系统版本号
	///@param nMajorVersion 主版本号
	///@param nMinorVersion 子版本号
	///@return 系统标识字符串
	static const char *GetVersion();
	
	///删除接口对象本身
	///@remark 不再使用本接口对象时,调用该函数删除接口对象
	virtual void Release() = 0;
	
	//多播设置开关
	virtual void SetMultiCast(bool bMultiCast=false) = 0;

	//注册多播地址
	virtual void RegTopicMultiAddr(char *pMultiAddr)=0;
	
	
	///初始化
	///@remark 初始化运行环境,只有调用后,接口才开始工作
	virtual void Init() = 0;
	
	///等待接口线程结束运行
	///@return 线程退出代码
	virtual int Join() = 0;
	
	///获取当前交易日
	///@retrun 获取到的交易日
	///@remark 只有登录成功后,才能得到正确的交易日
	virtual const char *GetTradingDay() = 0;
	
	///注册前置机网络地址
	///@param pszFrontAddress：前置机网络地址。
	///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。 
	///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
	virtual void RegisterFront(char *pszFrontAddress) = 0;
	
	///注册名字服务器网络地址
	///@param pszNsAddress：名字服务器网络地址。
	///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。 
	///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
	///@remark RegisterFront优先于RegisterNameServer
	virtual void RegisterNameServer(char *pszNsAddress) = 0;
	
	///注册回调接口
	///@param pSpi 派生自回调接口类的实例
	virtual void RegisterSpi(CQdamFtdcMduserSpi *pSpi) = 0;

	///订阅市场行情。
	///@param nTopicID 市场行情主题  
	///@param nResumeType 市场行情重传方式  
	///        QDAM_TERT_RESTART:从本交易日开始重传
	///        QDAM_TERT_RESUME:从上次收到的续传(非订阅全部合约时，不支持续传模式)
	///        QDAM_TERT_QUICK:先传送当前行情快照,再传送登录后市场行情的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
	virtual void SubscribeMarketDataTopic(int nTopicID, QDAM_TE_RESUME_TYPE nResumeType) = 0;

	///订阅合约行情。
	///@param ppInstrumentID 合约ID  
	///@param nCount 要订阅/退订行情的合约个数
	///@remark 
	virtual int SubMarketData(char *ppInstrumentID[], int nCount)=0;

	///退订合约行情。
	///@param ppInstrumentID 合约ID  
	///@param nCount 要订阅/退订行情的合约个数
	///@remark 
	virtual int UnSubMarketData(char *ppInstrumentID[], int nCount)=0;		
	
	///设置心跳超时时间。
	///@param timeout 心跳超时时间(秒)  
	virtual void SetHeartbeatTimeout(unsigned int timeout) = 0;

	
	///共享内存取值
	///@param CQdamFtdcShmDepthMarketDataField  传入参数
	///@param CQdamFtdcDepthMarketDataField 查询到的行情值
	///@return 0 操作成功
	///@return -1 打开日志文件失败
	virtual void ShmMarketData(CQdamFtdcShmDepthMarketDataField *reqfield,CQdamFtdcDepthMarketDataField *defdata) = 0;
	
    ///建立UDP连接
	///@param  udpip广播地址
	///@return 0 操作成功
	///@return -1 读取UDP失败
	virtual  void setudpchannel(char *udpip)= 0;

	///用户登录请求
	virtual int ReqUserLogin(CQdamFtdcReqUserLoginField *pReqUserLogin, int nRequestID) = 0;

	///用户退出请求
	virtual int ReqUserLogout(CQdamFtdcReqUserLogoutField *pReqUserLogout, int nRequestID) = 0;

	///订阅合约的相关信息
	virtual int ReqSubMarketData(CQdamFtdcSpecificInstrumentField *pSpecificInstrument, int nRequestID) = 0;

	///退订合约的相关信息
	virtual int ReqUnSubMarketData(CQdamFtdcSpecificInstrumentField *pSpecificInstrument, int nRequestID) = 0;

	///订阅主题请求
	virtual int ReqSubscribeTopic(CQdamFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///主题查询请求
	virtual int ReqQryTopic(CQdamFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///合约行情查询
	virtual int ReqQryMarketData(CQdamFtdcQryMarketDataField *pQryMarketData, int nRequestID) = 0;

	//启动多播
	//在无法登录服务器的情况下，调用此接口可以接收组播行情
	//在可以登录的情况下无需调用此接口
	//@param TradingDay 交易日，在没有登录的情况下，可以是自然日，但是要注意交易所的交易日
	virtual void ActiveMultiMarketData(char * TradingDay) = 0;
protected:
	~CQdamFtdcMduserApi(){};
};

#endif
