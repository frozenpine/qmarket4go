/////////////////////////////////////////////////////////////////////////
///@system QuantDo Platform
///@company �Ϻ���Ͷ����Ƽ����޹�˾
///@file QdamFtdcUserApitypedef struct.h
///@brief �����˿ͻ��˽ӿ�ʹ�õ�ҵ�����ݽṹ
///@history 
/////////////////////////////////////////////////////////////////////////

#ifndef QDAM_FTDCSTRUCT_H
#define QDAM_FTDCSTRUCT_H

#include "QdamFtdcUserApiDataType.h"

///��Ӧ��Ϣ
typedef struct
{
	///�������
	TQdamFtdcErrorIDType	ErrorID;
	///������Ϣ
	TQdamFtdcErrorMsgType	ErrorMsg;
} CQdamFtdcRspInfoField;

///ϵͳ�û���¼����
typedef struct
{
	///������
	TQdamFtdcDateType	TradingDay;
	///�����û�����
	TQdamFtdcUserIDType	UserID;
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///����
	TQdamFtdcPasswordType	Password;
	///�û��˲�Ʒ��Ϣ
	TQdamFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TQdamFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TQdamFtdcProtocolInfoType	ProtocolInfo;
	///IP��ַ
	TQdamFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TQdamFtdcMacAddressType	MacAddress;
	///�������Ĵ���
	TQdamFtdcDataCenterIDType	DataCenterID;
	///��̬����
	TQdamFtdcPasswordType	OneTimePassword;
	///�ն�IP��ַ
	TQdamFtdcIPAddressType	ClientIPAddress;
	///��Ȩ����
	TQdamFtdcAuthCodeType	AuthCode;
	///�Զ����ֶ�
	TQdamFtdcFieldContentType	FieldContent;
} CQdamFtdcReqUserLoginField;

///ϵͳ�û���¼Ӧ��
typedef struct
{
	///������
	TQdamFtdcDateType	TradingDay;
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�����û�����
	TQdamFtdcUserIDType	UserID;
	///��¼�ɹ�ʱ��
	TQdamFtdcTimeType	LoginTime;
	///�û���󱾵ر�����
	TQdamFtdcUserOrderLocalIDType	MaxOrderLocalID;
	///����ϵͳ����
	TQdamFtdcTradingSystemNameType	TradingSystemName;
	///�������Ĵ���
	TQdamFtdcDataCenterIDType	DataCenterID;
	///��Ա˽������ǰ����
	TQdamFtdcSequenceNoType	PrivateFlowSize;
	///����Ա˽������ǰ����
	TQdamFtdcSequenceNoType	UserFlowSize;
	///��¼������Ϣ
	TQdamFtdcLoginInfoType	LoginInfo;
	///�Ự���
	TQdamFtdcSessionIDType	SessionID;
	///ǰ�ñ��
	TQdamFtdcFrontIDType	FrontID;
} CQdamFtdcRspUserLoginField;

///�û��ǳ�����
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�����û�����
	TQdamFtdcUserIDType	UserID;
} CQdamFtdcReqUserLogoutField;

///�û��ǳ�Ӧ��
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�����û�����
	TQdamFtdcUserIDType	UserID;
} CQdamFtdcRspUserLogoutField;

///ǿ���û��˳�
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�����û�����
	TQdamFtdcUserIDType	UserID;
} CQdamFtdcForceUserExitField;

///�û������޸�
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�����û�����
	TQdamFtdcUserIDType	UserID;
	///������
	TQdamFtdcPasswordType	OldPassword;
	///������
	TQdamFtdcPasswordType	NewPassword;
} CQdamFtdcUserPasswordUpdateField;

///���뱨��
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�û����ر�����
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TQdamFtdcCustomType	UserCustom;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///ϵͳ�������
	TQdamFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��������
	TQdamFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TQdamFtdcDirectionType	Direction;
	///��ƽ��־
	TQdamFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TQdamFtdcPriceType	LimitPrice;
	///����
	TQdamFtdcVolumeType	Volume;
	///��Ч������
	TQdamFtdcTimeConditionType	TimeCondition;
	///GTD����
	TQdamFtdcDateType	GTDDate;
	///�ɽ�������
	TQdamFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TQdamFtdcVolumeType	MinVolume;
	///ֹ���
	TQdamFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TQdamFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TQdamFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TQdamFtdcBusinessUnitType	BusinessUnit;
	///ҵ�����
	TQdamFtdcBusinessTypeType	BusinessType;
} CQdamFtdcInputOrderField;

///��������
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�û����ر�����
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TQdamFtdcCustomType	UserCustom;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///�������
	TQdamFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///���γ��������ı��ر��
	TQdamFtdcUserOrderLocalIDType	UserOrderActionLocalID;
	///����������־
	TQdamFtdcActionFlagType	ActionFlag;
	///�۸�
	TQdamFtdcPriceType	LimitPrice;
	///�����仯
	TQdamFtdcVolumeType	VolumeChange;
	///ǰ�ñ��
	TQdamFtdcFrontIDType	FrontID;
	///�Ự���
	TQdamFtdcSessionIDType	SessionID;
} CQdamFtdcOrderActionField;

///�ڴ����
typedef struct
{
	///�ڴ����
	TQdamFtdcMemTableNameType	MemTableName;
} CQdamFtdcMemDBField;

///Ͷ�����ʽ��ʻ����������
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�ʽ���ˮ��
	TQdamFtdcAccountSeqNoType	AccountSeqNo;
	///�ʽ��ʺ�
	TQdamFtdcAccountIDType	AccountID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///���
	TQdamFtdcMoneyType	Amount;
	///�������
	TQdamFtdcAccountDirectionType	AmountDirection;
	///�û�����
	TQdamFtdcUserIDType	UserID;
} CQdamFtdcReqAccountDepositField;

///Ͷ�����ʽ��ʻ������Ӧ��
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�ʽ��ʺ�
	TQdamFtdcAccountIDType	AccountID;
	///�ʽ���ˮ��
	TQdamFtdcAccountSeqNoType	AccountSeqNo;
	///���
	TQdamFtdcMoneyType	Amount;
	///�������
	TQdamFtdcAccountDirectionType	AmountDirection;
	///�����ʽ�
	TQdamFtdcMoneyType	Available;
	///����׼����
	TQdamFtdcMoneyType	Balance;
	///�û�����
	TQdamFtdcUserIDType	UserID;
} CQdamFtdcRspAccountDepositField;

///ʵʱ�ϳ�
typedef struct
{
	///DB�������
	TQdamFtdcCommandNoType	CommandNo;
	///��������
	TQdamFtdcDateType	CommandDate;
	///����ʱ��
	TQdamFtdcTimeType	CommandTime;
	///DB��������
	TQdamFtdcCommandTypeType	CommandType;
	///�ֶ���
	TQdamFtdcFieldNameType	FieldName;
	///�ֶ�����
	TQdamFtdcFieldContentType	FieldContent;
} CQdamFtdcTBCommandField;

///�������
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�ʽ��ʺ�
	TQdamFtdcAccountIDType	AccountID;
	///�ʽ���ˮ��
	TQdamFtdcAccountSeqNoType	AccountSeqNo;
	///���
	TQdamFtdcMoneyType	Amount;
	///�������
	TQdamFtdcAccountDirectionType	AmountDirection;
	///�����ʽ�
	TQdamFtdcMoneyType	Available;
	///����׼����
	TQdamFtdcMoneyType	Balance;
	///�û�����
	TQdamFtdcUserIDType	UserID;
} CQdamFtdcInvestorAccountDepositResField;

///��Լ״̬
typedef struct
{
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///Ʒ�ִ���
	TQdamFtdcProductIDType	ProductID;
	///Ʒ������
	TQdamFtdcProductNameType	ProductName;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��Լ����
	TQdamFtdcInstrumentNameType	InstrumentName;
	///�������
	TQdamFtdcYearType	DeliveryYear;
	///������
	TQdamFtdcMonthType	DeliveryMonth;
	///�޼۵�����µ���
	TQdamFtdcVolumeType	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	TQdamFtdcVolumeType	MinLimitOrderVolume;
	///�м۵�����µ���
	TQdamFtdcVolumeType	MaxMarketOrderVolume;
	///�м۵���С�µ���
	TQdamFtdcVolumeType	MinMarketOrderVolume;
	///��������
	TQdamFtdcVolumeMultipleType	VolumeMultiple;
	///���۵�λ
	TQdamFtdcPriceTickType	PriceTick;
	///����
	TQdamFtdcCurrencyType	Currency;
	///��ͷ�޲�
	TQdamFtdcVolumeType	LongPosLimit;
	///��ͷ�޲�
	TQdamFtdcVolumeType	ShortPosLimit;
	///��ͣ���
	TQdamFtdcPriceType	LowerLimitPrice;
	///��ͣ���
	TQdamFtdcPriceType	UpperLimitPrice;
	///�����
	TQdamFtdcPriceType	PreSettlementPrice;
	///��Լ����״̬
	TQdamFtdcInstrumentStatusType	InstrumentStatus;
	///������
	TQdamFtdcDateType	CreateDate;
	///������
	TQdamFtdcDateType	OpenDate;
	///������
	TQdamFtdcDateType	ExpireDate;
	///��ʼ������
	TQdamFtdcDateType	StartDelivDate;
	///��󽻸���
	TQdamFtdcDateType	EndDelivDate;
	///���ƻ�׼��
	TQdamFtdcPriceType	BasisPrice;
	///��ǰ�Ƿ���
	TQdamFtdcBoolType	IsTrading;
	///������Ʒ����
	TQdamFtdcInstrumentIDType	UnderlyingInstrID;
	///������Ʒ����
	TQdamFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///�ֲ�����
	TQdamFtdcPositionTypeType	PositionType;
	///ִ�м�
	TQdamFtdcPriceType	StrikePrice;
	///��Ȩ����
	TQdamFtdcOptionsTypeType	OptionsType;
	///����
	TQdamFtdcRatioType	ExchangeRate;
	///��Ʒ����
	TQdamFtdcProductClassType	ProductClass;
	///��Ȩ��Ȩ��ʽ
	TQdamFtdcOptionsModeType	OptionsMode;
	///��֤���㷨����
	TQdamFtdcMarginCombTypeType	MarginCombType;
} CQdamFtdcInstrumentStatusField;

///����ģʽ��������
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�Զ������ֶ�
	TQdamFtdcAdviceRunModeType	RunMode;
} CQdamFtdcAdviceRunModeField;

///���ĺ�Լ״̬
typedef struct
{
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��Լ����״̬
	TQdamFtdcInstrumentStatusType	InstrumentStatus;
	///���뱾״̬ʱ��
	TQdamFtdcTimeType	EnterTime;
	///���뱾״̬ԭ��
	TQdamFtdcEnterReasonType	EnterReason;
} CQdamFtdcSubInstrumentStatusField;

