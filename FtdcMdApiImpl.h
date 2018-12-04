/////////////////////////////////////////////////////////////////////////
///@system QuantDo Platform
///@company �Ϻ���Ͷ����Ƽ����޹�˾
///@file FtdcMdApiImpl.h
///@brief �����˿ͻ���c�ӿ�
///@history
///20160918	������	�������ļ�
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

//=============================[���ûص�����]================================
///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
typedef void (APPWINAPI *FunOnFrontConnected)();//�ص�����
MDUSER_API_EXPORT int SetCallbackFunOnFrontConnected(ClientID client,FunOnFrontConnected funHandle);//���ûص�������ָ��

///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
///@param nReason ����ԭ��
///        0x1001 �����ʧ��
///        0x1002 ����дʧ��
///        0x2001 ����������ʱ
///        0x2002 ��������ʧ��
///        0x2003 �յ�������
typedef void (APPWINAPI *FunOnFrontDisconnected)(int nReason);
MDUSER_API_EXPORT int SetCallbackFunOnFrontDisconnected(ClientID client,FunOnFrontDisconnected funHandle);

///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
typedef void (APPWINAPI *FunOnHeartBeatWarning)(int nTimeLapse);
MDUSER_API_EXPORT int SetCallbackFunOnHeartBeatWarning(ClientID client,FunOnHeartBeatWarning funHandle);

///���Ļص���ʼ֪ͨ����API�յ�һ�����ĺ����ȵ��ñ�������Ȼ���Ǹ�������Ļص�������Ǳ��Ļص�����֪ͨ��
///@param nID ������루��˽���������������������ȣ�
///@param nSequenceNo �������
typedef void (APPWINAPI *FunOnPackageStart)(int nTopicID, int nSequenceNo);
MDUSER_API_EXPORT int SetCallbackFunOnPackageStart(ClientID client,FunOnPackageStart funHandle);

///���Ļص�����֪ͨ����API�յ�һ�����ĺ����ȵ��ñ��Ļص���ʼ֪ͨ��Ȼ���Ǹ�������Ļص��������ñ�������
///@param nTopicID ������루��˽���������������������ȣ�
///@param nSequenceNo �������
typedef void (APPWINAPI *FunOnPackageEnd)(int nTopicID, int nSequenceNo);
MDUSER_API_EXPORT int SetCallbackFunOnPackageEnd(ClientID client,FunOnPackageEnd funHandle);

///�����ಥ�����ӿ�
typedef void (APPWINAPI *FunOnMultiHeartbeat)(char *CurrTime,char *MultiCastIP);
MDUSER_API_EXPORT int SetCallbackFunOnMultiHeartbeat(ClientID client,FunOnMultiHeartbeat funHandle);

///���Ķಥ����
typedef void (APPWINAPI *FunOnStopMultiTopic)(int nTopicID);
MDUSER_API_EXPORT int SetCallbackFunOnStopMultiTopic(ClientID client,FunOnStopMultiTopic funHandle);