///ִ����������
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�û����ر�����
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TQdamFtdcCustomType	UserCustom;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///ϵͳ�������
	TQdamFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��ƽ��־
	TQdamFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///����
	TQdamFtdcVolumeType	Volume;
	///ҵ��Ԫ
	TQdamFtdcBusinessUnitType	BusinessUnit;
	///ִ������
	TQdamFtdcActionTypeType	ActionType;
	///����ͷ������ĳֲַ���
	TQdamFtdcPosiDirectionType	PosiDirection;
	///��Ȩ��Ȩ���Ƿ����ڻ�ͷ��ı��
	TQdamFtdcReservePositionFlagTypeType	ReservePositionFlag;
	///��Ȩ��Ȩ�����ɵ�ͷ���Ƿ��Զ�ƽ��
	TQdamFtdcCloseFlagTypeType	CloseFlag;
} CQdamFtdcInputExecOrderField;

///ִ���������
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�û����ر�����
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TQdamFtdcCustomType	UserCustom;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///�������
	TQdamFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///���γ��������ı��ر��
	TQdamFtdcUserOrderLocalIDType	UserOrderActionLocalID;
	///����������־
	TQdamFtdcActionFlagType	ActionFlag;
	///�۸�
	TQdamFtdcPriceType	LimitPrice;
	///�����仯
	TQdamFtdcVolumeType	VolumeChange;
	///ǰ�ñ��
	TQdamFtdcFrontIDType	FrontID;
	///�Ự���
	TQdamFtdcSessionIDType	SessionID;
} CQdamFtdcExecOrderActionField;

///ѯ��¼��
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�û����ر�����
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TQdamFtdcCustomType	UserCustom;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///���ر������
	TQdamFtdcOrderLocalIDType	OrderLocalID;
} CQdamFtdcInputForQuoteField;

///����¼��
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�û����ر�����
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TQdamFtdcCustomType	UserCustom;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///ϵͳ�������
	TQdamFtdcOrderSysIDType	OrderSysID;
	///Ӧ�۱��
	TQdamFtdcOrderSysIDType	ForQuoteSysID;
	///���۸�
	TQdamFtdcPriceType	AskPrice;
	///������
	TQdamFtdcVolumeType	AskVolume;
	///����ƽ��־
	TQdamFtdcOffsetFlagType	AskOffsetFlag;
	///��Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	AskHedgeFlag;
	///��۸�
	TQdamFtdcPriceType	BidPrice;
	///������
	TQdamFtdcVolumeType	BidVolume;
	///��ƽ��־
	TQdamFtdcOffsetFlagType	BidOffsetFlag;
	///��Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	BidHedgeFlag;
	///ҵ��Ԫ
	TQdamFtdcBusinessUnitType	BusinessUnit;
	///�򷽱��ر������
	TQdamFtdcUserOrderLocalIDType	BidOrderRef;
	///�������ر������
	TQdamFtdcUserOrderLocalIDType	AskOrderRef;
} CQdamFtdcInputQuoteField;

///���۲���
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�û����ر�����
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TQdamFtdcCustomType	UserCustom;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///�������
	TQdamFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///���γ��������ı��ر��
	TQdamFtdcUserOrderLocalIDType	UserOrderActionLocalID;
	///����������־
	TQdamFtdcActionFlagType	ActionFlag;
	///�۸�
	TQdamFtdcPriceType	LimitPrice;
	///�����仯
	TQdamFtdcVolumeType	VolumeChange;
	///ǰ�ñ��
	TQdamFtdcFrontIDType	FrontID;
	///�Ự���
	TQdamFtdcSessionIDType	SessionID;
} CQdamFtdcQuoteActionField;

///��Ȩ�ԶԳ�¼��
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱���
	TQdamFtdcInvestorIDType	InvestorID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��Ȩ�ԶԳ�����
	TQdamFtdcOrderRefType	OptionSelfCloseRef;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///����
	TQdamFtdcVolumeType	Volume;
	///������
	TQdamFtdcRequestIDType	RequestID;
	///ҵ��Ԫ
	TQdamFtdcBusinessUnitType	BusinessUnit;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///��Ȩ��Ȩ��ͷ���Ƿ��ԶԳ�
	TQdamFtdcOptSelfCloseFlagType	OptSelfCloseFlag;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TQdamFtdcInvestUnitIDType	InvestUnitID;
	///�ʽ��ʺ�
	TQdamFtdcAccountIDType	AccountID;
	///����
	TQdamFtdcCurrencyType	Currency;
	///�ͻ�����
	TQdamFtdcClientIDType	ClientID;
	///�µ�IP��ַ
	TQdamFtdcIPAddressType	IPAddress;
	///�µ�MAC��ַ
	TQdamFtdcMacAddressType	MacAddress;
} CQdamFtdcInputOptionSelfCloseField;

///��Ȩ�ԶԳ����
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱���
	TQdamFtdcInvestorIDType	InvestorID;
	///��Ȩ�ԶԳ��������
	TQdamFtdcOrderActionRefType	OptionSelfCloseActionRef;
	///��Ȩ�ԶԳ�����
	TQdamFtdcOrderRefType	OptionSelfCloseRef;
	///������
	TQdamFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TQdamFtdcFrontIDType	FrontID;
	///�Ự���
	TQdamFtdcSessionIDType	SessionID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Ȩ�ԶԳ�������
	TQdamFtdcOrderSysIDType	OptionSelfCloseSysID;
	///����������־
	TQdamFtdcActionFlagType	ActionFlag;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///Ͷ�ʵ�Ԫ����
	TQdamFtdcInvestUnitIDType	InvestUnitID;
	///�µ�IP��ַ
	TQdamFtdcIPAddressType	IPAddress;
	///�µ�MAC��ַ
	TQdamFtdcMacAddressType	MacAddress;
} CQdamFtdcOptionSelfCloseActionField;

///ϯλ״̬�л�
typedef struct
{
	///ʹ���ĸ�ͨ���µ�
	TQdamFtdcNumberType	APIID;
	///�µ�ϯλ��
	TQdamFtdcSeatIDType	SeatID;
	///ϯλ״̬����
	TQdamFtdcSeatDirectionType	SeatDirection;
} CQdamFtdcChangeSeatStatusField;

///����¼��
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�û����ر�����
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TQdamFtdcCustomType	UserCustom;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///����
	TQdamFtdcVolumeType	Volume;
	///��������
	TQdamFtdcLockTypeType	LockType;
	///ҵ��Ԫ
	TQdamFtdcBusinessUnitType	BusinessUnit;
} CQdamFtdcInputLockField;

///�����������
typedef struct
{
	///������
	TQdamFtdcTradingDayType	TradingDay;
	///�����
	TQdamFtdcPriceType	PreSettlementPrice;
	///������
	TQdamFtdcPriceType	PreClosePrice;
	///��ֲ���
	TQdamFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TQdamFtdcRatioType	PreDelta;
} CQdamFtdcMarketDataBaseField;

///���龲̬����
typedef struct
{
	///����
	TQdamFtdcPriceType	OpenPrice;
	///��߼�
	TQdamFtdcPriceType	HighestPrice;
	///��ͼ�
	TQdamFtdcPriceType	LowestPrice;
	///������
	TQdamFtdcPriceType	ClosePrice;
	///��ͣ���
	TQdamFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TQdamFtdcPriceType	LowerLimitPrice;
	///�����
	TQdamFtdcPriceType	SettlementPrice;
	///����ʵ��
	TQdamFtdcRatioType	CurrDelta;
} CQdamFtdcMarketDataStaticField;

///�������³ɽ�����
typedef struct
{
	///���¼�
	TQdamFtdcPriceType	LastPrice;
	///����
	TQdamFtdcVolumeType	Volume;
	///�ɽ����
	TQdamFtdcMoneyType	Turnover;
	///�ֲ���
	TQdamFtdcLargeVolumeType	OpenInterest;
} CQdamFtdcMarketDataLastMatchField;

///�������ż�����
typedef struct
{
	///�����һ
	TQdamFtdcPriceType	BidPrice1;
	///������һ
	TQdamFtdcVolumeType	BidVolume1;
	///������һ
	TQdamFtdcPriceType	AskPrice1;
	///������һ
	TQdamFtdcVolumeType	AskVolume1;
} CQdamFtdcMarketDataBestPriceField;

///�����������������
typedef struct
{
	///����۶�
	TQdamFtdcPriceType	BidPrice2;
	///��������
	TQdamFtdcVolumeType	BidVolume2;
	///�������
	TQdamFtdcPriceType	BidPrice3;
	///��������
	TQdamFtdcVolumeType	BidVolume3;
} CQdamFtdcMarketDataBid23Field;

///������������������
typedef struct
{
	///�����۶�
	TQdamFtdcPriceType	AskPrice2;
	///��������
	TQdamFtdcVolumeType	AskVolume2;
	///��������
	TQdamFtdcPriceType	AskPrice3;
	///��������
	TQdamFtdcVolumeType	AskVolume3;
} CQdamFtdcMarketDataAsk23Field;

///���������ġ�������
typedef struct
{
	///�������
	TQdamFtdcPriceType	BidPrice4;
	///��������
	TQdamFtdcVolumeType	BidVolume4;
	///�������
	TQdamFtdcPriceType	BidPrice5;
	///��������
	TQdamFtdcVolumeType	BidVolume5;
} CQdamFtdcMarketDataBid45Field;

///���������ġ�������
typedef struct
{
	///��������
	TQdamFtdcPriceType	AskPrice4;
	///��������
	TQdamFtdcVolumeType	AskVolume4;
	///��������
	TQdamFtdcPriceType	AskPrice5;
	///��������
	TQdamFtdcVolumeType	AskVolume5;
} CQdamFtdcMarketDataAsk45Field;

///�������ʱ������
typedef struct
{
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TQdamFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TQdamFtdcMillisecType	UpdateMillisec;
} CQdamFtdcMarketDataUpdateTimeField;

///�������
typedef struct
{
	///������
	TQdamFtdcTradingDayType	TradingDay;
	///�����
	TQdamFtdcPriceType	PreSettlementPrice;
	///������
	TQdamFtdcPriceType	PreClosePrice;
	///��ֲ���
	TQdamFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TQdamFtdcRatioType	PreDelta;
	///����
	TQdamFtdcPriceType	OpenPrice;
	///��߼�
	TQdamFtdcPriceType	HighestPrice;
	///��ͼ�
	TQdamFtdcPriceType	LowestPrice;
	///������
	TQdamFtdcPriceType	ClosePrice;
	///��ͣ���
	TQdamFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TQdamFtdcPriceType	LowerLimitPrice;
	///�����
	TQdamFtdcPriceType	SettlementPrice;
	///����ʵ��
	TQdamFtdcRatioType	CurrDelta;
	///���¼�
	TQdamFtdcPriceType	LastPrice;
	///����
	TQdamFtdcVolumeType	Volume;
	///�ɽ����
	TQdamFtdcMoneyType	Turnover;
	///�ֲ���
	TQdamFtdcLargeVolumeType	OpenInterest;
	///�����һ
	TQdamFtdcPriceType	BidPrice1;
	///������һ
	TQdamFtdcVolumeType	BidVolume1;
	///������һ
	TQdamFtdcPriceType	AskPrice1;
	///������һ
	TQdamFtdcVolumeType	AskVolume1;
	///����۶�
	TQdamFtdcPriceType	BidPrice2;
	///��������
	TQdamFtdcVolumeType	BidVolume2;
	///�������
	TQdamFtdcPriceType	BidPrice3;
	///��������
	TQdamFtdcVolumeType	BidVolume3;
	///�����۶�
	TQdamFtdcPriceType	AskPrice2;
	///��������
	TQdamFtdcVolumeType	AskVolume2;
	///��������
	TQdamFtdcPriceType	AskPrice3;
	///��������
	TQdamFtdcVolumeType	AskVolume3;
	///�������
	TQdamFtdcPriceType	BidPrice4;
	///��������
	TQdamFtdcVolumeType	BidVolume4;
	///�������
	TQdamFtdcPriceType	BidPrice5;
	///��������
	TQdamFtdcVolumeType	BidVolume5;
	///��������
	TQdamFtdcPriceType	AskPrice4;
	///��������
	TQdamFtdcVolumeType	AskVolume4;
	///��������
	TQdamFtdcPriceType	AskPrice5;
	///��������
	TQdamFtdcVolumeType	AskVolume5;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TQdamFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TQdamFtdcMillisecType	UpdateMillisec;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///����������
	TQdamFtdcVolumeType	VolumeAskLot;
	///����������
	TQdamFtdcVolumeType	VolumeBidLot;
	///��Լ״̬
	TQdamFtdcInstrumentStatusType	InstrumentStatus;
	///��������
	TQdamFtdcPriceType	AskPrice6;
	///��������
	TQdamFtdcVolumeType	AskVolume6;
	///��������
	TQdamFtdcPriceType	AskPrice7;
	///��������
	TQdamFtdcVolumeType	AskVolume7;
	///�����۰�
	TQdamFtdcPriceType	AskPrice8;
	///��������
	TQdamFtdcVolumeType	AskVolume8;
	///�����۾�
	TQdamFtdcPriceType	AskPrice9;
	///��������
	TQdamFtdcVolumeType	AskVolume9;
	///�������
	TQdamFtdcPriceType	BidPrice6;
	///��������
	TQdamFtdcVolumeType	BidVolume6;
	///�������
	TQdamFtdcPriceType	BidPrice7;
	///��������
	TQdamFtdcVolumeType	BidVolume7;
	///����۰�
	TQdamFtdcPriceType	BidPrice8;
	///��������
	TQdamFtdcVolumeType	BidVolume8;
	///����۾�
	TQdamFtdcPriceType	BidPrice9;
	///��������
	TQdamFtdcVolumeType	BidVolume9;
	///������ʮ
	TQdamFtdcPriceType	AskPrice10;
	///������ʮ
	TQdamFtdcVolumeType	AskVolume10;
	///�����ʮ
	TQdamFtdcPriceType	BidPrice10;
	///������ʮ
	TQdamFtdcVolumeType	BidVolume10;
} CQdamFtdcDepthMarketDataField;

///���ĺ�Լ�������Ϣ
typedef struct
{
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
} CQdamFtdcSpecificInstrumentField;

///Ͷ����Ȩ��
typedef struct
{
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�Ƿ�ʹ�þ��ֱֲ���,Ͷ���˻���Ч
	TQdamFtdcPositionTypeType	PositionType;
	///�Գɽ�����ʽ,�ʽ��˻���Ч
	TQdamFtdcSelfTradeAvoidTypeType	SelfTradeAvoidType;
	///����Ȩ��
	TQdamFtdcTradingRightType	TradingRight;
	///�Ƿ����ʽ�
	TQdamFtdcBoolType	CheckAccount;
	///�Ƿ���ֲ�
	TQdamFtdcBoolType	CheckPosition;
	///�����Ƿ񱨾�
	TQdamFtdcBoolType	OrderWarning;
	///�ʽ�ֲ��Ƿ��ϲ�
	TQdamFtdcBoolType	QryUpAccPosi;
	///Ͷ��ѡ���ʽ��˻�����
	TQdamFtdcDistributeTypeType	DistributeType;
} CQdamFtdcInvestorRightField;

///����������
typedef struct
{
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
} CQdamFtdcMarketDataExchangeIDField;

///�����ڴ������ѯ
typedef struct
{
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TQdamFtdcIPAddressType	IPAddress;
	///���ĺ�
	TQdamFtdcTopicIDType	TopicID;
} CQdamFtdcShmDepthMarketDataField;

///TOPIC��ѯ
typedef struct
{
	///���ĺ�
	TQdamFtdcTopicIDType	TopicID;
} CQdamFtdcTopicSearchField;

///�ּ�����
typedef struct
{
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��������
	TQdamFtdcDirectionType	Direction;
	///�۸�
	TQdamFtdcPriceType	Price;
	///����
	TQdamFtdcVolumeType	Volume;
	///����޸�ʱ��
	TQdamFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TQdamFtdcMillisecType	UpdateMillisec;
} CQdamFtdcMBLMarketDataField;

///������Լ��������
typedef struct
{
	///����������
	TQdamFtdcVolumeType	VolumeAskLot;
	///����������
	TQdamFtdcVolumeType	VolumeBidLot;
} CQdamFtdcMarketDataCMBVolumeField;

///��Լ״̬
typedef struct
{
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��Լ����״̬
	TQdamFtdcInstrumentStatusType	InstrumentStatus;
} CQdamFtdcQmdInstrumentStateField;

///���ĺ�Լ�������Ϣ
typedef struct
{
	///��Լ����
	TQdamFtdcSubInstrumentIDType	InstrumentID;
} CQdamFtdcSubSpecificInstrumentField;

///����������������
typedef struct
{
	///��������
	TQdamFtdcPriceType	AskPrice6;
	///��������
	TQdamFtdcVolumeType	AskVolume6;
	///��������
	TQdamFtdcPriceType	AskPrice7;
	///��������
	TQdamFtdcVolumeType	AskVolume7;
} CQdamFtdcMarketDataAsk67Field;

///���������˾�����
typedef struct
{
	///�����۰�
	TQdamFtdcPriceType	AskPrice8;
	///��������
	TQdamFtdcVolumeType	AskVolume8;
	///�����۾�
	TQdamFtdcPriceType	AskPrice9;
	///��������
	TQdamFtdcVolumeType	AskVolume9;
} CQdamFtdcMarketDataAsk89Field;

///����������������
typedef struct
{
	///�������
	TQdamFtdcPriceType	BidPrice6;
	///��������
	TQdamFtdcVolumeType	BidVolume6;
	///�������
	TQdamFtdcPriceType	BidPrice7;
	///��������
	TQdamFtdcVolumeType	BidVolume7;
} CQdamFtdcMarketDataBid67Field;

///��������˾�����
typedef struct
{
	///����۰�
	TQdamFtdcPriceType	BidPrice8;
	///��������
	TQdamFtdcVolumeType	BidVolume8;
	///����۾�
	TQdamFtdcPriceType	BidPrice9;
	///��������
	TQdamFtdcVolumeType	BidVolume9;
} CQdamFtdcMarketDataBid89Field;

///������������ʮ����
typedef struct
{
	///������ʮ
	TQdamFtdcPriceType	AskPrice10;
	///������ʮ
	TQdamFtdcVolumeType	AskVolume10;
	///�����ʮ
	TQdamFtdcPriceType	BidPrice10;
	///������ʮ
	TQdamFtdcVolumeType	BidVolume10;
} CQdamFtdcMarketDataAskBid10Field;

///�����Լ״̬
typedef struct
{
	///��Լ״̬
	TQdamFtdcInstrumentStatusType	InstrumentStatus;
} CQdamFtdcMarketDataInstrumentStatusField;

///�ɽ�
typedef struct
{
	///������
	TQdamFtdcTradingDayType	TradingDay;
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�û����ر�����
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TQdamFtdcCustomType	UserCustom;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///�ɽ����
	TQdamFtdcTradeIDType	TradeID;
	///�������
	TQdamFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��������
	TQdamFtdcDirectionType	Direction;
	///��ƽ��־
	TQdamFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///�ɽ��۸�
	TQdamFtdcPriceType	TradePrice;
	///�ɽ�����
	TQdamFtdcVolumeType	TradeVolume;
	///�ɽ�ʱ��
	TQdamFtdcTimeType	TradeTime;
	///�����Ա���
	TQdamFtdcParticipantIDType	ClearingPartID;
	///�ɽ����
	TQdamFtdcMoneyType	TradeAmnt;
	///��������
	TQdamFtdcTradeTypeType	TradeType;
	///Ӫҵ������
	TQdamFtdcBranchIDType	BranchID;
	///Ӫҵ������
	TQdamFtdcBranchNameType	BranchName;
} CQdamFtdcTradeField;