typedef void (APPWINAPI *FunUdpMarketData)(CQdamFtdcDepthMarketDataField *qmdata);
MDUSER_API_EXPORT int SetCallbackFunUdpMarketData(ClientID client,FunUdpMarketData funHandle);
///����Ӧ��
typedef void (APPWINAPI *FunOnRspError)(CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
MDUSER_API_EXPORT int SetCallbackFunOnRspError(ClientID client,FunOnRspError funHandle);
///�û���¼Ӧ��
typedef void (APPWINAPI *FunOnRspUserLogin)(CQdamFtdcRspUserLoginField *pRspUserLogin, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
MDUSER_API_EXPORT int SetCallbackFunOnRspUserLogin(ClientID client,FunOnRspUserLogin funHandle);
///�û��˳�Ӧ��
typedef void (APPWINAPI *FunOnRspUserLogout)(CQdamFtdcRspUserLogoutField *pRspUserLogout, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
MDUSER_API_EXPORT int SetCallbackFunOnRspUserLogout(ClientID client,FunOnRspUserLogout funHandle);
///�������֪ͨ
typedef void (APPWINAPI *FunOnRtnDepthMarketData)(CQdamFtdcDepthMarketDataField* pDepthMarketData);
MDUSER_API_EXPORT int SetCallbackFunOnRtnDepthMarketData(ClientID client,FunOnRtnDepthMarketData funHandle);
///�������֪ͨ
typedef void (APPWINAPI *FunOnRtnMultiDepthMarketData)(CQdamFtdcDepthMarketDataField* pDepthMarketData);
MDUSER_API_EXPORT int SetCallbackFunOnRtnMultiDepthMarketData(ClientID client,FunOnRtnMultiDepthMarketData funHandle);
///���ĺ�Լ�������Ϣ
typedef void (APPWINAPI *FunOnRspSubMarketData)(CQdamFtdcSpecificInstrumentField *pSpecificInstrument, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
MDUSER_API_EXPORT int SetCallbackFunOnRspSubMarketData(ClientID client,FunOnRspSubMarketData funHandle);
///�˶���Լ�������Ϣ
typedef void (APPWINAPI *FunOnRspUnSubMarketData)(CQdamFtdcSpecificInstrumentField *pSpecificInstrument, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
MDUSER_API_EXPORT int SetCallbackFunOnRspUnSubMarketData(ClientID client,FunOnRspUnSubMarketData funHandle);
///�ּ�����
typedef void (APPWINAPI *FunOnRtnMBLMarketData)(CQdamFtdcMBLMarketDataField *pMBLMarketData);
MDUSER_API_EXPORT int SetCallbackFunOnRtnMBLMarketData(ClientID client,FunOnRtnMBLMarketData funHandle);
///֣�ݺ�Լ״̬
typedef void (APPWINAPI *FunOnRtnQmdInstrumentStatu)(CQdamFtdcQmdInstrumentStateField *pQmdInstrumentState);
MDUSER_API_EXPORT int SetCallbackFunOnRtnQmdInstrumentStatu(ClientID client,FunOnRtnQmdInstrumentStatu funHandle);
///��������Ӧ��
typedef void (APPWINAPI *FunOnRspSubscribeTopic)(CQdamFtdcDisseminationField *pDissemination, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
MDUSER_API_EXPORT int SetCallbackFunOnRspSubscribeTopic(ClientID client,FunOnRspSubscribeTopic funHandle);
///�����ѯӦ��
typedef void (APPWINAPI *FunOnRspQryTopic)(CQdamFtdcDisseminationField *pDissemination, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
MDUSER_API_EXPORT int SetCallbackFunOnRspQryTopic(ClientID client,FunOnRspQryTopic funHandle);
///��Լ����Ӧ��
typedef void (APPWINAPI *FunOnRspQryMarketData)(CQdamFtdcRspMarketDataField *pRspMarketData, CQdamFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
MDUSER_API_EXPORT int SetCallbackFunOnRspQryMarketData(ClientID client,FunOnRspQryMarketData funHandle);
//==================================================================================================

///��ʼ������
MDUSER_API_EXPORT void Init(ClientID client);

MDUSER_API_EXPORT int Join(ClientID client);

///�ͷ�API
MDUSER_API_EXPORT void Release(ClientID client);

MDUSER_API_EXPORT int InitApi(const char *pszFlowPath);

///��ȡ��ǰ������
///@retrun ��ȡ���Ľ�����
///@remark ֻ�е�¼�ɹ���,���ܵõ���ȷ�Ľ�����
MDUSER_API_EXPORT const char *GetTradingDay(ClientID client);

///�ಥ���ÿ���
MDUSER_API_EXPORT void SetMultiCast(ClientID client,bool bMultiCast);

//ע��ಥ��ַ
MDUSER_API_EXPORT void RegTopicMultiAddr(ClientID client,char *pMultiAddr);

///ע��ǰ�û������ַ
///@param pszFrontAddress��ǰ�û������ַ��
///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001���� 
///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
MDUSER_API_EXPORT void RegisterFront(ClientID client,char *pszFrontAddress);

///ע�����ַ����������ַ
///@param pszNsAddress�����ַ����������ַ��
///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:12001���� 
///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����12001������������˿ںš�
///@remark RegisterFront������RegisterNameServer
MDUSER_API_EXPORT void RegisterNameServer(ClientID client,char *pszNsAddress);

///�����г����顣
///@param nTopicID �г���������  
///@param nResumeType �г������ش���ʽ  
///        QDAM_TERT_RESTART:�ӱ������տ�ʼ�ش�
///        QDAM_TERT_RESUME:���ϴ��յ�������(�Ƕ���ȫ����Լʱ����֧������ģʽ)
///        QDAM_TERT_QUICK:�ȴ��͵�ǰ�������,�ٴ��͵�¼���г����������
///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�˽���������ݡ�
MDUSER_API_EXPORT void SubscribeMarketDataTopic(ClientID client,int nTopicID, QDAM_TE_RESUME_TYPE nResumeType);

///���ĺ�Լ���顣
///@param ppInstrumentID ��ԼID  
///@param nCount Ҫ����/�˶�����ĺ�Լ����
///@remark 
MDUSER_API_EXPORT void SubMarketData(ClientID client,char *ppInstrumentID[], int nCount);

///�˶���Լ���顣
///@param ppInstrumentID ��ԼID  
///@param nCount Ҫ����/�˶�����ĺ�Լ����
///@remark
MDUSER_API_EXPORT void UnSubMarketData(ClientID client,char *ppInstrumentID[], int nCount);

///����������ʱʱ�䡣
///@param timeout ������ʱʱ��(��)  
MDUSER_API_EXPORT void SetHeartbeatTimeout(ClientID client,unsigned int timeout);

///�����ڴ�ȡֵ
///@param CQdamFtdcShmDepthMarketDataField  �������
///@param CQdamFtdcDepthMarketDataField ��ѯ��������ֵ
///@return 0 �����ɹ�
///@return -1 ����־�ļ�ʧ��
MDUSER_API_EXPORT void ShmMarketData(ClientID client,CQdamFtdcShmDepthMarketDataField *reqfield,CQdamFtdcDepthMarketDataField *defdata);

///����UDP����
///@param  udpip�㲥��ַ
///@return 0 �����ɹ�
///@return -1 ��ȡUDPʧ��
MDUSER_API_EXPORT void setudpchannel(ClientID client,char *udpip);

///�û���¼����
MDUSER_API_EXPORT int ReqUserLogin(ClientID client,CQdamFtdcReqUserLoginField *pReqUserLogin, int nRequestID);

///�û��˳�����
MDUSER_API_EXPORT int ReqUserLogout(ClientID client,CQdamFtdcReqUserLogoutField *pReqUserLogout, int nRequestID);

///���ĺ�Լ�������Ϣ
MDUSER_API_EXPORT int ReqSubMarketData(ClientID client,CQdamFtdcSpecificInstrumentField *pSpecificInstrument, int nRequestID);

///�˶���Լ�������Ϣ
MDUSER_API_EXPORT int ReqUnSubMarketData(ClientID client,CQdamFtdcSpecificInstrumentField *pSpecificInstrument, int nRequestID);

///������������
MDUSER_API_EXPORT int ReqSubscribeTopic(ClientID client,CQdamFtdcDisseminationField *pDissemination, int nRequestID);

///�����ѯ����
MDUSER_API_EXPORT int ReqQryTopic(ClientID client,CQdamFtdcDisseminationField *pDissemination, int nRequestID);

///��Լ�����ѯ
MDUSER_API_EXPORT int ReqQryMarketData(ClientID client,CQdamFtdcQryMarketDataField *pQryMarketData, int nRequestID);

MDUSER_API_EXPORT void ActiveMultiMarketData(ClientID client,char *TradingDay);

#ifdef __cplusplus
}
#endif

#endif