///����
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�û����ر�����
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TQdamFtdcCustomType	UserCustom;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///ϵͳ�������
	TQdamFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��������
	TQdamFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TQdamFtdcDirectionType	Direction;
	///��ƽ��־
	TQdamFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TQdamFtdcPriceType	LimitPrice;
	///����
	TQdamFtdcVolumeType	Volume;
	///��Ч������
	TQdamFtdcTimeConditionType	TimeCondition;
	///GTD����
	TQdamFtdcDateType	GTDDate;
	///�ɽ�������
	TQdamFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TQdamFtdcVolumeType	MinVolume;
	///ֹ���
	TQdamFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TQdamFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TQdamFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TQdamFtdcBusinessUnitType	BusinessUnit;
	///ҵ�����
	TQdamFtdcBusinessTypeType	BusinessType;
	///������
	TQdamFtdcTradingDayType	TradingDay;
	///����ʱ��
	TQdamFtdcTimeType	InsertTime;
	///������Դ
	TQdamFtdcOrderSourceType	OrderSource;
	///����״̬
	TQdamFtdcOrderStatusType	OrderStatus;
	///����ʱ��
	TQdamFtdcTimeType	CancelTime;
	///�����û����
	TQdamFtdcUserIDType	CancelUserID;
	///�Ѿ��ɽ�����
	TQdamFtdcVolumeType	VolumeTraded;
	///����ʣ������
	TQdamFtdcVolumeType	VolumeRemain;
	///�Ѿ���������
	TQdamFtdcVolumeType	VolumeCancled;
	///�������
	TQdamFtdcErrorIDType	ErrorID;
	///������Ϣ
	TQdamFtdcErrorMsgType	ErrorMsg;
	///���ϴ����ӵĳ�������
	TQdamFtdcVolumeType	VolumeIncCancled;
	///���ϴ����ӵĳɽ�����
	TQdamFtdcVolumeType	VolumeIncTraded;
	///�ʽ��ʺ�
	TQdamFtdcAccountIDType	AccountID;
	///ǰ�ñ��
	TQdamFtdcFrontIDType	FrontID;
	///�Ự���
	TQdamFtdcSessionIDType	SessionID;
	///������
	TQdamFtdcRequestIDType	RequestID;
	///ÿ��������
	TQdamFtdcMoneyType	EachFee;
	///ÿ�ֱ�֤��
	TQdamFtdcMoneyType	EachMargin;
	///ÿ����ȨȨ������֧
	TQdamFtdcMoneyType	EachPremium;
	///�µ�IP��ַ
	TQdamFtdcIPAddressType	IPAddress;
	///�µ�MAC��ַ
	TQdamFtdcMacAddressType	MacAddress;
	///Ӫҵ������
	TQdamFtdcBranchIDType	BranchID;
	///��¼���
	TQdamFtdcSequenceNoType	RecNum;
	///Ӳ�����к�
	TQdamFtdcHDSerialIDType	HDSerialID;
	///Ӫҵ������
	TQdamFtdcBranchNameType	BranchName;
} CQdamFtdcOrderField;

///����������
typedef struct
{
	///����ϵ�к�
	TQdamFtdcSequenceSeriesType	SequenceSeries;
	///������
	TQdamFtdcDateType	TradingDay;
	///�������Ĵ���
	TQdamFtdcDataCenterIDType	DataCenterID;
	///������ʼ���к�
	TQdamFtdcSequenceNoType	StartSequenceNo;
	///���˽������к�
	TQdamFtdcSequenceNoType	EndSequenceNo;
} CQdamFtdcFlowMessageCancelField;

///��Ϣ�ַ�
typedef struct
{
	///����ϵ�к�
	TQdamFtdcSequenceSeriesType	SequenceSeries;
	///���к�
	TQdamFtdcSequenceNoType	SequenceNo;
} CQdamFtdcDisseminationField;

///������Ϣ֪ͨ
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�޸��û����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�ۼӴ���
	TQdamFtdcTotalNumsType	Nums;
	///���漶��
	TQdamFtdcErrorLevelType	WarnLevel;
	///������
	TQdamFtdcErrorIDType	WarnID;
	///������Ϣ
	TQdamFtdcLargeErrorMsgType	WarnMsg;
	///����ʱ��
	TQdamFtdcTimeType	WarnTime;
} CQdamFtdcMessageNotifyField;

///������ָ��֪ͨ
typedef struct
{
	///Ͷ���û�����
	TQdamFtdcUserIDType	InvestorAdvicer;
	///Ͷ�ʾ���
	TQdamFtdcUserIDType	InvestorManager;
	///����Ա
	TQdamFtdcUserIDType	UserTrader;
	///��������
	TQdamFtdcVolumeType	VolumeFrozen;
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�û����ر�����
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TQdamFtdcCustomType	UserCustom;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///ϵͳ�������
	TQdamFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��������
	TQdamFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TQdamFtdcDirectionType	Direction;
	///��ƽ��־
	TQdamFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TQdamFtdcPriceType	LimitPrice;
	///����
	TQdamFtdcVolumeType	Volume;
	///��Ч������
	TQdamFtdcTimeConditionType	TimeCondition;
	///GTD����
	TQdamFtdcDateType	GTDDate;
	///�ɽ�������
	TQdamFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TQdamFtdcVolumeType	MinVolume;
	///ֹ���
	TQdamFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TQdamFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TQdamFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TQdamFtdcBusinessUnitType	BusinessUnit;
	///ҵ�����
	TQdamFtdcBusinessTypeType	BusinessType;
	///������
	TQdamFtdcTradingDayType	TradingDay;
	///����ʱ��
	TQdamFtdcTimeType	InsertTime;
	///������Դ
	TQdamFtdcOrderSourceType	OrderSource;
	///����״̬
	TQdamFtdcOrderStatusType	OrderStatus;
	///����ʱ��
	TQdamFtdcTimeType	CancelTime;
	///�����û����
	TQdamFtdcUserIDType	CancelUserID;
	///�Ѿ��ɽ�����
	TQdamFtdcVolumeType	VolumeTraded;
	///����ʣ������
	TQdamFtdcVolumeType	VolumeRemain;
	///�Ѿ���������
	TQdamFtdcVolumeType	VolumeCancled;
	///�������
	TQdamFtdcErrorIDType	ErrorID;
	///������Ϣ
	TQdamFtdcErrorMsgType	ErrorMsg;
	///���ϴ����ӵĳ�������
	TQdamFtdcVolumeType	VolumeIncCancled;
	///���ϴ����ӵĳɽ�����
	TQdamFtdcVolumeType	VolumeIncTraded;
	///�ʽ��ʺ�
	TQdamFtdcAccountIDType	AccountID;
	///ǰ�ñ��
	TQdamFtdcFrontIDType	FrontID;
	///�Ự���
	TQdamFtdcSessionIDType	SessionID;
	///������
	TQdamFtdcRequestIDType	RequestID;
	///ÿ��������
	TQdamFtdcMoneyType	EachFee;
	///ÿ�ֱ�֤��
	TQdamFtdcMoneyType	EachMargin;
	///ÿ����ȨȨ������֧
	TQdamFtdcMoneyType	EachPremium;
	///�µ�IP��ַ
	TQdamFtdcIPAddressType	IPAddress;
	///�µ�MAC��ַ
	TQdamFtdcMacAddressType	MacAddress;
	///Ӫҵ������
	TQdamFtdcBranchIDType	BranchID;
	///��¼���
	TQdamFtdcSequenceNoType	RecNum;
	///ָ��û���Ϣ
	TQdamFtdcAdviceUserInfoType	AdviceUserInfo;
	///Ӳ�����к�
	TQdamFtdcHDSerialIDType	HDSerialID;
	///Ӫҵ������
	TQdamFtdcBranchNameType	BranchName;
} CQdamFtdcAdviceOrderField;

///ִ������֪ͨ
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�û����ر�����
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TQdamFtdcCustomType	UserCustom;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///ϵͳ�������
	TQdamFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��ƽ��־
	TQdamFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///����
	TQdamFtdcVolumeType	Volume;
	///ҵ��Ԫ
	TQdamFtdcBusinessUnitType	BusinessUnit;
	///ִ������
	TQdamFtdcActionTypeType	ActionType;
	///����ͷ������ĳֲַ���
	TQdamFtdcPosiDirectionType	PosiDirection;
	///��Ȩ��Ȩ���Ƿ����ڻ�ͷ��ı��
	TQdamFtdcReservePositionFlagTypeType	ReservePositionFlag;
	///��Ȩ��Ȩ�����ɵ�ͷ���Ƿ��Զ�ƽ��
	TQdamFtdcCloseFlagTypeType	CloseFlag;
	///ִ�н��
	TQdamFtdcExecResultTypeType	ExecResultType;
	///������
	TQdamFtdcTradingDayType	TradingDay;
	///����ʱ��
	TQdamFtdcTimeType	InsertTime;
	///������Դ
	TQdamFtdcOrderSourceType	OrderSource;
	///����״̬
	TQdamFtdcOrderStatusType	OrderStatus;
	///����ʱ��
	TQdamFtdcTimeType	CancelTime;
	///�����û����
	TQdamFtdcUserIDType	CancelUserID;
	///�Ѿ��ɽ�����
	TQdamFtdcVolumeType	VolumeTraded;
	///����ʣ������
	TQdamFtdcVolumeType	VolumeRemain;
	///�Ѿ���������
	TQdamFtdcVolumeType	VolumeCancled;
	///�������
	TQdamFtdcErrorIDType	ErrorID;
	///������Ϣ
	TQdamFtdcErrorMsgType	ErrorMsg;
	///���ϴ����ӵĳ�������
	TQdamFtdcVolumeType	VolumeIncCancled;
	///���ϴ����ӵĳɽ�����
	TQdamFtdcVolumeType	VolumeIncTraded;
	///�ʽ��ʺ�
	TQdamFtdcAccountIDType	AccountID;
	///ǰ�ñ��
	TQdamFtdcFrontIDType	FrontID;
	///�Ự���
	TQdamFtdcSessionIDType	SessionID;
	///������
	TQdamFtdcRequestIDType	RequestID;
	///ÿ��������
	TQdamFtdcMoneyType	EachFee;
	///ÿ�ֱ�֤��
	TQdamFtdcMoneyType	EachMargin;
	///ÿ����ȨȨ������֧
	TQdamFtdcMoneyType	EachPremium;
	///�µ�IP��ַ
	TQdamFtdcIPAddressType	IPAddress;
	///�µ�MAC��ַ
	TQdamFtdcMacAddressType	MacAddress;
	///Ӫҵ������
	TQdamFtdcBranchIDType	BranchID;
	///��¼���
	TQdamFtdcSequenceNoType	RecNum;
} CQdamFtdcExecOrderField;

///ѯ����֪ͨ
typedef struct
{
	///������
	TQdamFtdcDateType	TradingDay;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///ѯ�۱��
	TQdamFtdcOrderSysIDType	OrderSysID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///����ʱ��
	TQdamFtdcTimeType	InsertTime;
} CQdamFtdcForQuoteRspField;

///����֪ͨ
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�û����ر�����
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TQdamFtdcCustomType	UserCustom;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///ϵͳ�������
	TQdamFtdcOrderSysIDType	OrderSysID;
	///Ӧ�۱��
	TQdamFtdcOrderSysIDType	ForQuoteSysID;
	///���۸�
	TQdamFtdcPriceType	AskPrice;
	///������
	TQdamFtdcVolumeType	AskVolume;
	///����ƽ��־
	TQdamFtdcOffsetFlagType	AskOffsetFlag;
	///��Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	AskHedgeFlag;
	///��۸�
	TQdamFtdcPriceType	BidPrice;
	///������
	TQdamFtdcVolumeType	BidVolume;
	///��ƽ��־
	TQdamFtdcOffsetFlagType	BidOffsetFlag;
	///��Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	BidHedgeFlag;
	///ҵ��Ԫ
	TQdamFtdcBusinessUnitType	BusinessUnit;
	///�򷽱��ر������
	TQdamFtdcUserOrderLocalIDType	BidOrderRef;
	///�������ر������
	TQdamFtdcUserOrderLocalIDType	AskOrderRef;
	///������
	TQdamFtdcTradingDayType	TradingDay;
	///����ʱ��
	TQdamFtdcTimeType	InsertTime;
	///������Դ
	TQdamFtdcOrderSourceType	OrderSource;
	///����״̬
	TQdamFtdcOrderStatusType	OrderStatus;
	///����ʱ��
	TQdamFtdcTimeType	CancelTime;
	///�����û����
	TQdamFtdcUserIDType	CancelUserID;
	///�Ѿ��ɽ�����
	TQdamFtdcVolumeType	VolumeTraded;
	///����ʣ������
	TQdamFtdcVolumeType	VolumeRemain;
	///�Ѿ���������
	TQdamFtdcVolumeType	VolumeCancled;
	///�������
	TQdamFtdcErrorIDType	ErrorID;
	///������Ϣ
	TQdamFtdcErrorMsgType	ErrorMsg;
	///���ϴ����ӵĳ�������
	TQdamFtdcVolumeType	VolumeIncCancled;
	///���ϴ����ӵĳɽ�����
	TQdamFtdcVolumeType	VolumeIncTraded;
	///�ʽ��ʺ�
	TQdamFtdcAccountIDType	AccountID;
	///ǰ�ñ��
	TQdamFtdcFrontIDType	FrontID;
	///�Ự���
	TQdamFtdcSessionIDType	SessionID;
	///������
	TQdamFtdcRequestIDType	RequestID;
	///ÿ��������
	TQdamFtdcMoneyType	EachFee;
	///ÿ�ֱ�֤��
	TQdamFtdcMoneyType	EachMargin;
	///ÿ����ȨȨ������֧
	TQdamFtdcMoneyType	EachPremium;
	///�µ�IP��ַ
	TQdamFtdcIPAddressType	IPAddress;
	///�µ�MAC��ַ
	TQdamFtdcMacAddressType	MacAddress;
	///Ӫҵ������
	TQdamFtdcBranchIDType	BranchID;
	///��¼���
	TQdamFtdcSequenceNoType	RecNum;
	///��ϵͳ�������
	TQdamFtdcOrderSysIDType	BidOrderSysID;
	///����ϵͳ�������
	TQdamFtdcOrderSysIDType	AskOrderSysID;
} CQdamFtdcQuoteField;

///��Ȩ�ԶԳ�
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱���
	TQdamFtdcInvestorIDType	InvestorID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��Ȩ�ԶԳ�����
	TQdamFtdcOrderRefType	OptionSelfCloseRef;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///����
	TQdamFtdcVolumeType	Volume;
	///������
	TQdamFtdcRequestIDType	RequestID;
	///ҵ��Ԫ
	TQdamFtdcBusinessUnitType	BusinessUnit;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///��Ȩ��Ȩ��ͷ���Ƿ��ԶԳ�
	TQdamFtdcOptSelfCloseFlagType	OptSelfCloseFlag;
	///������Ȩ�ԶԳ���
	TQdamFtdcOrderLocalIDType	OptionSelfCloseLocalID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Ա���
	TQdamFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQdamFtdcClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TQdamFtdcExchangeInstIDType	ExchangeInstID;
	///����������Ա����
	TQdamFtdcTraderIDType	TraderID;
	///��װ���
	TQdamFtdcInstallIDType	InstallID;
	///��Ȩ�ԶԳ��ύ״̬
	TQdamFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///������ʾ���
	TQdamFtdcSequenceNoType	NotifySequence;
	///������
	TQdamFtdcDateType	TradingDay;
	///������
	TQdamFtdcSettlementIDType	SettlementID;
	///��Ȩ�ԶԳ�������
	TQdamFtdcOrderSysIDType	OptionSelfCloseSysID;
	///��������
	TQdamFtdcDateType	InsertDate;
	///����ʱ��
	TQdamFtdcTimeType	InsertTime;
	///����ʱ��
	TQdamFtdcTimeType	CancelTime;
	///�ԶԳ���
	TQdamFtdcExecResultTypeType	ExecResultType;
	///�����Ա���
	TQdamFtdcParticipantIDType	ClearingPartID;
	///���
	TQdamFtdcSequenceNoType	SequenceNo;
	///ǰ�ñ��
	TQdamFtdcFrontIDType	FrontID;
	///�Ự���
	TQdamFtdcSessionIDType	SessionID;
	///�û��˲�Ʒ��Ϣ
	TQdamFtdcProductInfoType	UserProductInfo;
	///״̬��Ϣ
	TQdamFtdcStatusMsgType	StatusMsg;
	///�����û�����
	TQdamFtdcUserIDType	ActiveUserID;
	///���͹�˾�������
	TQdamFtdcSequenceNoType	BrokerOptionSelfCloseSeq;
	///Ӫҵ�����
	TQdamFtdcBranchIDType	BranchID;
	///Ͷ�ʵ�Ԫ����
	TQdamFtdcInvestUnitIDType	InvestUnitID;
	///�ʽ��ʺ�
	TQdamFtdcAccountIDType	AccountID;
	///����
	TQdamFtdcCurrencyType	Currency;
	///�µ�IP��ַ
	TQdamFtdcIPAddressType	IPAddress;
	///�µ�MAC��ַ
	TQdamFtdcMacAddressType	MacAddress;
} CQdamFtdcOptionSelfCloseField;

///����
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�û����ر�����
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TQdamFtdcCustomType	UserCustom;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///����
	TQdamFtdcVolumeType	Volume;
	///��������
	TQdamFtdcLockTypeType	LockType;
	///ҵ��Ԫ
	TQdamFtdcBusinessUnitType	BusinessUnit;
	///������
	TQdamFtdcTradingDayType	TradingDay;
	///�������
	TQdamFtdcOrderSysIDType	LockSysID;
	///����ʱ��
	TQdamFtdcTimeType	InsertTime;
	///����״̬
	TQdamFtdcOrderActionStatusType	LockStatus;
	///����ʱ��
	TQdamFtdcTimeType	CancelTime;
	///�ʽ��ʺ�
	TQdamFtdcAccountIDType	AccountID;
	///ǰ�ñ��
	TQdamFtdcFrontIDType	FrontID;
	///�Ự���
	TQdamFtdcSessionIDType	SessionID;
	///������
	TQdamFtdcRequestIDType	RequestID;
	///�µ�IP��ַ
	TQdamFtdcIPAddressType	IPAddress;
	///�µ�MAC��ַ
	TQdamFtdcMacAddressType	MacAddress;
	///Ӫҵ������
	TQdamFtdcBranchIDType	BranchID;
	///�������
	TQdamFtdcErrorIDType	ErrorID;
	///������Ϣ
	TQdamFtdcErrorMsgType	ErrorMsg;
	///��¼���
	TQdamFtdcSequenceNoType	RecNum;
} CQdamFtdcLockField;

///������ѯ
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�������
	TQdamFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
} CQdamFtdcQryOrderField;

///�ɽ���ѯ
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�ɽ����
	TQdamFtdcTradeIDType	TradeID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
} CQdamFtdcQryTradeField;

///��Լ��ѯ
typedef struct
{
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Ʒ����
	TQdamFtdcProductIDType	ProductID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
} CQdamFtdcQryInstrumentField;

///��Լ��ѯӦ��
typedef struct
{
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///Ʒ�ִ���
	TQdamFtdcProductIDType	ProductID;
	///Ʒ������
	TQdamFtdcProductNameType	ProductName;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��Լ����
	TQdamFtdcInstrumentNameType	InstrumentName;
	///�������
	TQdamFtdcYearType	DeliveryYear;
	///������
	TQdamFtdcMonthType	DeliveryMonth;
	///�޼۵�����µ���
	TQdamFtdcVolumeType	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	TQdamFtdcVolumeType	MinLimitOrderVolume;
	///�м۵�����µ���
	TQdamFtdcVolumeType	MaxMarketOrderVolume;
	///�м۵���С�µ���
	TQdamFtdcVolumeType	MinMarketOrderVolume;
	///��������
	TQdamFtdcVolumeMultipleType	VolumeMultiple;
	///���۵�λ
	TQdamFtdcPriceTickType	PriceTick;
	///����
	TQdamFtdcCurrencyType	Currency;
	///��ͷ�޲�
	TQdamFtdcVolumeType	LongPosLimit;
	///��ͷ�޲�
	TQdamFtdcVolumeType	ShortPosLimit;
	///��ͣ���
	TQdamFtdcPriceType	LowerLimitPrice;
	///��ͣ���
	TQdamFtdcPriceType	UpperLimitPrice;
	///�����
	TQdamFtdcPriceType	PreSettlementPrice;
	///��Լ����״̬
	TQdamFtdcInstrumentStatusType	InstrumentStatus;
	///������
	TQdamFtdcDateType	CreateDate;
	///������
	TQdamFtdcDateType	OpenDate;
	///������
	TQdamFtdcDateType	ExpireDate;
	///��ʼ������
	TQdamFtdcDateType	StartDelivDate;
	///��󽻸���
	TQdamFtdcDateType	EndDelivDate;
	///���ƻ�׼��
	TQdamFtdcPriceType	BasisPrice;
	///��ǰ�Ƿ���
	TQdamFtdcBoolType	IsTrading;
	///������Ʒ����
	TQdamFtdcInstrumentIDType	UnderlyingInstrID;
	///������Ʒ����
	TQdamFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///�ֲ�����
	TQdamFtdcPositionTypeType	PositionType;
	///ִ�м�
	TQdamFtdcPriceType	StrikePrice;
	///��Ȩ����
	TQdamFtdcOptionsTypeType	OptionsType;
	///����
	TQdamFtdcRatioType	ExchangeRate;
	///��Ʒ����
	TQdamFtdcProductClassType	ProductClass;
	///��Ȩ��Ȩ��ʽ
	TQdamFtdcOptionsModeType	OptionsMode;
	///��֤���㷨����
	TQdamFtdcMarginCombTypeType	MarginCombType;
} CQdamFtdcRspInstrumentField;

///Ͷ�����ʽ��ѯ
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
} CQdamFtdcQryInvestorAccountField;

///Ͷ�����ʽ�Ӧ��
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�ʽ��ʺ�
	TQdamFtdcAccountIDType	AccountID;
	///�ϴν���׼����
	TQdamFtdcMoneyType	PreBalance;
	///���տ����ʽ�
	TQdamFtdcMoneyType	PreAvailable;
	///�����
	TQdamFtdcMoneyType	Deposit;
	///������
	TQdamFtdcMoneyType	Withdraw;
	///ռ�ñ�֤��
	TQdamFtdcMoneyType	Margin;
	///��ȨȨ������֧
	TQdamFtdcMoneyType	Premium;
	///������
	TQdamFtdcMoneyType	Fee;
	///����ı�֤��
	TQdamFtdcMoneyType	FrozenMargin;
	///����Ȩ����
	TQdamFtdcMoneyType	FrozenPremium;
	///����������
	TQdamFtdcMoneyType	FrozenFee;
	///ƽ��ӯ��
	TQdamFtdcMoneyType	CloseProfit;
	///�ֲ�ӯ��
	TQdamFtdcMoneyType	PositionProfit;
	///�����ʽ�
	TQdamFtdcMoneyType	Available;
	///����׼����
	TQdamFtdcMoneyType	Balance;
	///��ͷռ�ñ�֤��
	TQdamFtdcMoneyType	LongMargin;
	///��ͷռ�ñ�֤��
	TQdamFtdcMoneyType	ShortMargin;
	///��ͷ����ı�֤��
	TQdamFtdcMoneyType	LongFrozenMargin;
	///��ͷ����ı�֤��
	TQdamFtdcMoneyType	ShortFrozenMargin;
	///��̬Ȩ��
	TQdamFtdcMoneyType	DynamicRights;
	///���ն�
	TQdamFtdcRatioType	Risk;
	///��������
	TQdamFtdcMoneyType	OtherFee;
	///��Ѻ���
	TQdamFtdcMoneyType	Mortgage;
	///����
	TQdamFtdcCurrencyType	Currency;
	///��ȡ�ʽ�
	TQdamFtdcMoneyType	WithdrawQuota;
	///������ʽ�
	TQdamFtdcMoneyType	FrozenCash;
	///�˻����
	TQdamFtdcMoneyType	CurrentBalance;
	///���ʲ�
	TQdamFtdcMoneyType	AssetBalance;
	///����ֵ
	TQdamFtdcMoneyType	MarketValue;
} CQdamFtdcRspInvestorAccountField;

///����Ͷ���߲�ѯ
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
} CQdamFtdcQryUserInvestorField;

///����Ͷ����Ӧ��
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�����û�����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///Ĭ���û�����
	TQdamFtdcUserIDType	NextUserID;
	///�Ƿ���µ�
	TQdamFtdcAdviceUserOrderModeType	OrderMode;
	///�Զ������ֶ�
	TQdamFtdcAdviceRunModeType	RunMode;
	///���������ߴ����ʾ��
	TQdamFtdcAdviceSwitchFlagType	AdviceSwitchFlag;
} CQdamFtdcRspUserInvestorField;

///Ͷ���߹�ϵ��ѯ
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
} CQdamFtdcQryInvestorRelationField;

///Ͷ���߹�ϵӦ��
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///��Ͷ���߱��
	TQdamFtdcInvestorIDType	ParentInvestorID;
	///˳����
	TQdamFtdcSequenceNoType	SpecifyNo;
} CQdamFtdcRspInvestorRelationField;

///��������ѯ����
typedef struct
{
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
} CQdamFtdcQryExchangeField;

///��������ѯӦ��
typedef struct
{
	///������
	TQdamFtdcTradingDayType	TradingDay;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///����������
	TQdamFtdcExchangeNameType	ExchangeName;
} CQdamFtdcRspExchangeField;

///Ͷ���ֲֲ߳�ѯ����
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
} CQdamFtdcQryInvestorPositionField;

///Ͷ���ֲֲ߳�ѯӦ��
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��������
	TQdamFtdcDirectionType	Direction;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///ռ�ñ�֤��
	TQdamFtdcMoneyType	UsedMargin;
	///�ֲܳ���
	TQdamFtdcVolumeType	Position;
	///�ֲֳܳɱ�
	TQdamFtdcPriceType	PositionCost;
	///��ʼ��ֲ���(���ղ���)
	TQdamFtdcVolumeType	YdPosition;
	///��ʼ���ճֲֳɱ�(���ղ���)
	TQdamFtdcMoneyType	YdPositionCost;
	///����ı�֤��
	TQdamFtdcMoneyType	FrozenMargin;
	///���ֶ���ֲ�
	TQdamFtdcVolumeType	FrozenPosition;
	///ƽ�ֶ���ֲ�
	TQdamFtdcVolumeType	FrozenClosing;
	///�ֲ�ӯ��
	TQdamFtdcMoneyType	PositionProfit;
	///�����Ȩ����
	TQdamFtdcMoneyType	FrozenPremium;
	///���һ�ʳɽ����
	TQdamFtdcTradeIDType	LastTradeID;
	///���һ�ʱ��ر������
	TQdamFtdcOrderLocalIDType	LastOrderLocalID;
	///�ֲֿܳ�ƽ������(����ƽ�ֶ���ֲ�)
	TQdamFtdcVolumeType	PositionClose;
	///��ֲֿ�ƽ������(����ƽ�ֶ���ֲ�)
	TQdamFtdcVolumeType	YdPositionClose;
	///��ֲ�ƽ�ֶ���ֲ�
	TQdamFtdcVolumeType	YdFrozenClosing;
	///���տ�������(����������)
	TQdamFtdcVolumeType	OpenVolume;
	///����ƽ������(������ֲֵ�ƽ��,����������)
	TQdamFtdcVolumeType	CloseVolume;
	///ƽ��ӯ��
	TQdamFtdcMoneyType	CloseProfit;
	///ִ�ж���ֲ�
	TQdamFtdcVolumeType	StrikeFrozenPosition;
	///����ִ�ж���ֲ�
	TQdamFtdcVolumeType	AbandonFrozenPosition;
	///�ɱ���
	TQdamFtdcPriceType	CostPrice;
	///���ֳɱ�
	TQdamFtdcMoneyType	OpenCost;
} CQdamFtdcRspInvestorPositionField;

///�û���ѯ
typedef struct
{
	///�����û�����
	TQdamFtdcUserIDType	StartUserID;
	///�����û�����
	TQdamFtdcUserIDType	EndUserID;
} CQdamFtdcQryUserField;

///�û�
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�û���¼����
	TQdamFtdcPasswordType	Password;
	///�Ƿ��Ծ
	TQdamFtdcIsActiveType	IsActive;
	///�û�����
	TQdamFtdcUserNameType	UserName;
	///�û�����
	TQdamFtdcUserTypeType	UserType;
	///Ӫҵ��
	TQdamFtdcDepartmentType	Department;
	///��Ȩ���ܼ�
	TQdamFtdcGrantFuncSetType	GrantFuncSet;
	///���������
	TQdamFtdcNumberType	MaxOnline;
	///IP��ַ
	TQdamFtdcIPAddressType	IPAddress;
	///�Ƿ������Ӳ�Ʒ
	TQdamFtdcBoolType	CheckProductInfo;
	///Mac��ַ
	TQdamFtdcMacAddressType	MacAddress;
	///�Ƿ���IP��MAC
	TQdamFtdcBoolType	CheckIPMacAddr;
	///�����½��������
	TQdamFtdcNumberType	LoginErrorLimit;
	///Ŀǰ�����½����
	TQdamFtdcNumberType	LoginErrorCount;
	///Ӳ�����к�
	TQdamFtdcHDSerialIDType	HDSerialID;
	///�����Ƿ����
	TQdamFtdcIsUpdateType	IsUpdate;
} CQdamFtdcRspUserField;

///Ͷ�����������ʲ�ѯ
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
} CQdamFtdcQryInvestorFeeField;

///Ͷ������������
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱���
	TQdamFtdcInvestorIDType	InvestorID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///���������Ѱ�����
	TQdamFtdcRatioType	OpenFeeRate;
	///���������Ѱ�����
	TQdamFtdcRatioType	OpenFeeAmt;
	///ƽ�������Ѱ�����
	TQdamFtdcRatioType	OffsetFeeRate;
	///ƽ�������Ѱ�����
	TQdamFtdcRatioType	OffsetFeeAmt;
	///ƽ��������Ѱ�����
	TQdamFtdcRatioType	OTFeeRate;
	///ƽ��������Ѱ�����
	TQdamFtdcRatioType	OTFeeAmt;
} CQdamFtdcRspInvestorFeeField;

///Ͷ���߱�֤���ʲ�ѯ
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
} CQdamFtdcQryInvestorMarginField;

///Ͷ���߱�֤����
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱���
	TQdamFtdcInvestorIDType	InvestorID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///��ͷռ�ñ�֤�𰴱���
	TQdamFtdcRatioType	LongMarginRate;
	///��ͷ��֤������
	TQdamFtdcRatioType	LongMarginAmt;
	///��ͷռ�ñ�֤�𰴱���
	TQdamFtdcRatioType	ShortMarginRate;
	///��ͷ��֤������
	TQdamFtdcRatioType	ShortMarginAmt;
} CQdamFtdcRspInvestorMarginField;

///Ͷ���߲�ѯ
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
} CQdamFtdcQryInvestorField;

///Ͷ����Ӧ��
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///Ͷ��������
	TQdamFtdcInvestorNameType	InvestorName;
	///Ͷ��������
	TQdamFtdcInvestorTypeType	InvestorType;
	///Ͷ��������
	TQdamFtdcInvestorIDType	GroupID;
	///Ͷ��������
	TQdamFtdcInvestorNameType	GroupName;
	///����
	TQdamFtdcAliasType	Alias;
	///��������
	TQdamFtdcLinkTypeType	LinkType;
	///�ʽ��˻����
	TQdamFtdcInvestorIDType	ParentInvestorID;
	///��¼����
	TQdamFtdcNumberType	LoginStatus;
	///�Ƿ�ʹ�þ��ֱֲ���,Ͷ���˻���Ч
	TQdamFtdcPositionTypeType	PositionType;
	///�Գɽ�����ʽ,�ʽ��˻���Ч
	TQdamFtdcSelfTradeAvoidTypeType	SelfTradeAvoidType;
	///����Ȩ��
	TQdamFtdcTradingRightType	TradingRight;
	///�Ƿ����ʽ�
	TQdamFtdcBoolType	CheckAccount;
	///�Ƿ���ֲ�
	TQdamFtdcBoolType	CheckPosition;
	///�����Ƿ񱨾�
	TQdamFtdcBoolType	OrderWarning;
	///�ʽ�ֲ��Ƿ��ϲ�
	TQdamFtdcBoolType	QryUpAccPosi;
	///Ͷ��ѡ���ʽ��˻�����
	TQdamFtdcDistributeTypeType	DistributeType;
} CQdamFtdcRspInvestorField;

///�˺ŷ���״����ѯ
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
} CQdamFtdcQryAccountRiskField;

///�˺ŷ���״��Ӧ��
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�ʽ��ʺ�
	TQdamFtdcAccountIDType	AccountID;
	///����׼����
	TQdamFtdcMoneyType	SetBalance;
	///���ֺ���
	TQdamFtdcMoneyType	OpenAvailable;
	///ƽ�ֺ���
	TQdamFtdcMoneyType	OffsetAvailable;
	///�˻�״̬
	TQdamFtdcAccountStatusType	AccountStatus;
	///��̬Ȩ��
	TQdamFtdcMoneyType	DynamicRights;
	///�˻�Ȩ��
	TQdamFtdcTradingRightType	TradingRight;
} CQdamFtdcRspAccountRiskField;

///�����û��Ự��ѯ
typedef struct
{
	///�����û�����
	TQdamFtdcUserIDType	StartUserID;
	///�����û�����
	TQdamFtdcUserIDType	EndUserID;
} CQdamFtdcQryUserSessionField;

///�����û��ỰӦ��
typedef struct
{
	///���͹�˾����
	TQdamFtdcBrokerIDType	BrokerID;
	///�����û�����
	TQdamFtdcUserIDType	UserID;
	///�����û�����
	TQdamFtdcUserTypeType	UserType;
	///�Ự���
	TQdamFtdcSessionIDType	SessionID;
	///ǰ�ñ��
	TQdamFtdcFrontIDType	FrontID;
	///��¼ʱ��
	TQdamFtdcTimeType	LoginTime;
	///IP��ַ
	TQdamFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TQdamFtdcMacAddressType	MacAddress;
	///�û��˲�Ʒ��Ϣ
	TQdamFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TQdamFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TQdamFtdcProtocolInfoType	ProtocolInfo;
	///Ӳ�����к�
	TQdamFtdcHDSerialIDType	HDSerialID;
} CQdamFtdcRspUserSessionField;

///�����ѯ
typedef struct
{
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
} CQdamFtdcQryMarketDataField;

///����Ӧ��
typedef struct
{
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///������
	TQdamFtdcTradingDayType	TradingDay;
	///�����
	TQdamFtdcPriceType	PreSettlementPrice;
	///������
	TQdamFtdcPriceType	PreClosePrice;
	///��ֲ���
	TQdamFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TQdamFtdcRatioType	PreDelta;
	///����
	TQdamFtdcPriceType	OpenPrice;
	///��߼�
	TQdamFtdcPriceType	HighestPrice;
	///��ͼ�
	TQdamFtdcPriceType	LowestPrice;
	///������
	TQdamFtdcPriceType	ClosePrice;
	///��ͣ���
	TQdamFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TQdamFtdcPriceType	LowerLimitPrice;
	///�����
	TQdamFtdcPriceType	SettlementPrice;
	///����ʵ��
	TQdamFtdcRatioType	CurrDelta;
	///���¼�
	TQdamFtdcPriceType	LastPrice;
	///����
	TQdamFtdcVolumeType	Volume;
	///�ɽ����
	TQdamFtdcMoneyType	Turnover;
	///�ֲ���
	TQdamFtdcLargeVolumeType	OpenInterest;
	///�����һ
	TQdamFtdcPriceType	BidPrice1;
	///������һ
	TQdamFtdcVolumeType	BidVolume1;
	///������һ
	TQdamFtdcPriceType	AskPrice1;
	///������һ
	TQdamFtdcVolumeType	AskVolume1;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TQdamFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TQdamFtdcMillisecType	UpdateMillisec;
} CQdamFtdcRspMarketDataField;

///��Ʒ��ѯ
typedef struct
{
	///��Ʒ����
	TQdamFtdcProductIDType	ProductID;
} CQdamFtdcQryProductField;

///��ƷӦ��
typedef struct
{
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Ʒ����
	TQdamFtdcProductIDType	ProductID;
	///Ͷ���߷��еĲ�Ʒ����
	TQdamFtdcProductNameType	ProductName;
	///����
	TQdamFtdcCurrencyType	Currency;
	///����
	TQdamFtdcRatioType	ExchangeRate;
} CQdamFtdcRspProductField;

///�ڲ�������Ϣ
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�޸��û����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///���
	TQdamFtdcSequenceNoType	SequenceNo;
	///�û��Զ�����
	TQdamFtdcCustomType	UserCustom;
} CQdamFtdcPingPongField;

///���ɽ���������ѯ����
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��������
	TQdamFtdcDirectionType	Direction;
	///��ƽ��־
	TQdamFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TQdamFtdcPriceType	LimitPrice;
} CQdamFtdcQryMaxVolumeField;

///���ɽ���������ѯӦ��
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��������
	TQdamFtdcDirectionType	Direction;
	///��ƽ��־
	TQdamFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TQdamFtdcPriceType	LimitPrice;
	///����
	TQdamFtdcVolumeType	Volume;
} CQdamFtdcRspMaxVolumeField;

///����������Ա��ѯ����
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///��¼���͹�˾���
	TQdamFtdcBrokerIDType	LogBrokerID;
	///��¼�û�����
	TQdamFtdcUserIDType	LogUserID;
	///�û��˽ӿڰ汾
	TQdamFtdcProductInfoType	ApiVersion;
	///�û��˳���汾
	TQdamFtdcProductInfoType	UserVersion;
} CQdamFtdcQryAdviceTraderField;

///����������Ա��ѯӦ��
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�����û�����
	TQdamFtdcUserIDType	RelationUserID;
	///�����û�����
	TQdamFtdcUserNameType	RelationUserName;
} CQdamFtdcRspAdviceTraderField;

///��ϳֲ���ϸ��ѯ����
typedef struct
{
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
} CQdamFtdcQryCmbPositionDetailField;

///��ϳֲ���ϸ��ѯӦ��
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///���Ⱥ�Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///���Ⱥ�Լ����
	TQdamFtdcInstrumentIDType	CmbInstrumentID;
	///�ɽ����
	TQdamFtdcTradeIDType	TradeID;
	///�������
	TQdamFtdcOrderSysIDType	OrderSysID;
	///��������
	TQdamFtdcDirectionType	Direction;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///�ֲ���
	TQdamFtdcVolumeType	Position;
	///���ȱ��
	TQdamFtdcNumberType	LegQty;
	///��������
	TQdamFtdcTradingDayType	TradingDay;
} CQdamFtdcRspCmbPositionDetailField;

///Ͷ���߽�������ѯ����
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///��������
	TQdamFtdcTradingDayType	TradingDay;
} CQdamFtdcQrySettlementInfoField;

///Ͷ���߽�������ѯӦ��
typedef struct
{
	///��������
	TQdamFtdcTradingDayType	TradingDay;
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///���
	TQdamFtdcSequenceNoType	SequenceNo;
	///��Ϣ����
	TQdamFtdcContentType	Content;
} CQdamFtdcRspSettlementInfoField;

///��ѯ�������ҳ
typedef struct
{
	///��������
	TQdamFtdcSessionIDType	ResultID;
	///�ܼ�¼��
	TQdamFtdcNumberType	Count;
	///��ҳ��
	TQdamFtdcNumberType	Pages;
	///ʣ��ҳ��
	TQdamFtdcNumberType	Remain;
} CQdamFtdcQryResultPageField;

///��ѯ�ֲ���ϸ����
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///���Ⱥ�Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
} CQdamFtdcQryPositionDetailField;

///��ѯ�ֲ���ϸӦ��
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///��������
	TQdamFtdcDirectionType	Direction;
	///��������
	TQdamFtdcDateType	OpenDate;
	///�ɽ����
	TQdamFtdcTradeIDType	TradeID;
	///����
	TQdamFtdcVolumeType	Volume;
	///���ּ�
	TQdamFtdcMoneyType	OpenPrice;
	///������
	TQdamFtdcDateType	TradingDay;
	///��������
	TQdamFtdcTradeTypeType	TradeType;
	///��Ϻ�Լ����
	TQdamFtdcInstrumentIDType	CombInstrumentID;
	///���ն���ƽ��ӯ��
	TQdamFtdcMoneyType	CloseProfitByDate;
	///��ʶԳ�ƽ��ӯ��
	TQdamFtdcMoneyType	CloseProfitByTrade;
	///���ն��гֲ�ӯ��
	TQdamFtdcMoneyType	PositionProfitByDate;
	///��ʶԳ�ֲ�ӯ��
	TQdamFtdcMoneyType	PositionProfitByTrade;
	///Ͷ���߱�֤��
	TQdamFtdcMoneyType	Margin;
	///��������֤��
	TQdamFtdcMoneyType	ExchMargin;
	///��֤����
	TQdamFtdcMoneyType	MarginRateByMoney;
	///��֤����(������)
	TQdamFtdcMoneyType	MarginRateByVolume;
	///������
	TQdamFtdcPriceType	LastSettlementPrice;
	///�����
	TQdamFtdcPriceType	SettlementPrice;
	///ƽ����
	TQdamFtdcVolumeType	CloseVolume;
	///ƽ�ֽ��
	TQdamFtdcMoneyType	CloseAmount;
	///������
	TQdamFtdcSettlementIDType	SettlementID;
	///Ͷ�ʵ�Ԫ����
	TQdamFtdcInvestUnitIDType	InvestUnitID;
	///�ֲ���ϸ���
	TQdamFtdcNumberType	SeqNum;
	///�û��Զ�����
	TQdamFtdcCustomType	UserCustom;
} CQdamFtdcRspPositionDetailField;

///ѯ�۲�ѯ
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
} CQdamFtdcQryForQuoteField;

///ѯ�۲�ѯӦ��
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///�û����ر�����
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�û��Զ�����
	TQdamFtdcCustomType	UserCustom;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///���ر������
	TQdamFtdcOrderLocalIDType	OrderLocalID;
	///ѯ��״̬
	TQdamFtdcForQuoteStatusTypeType	ForQuoteStatus;
	///������
	TQdamFtdcDateType	TradingDay;
	///����ʱ��
	TQdamFtdcTimeType	InsertTime;
} CQdamFtdcForQuoteField;

///���۲�ѯ
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///ϵͳ�������
	TQdamFtdcOrderSysIDType	OrderSysID;
} CQdamFtdcQryQuoteField;

///Ͷ������Ȩ�������ʲ�ѯ
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
} CQdamFtdcQryInvestorOptionFeeField;

///Ͷ������Ȩ��������
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱���
	TQdamFtdcInvestorIDType	InvestorID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///���������Ѱ�����
	TQdamFtdcRatioType	OpenFeeRate;
	///���������Ѱ�����
	TQdamFtdcRatioType	OpenFeeAmt;
	///ƽ�������Ѱ�����
	TQdamFtdcRatioType	OffsetFeeRate;
	///ƽ�������Ѱ�����
	TQdamFtdcRatioType	OffsetFeeAmt;
	///ƽ��������Ѱ�����
	TQdamFtdcRatioType	OTFeeRate;
	///ƽ��������Ѱ�����
	TQdamFtdcRatioType	OTFeeAmt;
	///ִ�������Ѱ�����
	TQdamFtdcRatioType	StrikeFeeRate;
	///ִ�������Ѱ�����
	TQdamFtdcRatioType	StrikeFeeAmt;
} CQdamFtdcRspInvestorOptionFeeField;

///ִ�������ѯ
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdamFtdcUserIDType	UserID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�������
	TQdamFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
} CQdamFtdcQryExecOrderField;

///Ͷ����֪ͨ
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///Ͷ��������
	TQdamFtdcInvestorNameType	InvestorName;
	///Ͷ��������
	TQdamFtdcInvestorTypeType	InvestorType;
	///Ͷ��������
	TQdamFtdcInvestorIDType	GroupID;
	///Ͷ��������
	TQdamFtdcInvestorNameType	GroupName;
	///����
	TQdamFtdcAliasType	Alias;
	///��������
	TQdamFtdcLinkTypeType	LinkType;
	///�ʽ��˻����
	TQdamFtdcInvestorIDType	ParentInvestorID;
	///��¼����
	TQdamFtdcNumberType	LoginStatus;
	///�Ƿ�ʹ�þ��ֱֲ���,Ͷ���˻���Ч
	TQdamFtdcPositionTypeType	PositionType;
	///�Գɽ�����ʽ,�ʽ��˻���Ч
	TQdamFtdcSelfTradeAvoidTypeType	SelfTradeAvoidType;
	///����Ȩ��
	TQdamFtdcTradingRightType	TradingRight;
	///�Ƿ����ʽ�
	TQdamFtdcBoolType	CheckAccount;
	///�Ƿ���ֲ�
	TQdamFtdcBoolType	CheckPosition;
	///�����Ƿ񱨾�
	TQdamFtdcBoolType	OrderWarning;
	///�ʽ�ֲ��Ƿ��ϲ�
	TQdamFtdcBoolType	QryUpAccPosi;
	///Ͷ��ѡ���ʽ��˻�����
	TQdamFtdcDistributeTypeType	DistributeType;
} CQdamFtdcRtnInvestorField;

///Ͷ�����ʽ�֪ͨ
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///�ʽ��ʺ�
	TQdamFtdcAccountIDType	AccountID;
	///�ϴν���׼����
	TQdamFtdcMoneyType	PreBalance;
	///���տ����ʽ�
	TQdamFtdcMoneyType	PreAvailable;
	///�����
	TQdamFtdcMoneyType	Deposit;
	///������
	TQdamFtdcMoneyType	Withdraw;
	///ռ�ñ�֤��
	TQdamFtdcMoneyType	Margin;
	///��ȨȨ������֧
	TQdamFtdcMoneyType	Premium;
	///������
	TQdamFtdcMoneyType	Fee;
	///����ı�֤��
	TQdamFtdcMoneyType	FrozenMargin;
	///����Ȩ����
	TQdamFtdcMoneyType	FrozenPremium;
	///����������
	TQdamFtdcMoneyType	FrozenFee;
	///ƽ��ӯ��
	TQdamFtdcMoneyType	CloseProfit;
	///�ֲ�ӯ��
	TQdamFtdcMoneyType	PositionProfit;
	///�����ʽ�
	TQdamFtdcMoneyType	Available;
	///����׼����
	TQdamFtdcMoneyType	Balance;
	///��ͷռ�ñ�֤��
	TQdamFtdcMoneyType	LongMargin;
	///��ͷռ�ñ�֤��
	TQdamFtdcMoneyType	ShortMargin;
	///��ͷ����ı�֤��
	TQdamFtdcMoneyType	LongFrozenMargin;
	///��ͷ����ı�֤��
	TQdamFtdcMoneyType	ShortFrozenMargin;
	///��̬Ȩ��
	TQdamFtdcMoneyType	DynamicRights;
	///���ն�
	TQdamFtdcRatioType	Risk;
	///��������
	TQdamFtdcMoneyType	OtherFee;
	///��Ѻ���
	TQdamFtdcMoneyType	Mortgage;
	///����
	TQdamFtdcCurrencyType	Currency;
	///��ȡ�ʽ�
	TQdamFtdcMoneyType	WithdrawQuota;
	///������ʽ�
	TQdamFtdcMoneyType	FrozenCash;
	///�˻����
	TQdamFtdcMoneyType	CurrentBalance;
	///���ʲ�
	TQdamFtdcMoneyType	AssetBalance;
	///����ֵ
	TQdamFtdcMoneyType	MarketValue;
} CQdamFtdcRtnInvestorAccountField;

///Ͷ���߷��Ȩ��֪ͨ
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��Ȩ��
	TQdamFtdcBoolType	BuyOpen;
	///��ƽȨ��
	TQdamFtdcBoolType	BuyClose;
	///����Ȩ��
	TQdamFtdcBoolType	SellOpen;
	///��ƽȨ��
	TQdamFtdcBoolType	SellClose;
	///��Ʒ����
	TQdamFtdcProductClassType	ProductClass;
} CQdamFtdcRtnInvestorTradingRightRiskField;

///Ͷ����Ȩ��֪ͨ
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��Լ����Ȩ��
	TQdamFtdcTradingRightType	TradingRight;
	///��Ʒ����
	TQdamFtdcProductClassType	ProductClass;
} CQdamFtdcRtnInvestorTradingRightField;

///���׻��ʲ�ѯ
typedef struct
{
	///����
	TQdamFtdcCurrencyType	InstCurrency;
	///����
	TQdamFtdcCurrencyType	AccCurrency;
} CQdamFtdcQryExchangeRateField;

///���׻���
typedef struct
{
	///����
	TQdamFtdcCurrencyType	InstCurrency;
	///����
	TQdamFtdcCurrencyType	AccCurrency;
	///����
	TQdamFtdcRatioType	ExchangeRate;
} CQdamFtdcRspExchangeRateField;

///���׻���֪ͨ
typedef struct
{
	///����
	TQdamFtdcCurrencyType	InstCurrency;
	///����
	TQdamFtdcCurrencyType	AccCurrency;
	///����
	TQdamFtdcRatioType	ExchangeRate;
} CQdamFtdcRtnExchangeRateField;

///����ϳֲ���ϸ��ѯ����
typedef struct
{
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
} CQdamFtdcQryCombPositionDetailField;

///����ϳֲ���ϸ��ѯӦ��
typedef struct
{
	///��������
	TQdamFtdcTradingDayType	TradingDay;
	///��������
	TQdamFtdcDateType	OpenDate;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///������
	TQdamFtdcSettlementIDType	SettlementID;
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///��ϱ��
	TQdamFtdcTradeIDType	ComTradeID;
	///�ɽ����
	TQdamFtdcTradeIDType	TradeID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///��������
	TQdamFtdcDirectionType	Direction;
	///�ֲ���
	TQdamFtdcVolumeType	Position;
	///Ͷ���߱�֤��
	TQdamFtdcMoneyType	Margin;
	///��������֤��
	TQdamFtdcMoneyType	ExchMargin;
	///��֤����
	TQdamFtdcMoneyType	MarginRateByMoney;
	///��֤����(������)
	TQdamFtdcMoneyType	MarginRateByVolume;
	///���ȱ��
	TQdamFtdcLegIDType	LegID;
	///���ȳ���
	TQdamFtdcLegMultipleType	LegMultiple;
	///��ϳֲֺ�Լ����
	TQdamFtdcInstrumentIDType	CmbInstrumentID;
	///�ɽ����
	TQdamFtdcTradeGroupIDType	TradeGroupID;
} CQdamFtdcRspCombPositionDetailField;

///Ͷ���ֲ߳�֪ͨ
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///��������
	TQdamFtdcDirectionType	Direction;
	///Ͷ���ױ���־
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///ռ�ñ�֤��
	TQdamFtdcMoneyType	UsedMargin;
	///�ֲܳ���
	TQdamFtdcVolumeType	Position;
	///�ֲֳܳɱ�
	TQdamFtdcPriceType	PositionCost;
	///��ʼ��ֲ���(���ղ���)
	TQdamFtdcVolumeType	YdPosition;
	///��ʼ���ճֲֳɱ�(���ղ���)
	TQdamFtdcMoneyType	YdPositionCost;
	///����ı�֤��
	TQdamFtdcMoneyType	FrozenMargin;
	///���ֶ���ֲ�
	TQdamFtdcVolumeType	FrozenPosition;
	///ƽ�ֶ���ֲ�
	TQdamFtdcVolumeType	FrozenClosing;
	///�ֲ�ӯ��
	TQdamFtdcMoneyType	PositionProfit;
	///�����Ȩ����
	TQdamFtdcMoneyType	FrozenPremium;
	///���һ�ʳɽ����
	TQdamFtdcTradeIDType	LastTradeID;
	///���һ�ʱ��ر������
	TQdamFtdcOrderLocalIDType	LastOrderLocalID;
	///�ֲֿܳ�ƽ������(����ƽ�ֶ���ֲ�)
	TQdamFtdcVolumeType	PositionClose;
	///��ֲֿ�ƽ������(����ƽ�ֶ���ֲ�)
	TQdamFtdcVolumeType	YdPositionClose;
	///��ֲ�ƽ�ֶ���ֲ�
	TQdamFtdcVolumeType	YdFrozenClosing;
	///���տ�������(����������)
	TQdamFtdcVolumeType	OpenVolume;
	///����ƽ������(������ֲֵ�ƽ��,����������)
	TQdamFtdcVolumeType	CloseVolume;
	///ƽ��ӯ��
	TQdamFtdcMoneyType	CloseProfit;
	///ִ�ж���ֲ�
	TQdamFtdcVolumeType	StrikeFrozenPosition;
	///����ִ�ж���ֲ�
	TQdamFtdcVolumeType	AbandonFrozenPosition;
	///�ɱ���
	TQdamFtdcPriceType	CostPrice;
	///���ֳɱ�
	TQdamFtdcMoneyType	OpenCost;
} CQdamFtdcRtnInvestorPositionField;

///��Ȩ�ԶԳ��ѯ
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱���
	TQdamFtdcInvestorIDType	InvestorID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��Ȩ�ԶԳ�������
	TQdamFtdcOrderSysIDType	OptionSelfCloseSysID;
	///��ʼʱ��
	TQdamFtdcTimeType	InsertTimeStart;
	///����ʱ��
	TQdamFtdcTimeType	InsertTimeEnd;
} CQdamFtdcQryOptionSelfCloseField;

///����֤ȯ��λ��ѯ
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
} CQdamFtdcQryLockPositionField;

///����֤ȯ��λ
typedef struct
{
	///���͹�˾���
	TQdamFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdamFtdcInvestorIDType	InvestorID;
	///��Ա���
	TQdamFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQdamFtdcClientIDType	ClientID;
	///��Լ����
	TQdamFtdcInstrumentIDType	InstrumentID;
	///����������
	TQdamFtdcExchangeIDType	ExchangeID;
	///��������
	TQdamFtdcVolumeType	Volume;
	///��������
	TQdamFtdcVolumeType	FrozenVolume;
	///������������
	TQdamFtdcVolumeType	TodayVolume;
} CQdamFtdcLockPositionField;

#endif
