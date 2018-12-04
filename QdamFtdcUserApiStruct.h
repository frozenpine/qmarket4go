/////////////////////////////////////////////////////////////////////////
///@system QuantDo Platform
///@company 上海量投网络科技有限公司
///@file QdamFtdcUserApitypedef struct.h
///@brief 定义了客户端接口使用的业务数据结构
///@history 
/////////////////////////////////////////////////////////////////////////

#ifndef QDAM_FTDCSTRUCT_H
#define QDAM_FTDCSTRUCT_H

#include "QdamFtdcUserApiDataType.h"

///响应信息
typedef struct
{
	///错误代码
	TQdamFtdcErrorIDType	ErrorID;
	///错误信息
	TQdamFtdcErrorMsgType	ErrorMsg;
} CQdamFtdcRspInfoField;

///系统用户登录请求
typedef struct
{
	///交易日
	TQdamFtdcDateType	TradingDay;
	///交易用户代码
	TQdamFtdcUserIDType	UserID;
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///密码
	TQdamFtdcPasswordType	Password;
	///用户端产品信息
	TQdamFtdcProductInfoType	UserProductInfo;
	///接口端产品信息
	TQdamFtdcProductInfoType	InterfaceProductInfo;
	///协议信息
	TQdamFtdcProtocolInfoType	ProtocolInfo;
	///IP地址
	TQdamFtdcIPAddressType	IPAddress;
	///Mac地址
	TQdamFtdcMacAddressType	MacAddress;
	///数据中心代码
	TQdamFtdcDataCenterIDType	DataCenterID;
	///动态密码
	TQdamFtdcPasswordType	OneTimePassword;
	///终端IP地址
	TQdamFtdcIPAddressType	ClientIPAddress;
	///授权编码
	TQdamFtdcAuthCodeType	AuthCode;
	///自定义字段
	TQdamFtdcFieldContentType	FieldContent;
} CQdamFtdcReqUserLoginField;

///系统用户登录应答
typedef struct
{
	///交易日
	TQdamFtdcDateType	TradingDay;
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TQdamFtdcUserIDType	UserID;
	///登录成功时间
	TQdamFtdcTimeType	LoginTime;
	///用户最大本地报单号
	TQdamFtdcUserOrderLocalIDType	MaxOrderLocalID;
	///交易系统名称
	TQdamFtdcTradingSystemNameType	TradingSystemName;
	///数据中心代码
	TQdamFtdcDataCenterIDType	DataCenterID;
	///会员私有流当前长度
	TQdamFtdcSequenceNoType	PrivateFlowSize;
	///交易员私有流当前长度
	TQdamFtdcSequenceNoType	UserFlowSize;
	///登录附加信息
	TQdamFtdcLoginInfoType	LoginInfo;
	///会话编号
	TQdamFtdcSessionIDType	SessionID;
	///前置编号
	TQdamFtdcFrontIDType	FrontID;
} CQdamFtdcRspUserLoginField;

///用户登出请求
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TQdamFtdcUserIDType	UserID;
} CQdamFtdcReqUserLogoutField;

///用户登出应答
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TQdamFtdcUserIDType	UserID;
} CQdamFtdcRspUserLogoutField;

///强制用户退出
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TQdamFtdcUserIDType	UserID;
} CQdamFtdcForceUserExitField;

///用户口令修改
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TQdamFtdcUserIDType	UserID;
	///旧密码
	TQdamFtdcPasswordType	OldPassword;
	///新密码
	TQdamFtdcPasswordType	NewPassword;
} CQdamFtdcUserPasswordUpdateField;

///输入报单
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///用户本地报单号
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TQdamFtdcCustomType	UserCustom;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///系统报单编号
	TQdamFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///报单类型
	TQdamFtdcOrderPriceTypeType	OrderPriceType;
	///买卖方向
	TQdamFtdcDirectionType	Direction;
	///开平标志
	TQdamFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///价格
	TQdamFtdcPriceType	LimitPrice;
	///数量
	TQdamFtdcVolumeType	Volume;
	///有效期类型
	TQdamFtdcTimeConditionType	TimeCondition;
	///GTD日期
	TQdamFtdcDateType	GTDDate;
	///成交量类型
	TQdamFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TQdamFtdcVolumeType	MinVolume;
	///止损价
	TQdamFtdcPriceType	StopPrice;
	///强平原因
	TQdamFtdcForceCloseReasonType	ForceCloseReason;
	///自动挂起标志
	TQdamFtdcBoolType	IsAutoSuspend;
	///业务单元
	TQdamFtdcBusinessUnitType	BusinessUnit;
	///业务类别
	TQdamFtdcBusinessTypeType	BusinessType;
} CQdamFtdcInputOrderField;

///报单操作
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///用户本地报单号
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TQdamFtdcCustomType	UserCustom;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///报单编号
	TQdamFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///本次撤单操作的本地编号
	TQdamFtdcUserOrderLocalIDType	UserOrderActionLocalID;
	///报单操作标志
	TQdamFtdcActionFlagType	ActionFlag;
	///价格
	TQdamFtdcPriceType	LimitPrice;
	///数量变化
	TQdamFtdcVolumeType	VolumeChange;
	///前置编号
	TQdamFtdcFrontIDType	FrontID;
	///会话编号
	TQdamFtdcSessionIDType	SessionID;
} CQdamFtdcOrderActionField;

///内存表导出
typedef struct
{
	///内存表名
	TQdamFtdcMemTableNameType	MemTableName;
} CQdamFtdcMemDBField;

///投资者资金帐户出入金请求
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///资金流水号
	TQdamFtdcAccountSeqNoType	AccountSeqNo;
	///资金帐号
	TQdamFtdcAccountIDType	AccountID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///金额
	TQdamFtdcMoneyType	Amount;
	///出入金方向
	TQdamFtdcAccountDirectionType	AmountDirection;
	///用户代码
	TQdamFtdcUserIDType	UserID;
} CQdamFtdcReqAccountDepositField;

///投资者资金帐户出入金应答
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///资金帐号
	TQdamFtdcAccountIDType	AccountID;
	///资金流水号
	TQdamFtdcAccountSeqNoType	AccountSeqNo;
	///金额
	TQdamFtdcMoneyType	Amount;
	///出入金方向
	TQdamFtdcAccountDirectionType	AmountDirection;
	///可用资金
	TQdamFtdcMoneyType	Available;
	///结算准备金
	TQdamFtdcMoneyType	Balance;
	///用户代码
	TQdamFtdcUserIDType	UserID;
} CQdamFtdcRspAccountDepositField;

///实时上场
typedef struct
{
	///DB命令序号
	TQdamFtdcCommandNoType	CommandNo;
	///操作日期
	TQdamFtdcDateType	CommandDate;
	///操作时间
	TQdamFtdcTimeType	CommandTime;
	///DB命令类型
	TQdamFtdcCommandTypeType	CommandType;
	///字段名
	TQdamFtdcFieldNameType	FieldName;
	///字段内容
	TQdamFtdcFieldContentType	FieldContent;
} CQdamFtdcTBCommandField;

///出入金结果
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///资金帐号
	TQdamFtdcAccountIDType	AccountID;
	///资金流水号
	TQdamFtdcAccountSeqNoType	AccountSeqNo;
	///金额
	TQdamFtdcMoneyType	Amount;
	///出入金方向
	TQdamFtdcAccountDirectionType	AmountDirection;
	///可用资金
	TQdamFtdcMoneyType	Available;
	///结算准备金
	TQdamFtdcMoneyType	Balance;
	///用户代码
	TQdamFtdcUserIDType	UserID;
} CQdamFtdcInvestorAccountDepositResField;

///合约状态
typedef struct
{
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///品种代码
	TQdamFtdcProductIDType	ProductID;
	///品种名称
	TQdamFtdcProductNameType	ProductName;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///合约名称
	TQdamFtdcInstrumentNameType	InstrumentName;
	///交割年份
	TQdamFtdcYearType	DeliveryYear;
	///交割月
	TQdamFtdcMonthType	DeliveryMonth;
	///限价单最大下单量
	TQdamFtdcVolumeType	MaxLimitOrderVolume;
	///限价单最小下单量
	TQdamFtdcVolumeType	MinLimitOrderVolume;
	///市价单最大下单量
	TQdamFtdcVolumeType	MaxMarketOrderVolume;
	///市价单最小下单量
	TQdamFtdcVolumeType	MinMarketOrderVolume;
	///数量乘数
	TQdamFtdcVolumeMultipleType	VolumeMultiple;
	///报价单位
	TQdamFtdcPriceTickType	PriceTick;
	///币种
	TQdamFtdcCurrencyType	Currency;
	///多头限仓
	TQdamFtdcVolumeType	LongPosLimit;
	///空头限仓
	TQdamFtdcVolumeType	ShortPosLimit;
	///跌停板价
	TQdamFtdcPriceType	LowerLimitPrice;
	///涨停板价
	TQdamFtdcPriceType	UpperLimitPrice;
	///昨结算
	TQdamFtdcPriceType	PreSettlementPrice;
	///合约交易状态
	TQdamFtdcInstrumentStatusType	InstrumentStatus;
	///创建日
	TQdamFtdcDateType	CreateDate;
	///上市日
	TQdamFtdcDateType	OpenDate;
	///到期日
	TQdamFtdcDateType	ExpireDate;
	///开始交割日
	TQdamFtdcDateType	StartDelivDate;
	///最后交割日
	TQdamFtdcDateType	EndDelivDate;
	///挂牌基准价
	TQdamFtdcPriceType	BasisPrice;
	///当前是否交易
	TQdamFtdcBoolType	IsTrading;
	///基础商品代码
	TQdamFtdcInstrumentIDType	UnderlyingInstrID;
	///基础商品乘数
	TQdamFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///持仓类型
	TQdamFtdcPositionTypeType	PositionType;
	///执行价
	TQdamFtdcPriceType	StrikePrice;
	///期权类型
	TQdamFtdcOptionsTypeType	OptionsType;
	///汇率
	TQdamFtdcRatioType	ExchangeRate;
	///产品类型
	TQdamFtdcProductClassType	ProductClass;
	///期权行权方式
	TQdamFtdcOptionsModeType	OptionsMode;
	///保证金算法类型
	TQdamFtdcMarginCombTypeType	MarginCombType;
} CQdamFtdcInstrumentStatusField;

///审批模式设置请求
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///自动或者手动
	TQdamFtdcAdviceRunModeType	RunMode;
} CQdamFtdcAdviceRunModeField;

///订阅合约状态
typedef struct
{
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///合约交易状态
	TQdamFtdcInstrumentStatusType	InstrumentStatus;
	///进入本状态时间
	TQdamFtdcTimeType	EnterTime;
	///进入本状态原因
	TQdamFtdcEnterReasonType	EnterReason;
} CQdamFtdcSubInstrumentStatusField;

///执行宣告输入
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///用户本地报单号
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TQdamFtdcCustomType	UserCustom;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///系统报单编号
	TQdamFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///开平标志
	TQdamFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///数量
	TQdamFtdcVolumeType	Volume;
	///业务单元
	TQdamFtdcBusinessUnitType	BusinessUnit;
	///执行类型
	TQdamFtdcActionTypeType	ActionType;
	///保留头寸申请的持仓方向
	TQdamFtdcPosiDirectionType	PosiDirection;
	///期权行权后是否保留期货头寸的标记
	TQdamFtdcReservePositionFlagTypeType	ReservePositionFlag;
	///期权行权后生成的头寸是否自动平仓
	TQdamFtdcCloseFlagTypeType	CloseFlag;
} CQdamFtdcInputExecOrderField;

///执行宣告操作
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///用户本地报单号
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TQdamFtdcCustomType	UserCustom;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///报单编号
	TQdamFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///本次撤单操作的本地编号
	TQdamFtdcUserOrderLocalIDType	UserOrderActionLocalID;
	///报单操作标志
	TQdamFtdcActionFlagType	ActionFlag;
	///价格
	TQdamFtdcPriceType	LimitPrice;
	///数量变化
	TQdamFtdcVolumeType	VolumeChange;
	///前置编号
	TQdamFtdcFrontIDType	FrontID;
	///会话编号
	TQdamFtdcSessionIDType	SessionID;
} CQdamFtdcExecOrderActionField;

///询价录入
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///用户本地报单号
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TQdamFtdcCustomType	UserCustom;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///本地报单编号
	TQdamFtdcOrderLocalIDType	OrderLocalID;
} CQdamFtdcInputForQuoteField;

///报价录入
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///用户本地报单号
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TQdamFtdcCustomType	UserCustom;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///系统报单编号
	TQdamFtdcOrderSysIDType	OrderSysID;
	///应价编号
	TQdamFtdcOrderSysIDType	ForQuoteSysID;
	///卖价格
	TQdamFtdcPriceType	AskPrice;
	///卖数量
	TQdamFtdcVolumeType	AskVolume;
	///卖开平标志
	TQdamFtdcOffsetFlagType	AskOffsetFlag;
	///卖投机套保标志
	TQdamFtdcHedgeFlagType	AskHedgeFlag;
	///买价格
	TQdamFtdcPriceType	BidPrice;
	///买数量
	TQdamFtdcVolumeType	BidVolume;
	///买开平标志
	TQdamFtdcOffsetFlagType	BidOffsetFlag;
	///买投机套保标志
	TQdamFtdcHedgeFlagType	BidHedgeFlag;
	///业务单元
	TQdamFtdcBusinessUnitType	BusinessUnit;
	///买方本地报单编号
	TQdamFtdcUserOrderLocalIDType	BidOrderRef;
	///卖方本地报单编号
	TQdamFtdcUserOrderLocalIDType	AskOrderRef;
} CQdamFtdcInputQuoteField;

///报价操作
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///用户本地报单号
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TQdamFtdcCustomType	UserCustom;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///报单编号
	TQdamFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///本次撤单操作的本地编号
	TQdamFtdcUserOrderLocalIDType	UserOrderActionLocalID;
	///报单操作标志
	TQdamFtdcActionFlagType	ActionFlag;
	///价格
	TQdamFtdcPriceType	LimitPrice;
	///数量变化
	TQdamFtdcVolumeType	VolumeChange;
	///前置编号
	TQdamFtdcFrontIDType	FrontID;
	///会话编号
	TQdamFtdcSessionIDType	SessionID;
} CQdamFtdcQuoteActionField;

///期权自对冲录入
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编码
	TQdamFtdcInvestorIDType	InvestorID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///期权自对冲引用
	TQdamFtdcOrderRefType	OptionSelfCloseRef;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///数量
	TQdamFtdcVolumeType	Volume;
	///请求编号
	TQdamFtdcRequestIDType	RequestID;
	///业务单元
	TQdamFtdcBusinessUnitType	BusinessUnit;
	///投机套保标志
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///期权行权的头寸是否自对冲
	TQdamFtdcOptSelfCloseFlagType	OptSelfCloseFlag;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TQdamFtdcInvestUnitIDType	InvestUnitID;
	///资金帐号
	TQdamFtdcAccountIDType	AccountID;
	///币种
	TQdamFtdcCurrencyType	Currency;
	///客户代码
	TQdamFtdcClientIDType	ClientID;
	///下单IP地址
	TQdamFtdcIPAddressType	IPAddress;
	///下单MAC地址
	TQdamFtdcMacAddressType	MacAddress;
} CQdamFtdcInputOptionSelfCloseField;

///期权自对冲操作
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编码
	TQdamFtdcInvestorIDType	InvestorID;
	///期权自对冲操作引用
	TQdamFtdcOrderActionRefType	OptionSelfCloseActionRef;
	///期权自对冲引用
	TQdamFtdcOrderRefType	OptionSelfCloseRef;
	///请求编号
	TQdamFtdcRequestIDType	RequestID;
	///前置编号
	TQdamFtdcFrontIDType	FrontID;
	///会话编号
	TQdamFtdcSessionIDType	SessionID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///期权自对冲操作编号
	TQdamFtdcOrderSysIDType	OptionSelfCloseSysID;
	///报单操作标志
	TQdamFtdcActionFlagType	ActionFlag;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///投资单元代码
	TQdamFtdcInvestUnitIDType	InvestUnitID;
	///下单IP地址
	TQdamFtdcIPAddressType	IPAddress;
	///下单MAC地址
	TQdamFtdcMacAddressType	MacAddress;
} CQdamFtdcOptionSelfCloseActionField;

///席位状态切换
typedef struct
{
	///使用哪个通道下单
	TQdamFtdcNumberType	APIID;
	///下单席位号
	TQdamFtdcSeatIDType	SeatID;
	///席位状态方向
	TQdamFtdcSeatDirectionType	SeatDirection;
} CQdamFtdcChangeSeatStatusField;

///锁定录入
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///用户本地报单号
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TQdamFtdcCustomType	UserCustom;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///数量
	TQdamFtdcVolumeType	Volume;
	///锁定类型
	TQdamFtdcLockTypeType	LockType;
	///业务单元
	TQdamFtdcBusinessUnitType	BusinessUnit;
} CQdamFtdcInputLockField;

///行情基础属性
typedef struct
{
	///交易日
	TQdamFtdcTradingDayType	TradingDay;
	///昨结算
	TQdamFtdcPriceType	PreSettlementPrice;
	///昨收盘
	TQdamFtdcPriceType	PreClosePrice;
	///昨持仓量
	TQdamFtdcLargeVolumeType	PreOpenInterest;
	///昨虚实度
	TQdamFtdcRatioType	PreDelta;
} CQdamFtdcMarketDataBaseField;

///行情静态属性
typedef struct
{
	///今开盘
	TQdamFtdcPriceType	OpenPrice;
	///最高价
	TQdamFtdcPriceType	HighestPrice;
	///最低价
	TQdamFtdcPriceType	LowestPrice;
	///今收盘
	TQdamFtdcPriceType	ClosePrice;
	///涨停板价
	TQdamFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TQdamFtdcPriceType	LowerLimitPrice;
	///今结算
	TQdamFtdcPriceType	SettlementPrice;
	///今虚实度
	TQdamFtdcRatioType	CurrDelta;
} CQdamFtdcMarketDataStaticField;

///行情最新成交属性
typedef struct
{
	///最新价
	TQdamFtdcPriceType	LastPrice;
	///数量
	TQdamFtdcVolumeType	Volume;
	///成交金额
	TQdamFtdcMoneyType	Turnover;
	///持仓量
	TQdamFtdcLargeVolumeType	OpenInterest;
} CQdamFtdcMarketDataLastMatchField;

///行情最优价属性
typedef struct
{
	///申买价一
	TQdamFtdcPriceType	BidPrice1;
	///申买量一
	TQdamFtdcVolumeType	BidVolume1;
	///申卖价一
	TQdamFtdcPriceType	AskPrice1;
	///申卖量一
	TQdamFtdcVolumeType	AskVolume1;
} CQdamFtdcMarketDataBestPriceField;

///行情申买二、三属性
typedef struct
{
	///申买价二
	TQdamFtdcPriceType	BidPrice2;
	///申买量二
	TQdamFtdcVolumeType	BidVolume2;
	///申买价三
	TQdamFtdcPriceType	BidPrice3;
	///申买量三
	TQdamFtdcVolumeType	BidVolume3;
} CQdamFtdcMarketDataBid23Field;

///行情申卖二、三属性
typedef struct
{
	///申卖价二
	TQdamFtdcPriceType	AskPrice2;
	///申卖量二
	TQdamFtdcVolumeType	AskVolume2;
	///申卖价三
	TQdamFtdcPriceType	AskPrice3;
	///申卖量三
	TQdamFtdcVolumeType	AskVolume3;
} CQdamFtdcMarketDataAsk23Field;

///行情申买四、五属性
typedef struct
{
	///申买价四
	TQdamFtdcPriceType	BidPrice4;
	///申买量四
	TQdamFtdcVolumeType	BidVolume4;
	///申买价五
	TQdamFtdcPriceType	BidPrice5;
	///申买量五
	TQdamFtdcVolumeType	BidVolume5;
} CQdamFtdcMarketDataBid45Field;

///行情申卖四、五属性
typedef struct
{
	///申卖价四
	TQdamFtdcPriceType	AskPrice4;
	///申卖量四
	TQdamFtdcVolumeType	AskVolume4;
	///申卖价五
	TQdamFtdcPriceType	AskPrice5;
	///申卖量五
	TQdamFtdcVolumeType	AskVolume5;
} CQdamFtdcMarketDataAsk45Field;

///行情更新时间属性
typedef struct
{
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///最后修改时间
	TQdamFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TQdamFtdcMillisecType	UpdateMillisec;
} CQdamFtdcMarketDataUpdateTimeField;

///深度行情
typedef struct
{
	///交易日
	TQdamFtdcTradingDayType	TradingDay;
	///昨结算
	TQdamFtdcPriceType	PreSettlementPrice;
	///昨收盘
	TQdamFtdcPriceType	PreClosePrice;
	///昨持仓量
	TQdamFtdcLargeVolumeType	PreOpenInterest;
	///昨虚实度
	TQdamFtdcRatioType	PreDelta;
	///今开盘
	TQdamFtdcPriceType	OpenPrice;
	///最高价
	TQdamFtdcPriceType	HighestPrice;
	///最低价
	TQdamFtdcPriceType	LowestPrice;
	///今收盘
	TQdamFtdcPriceType	ClosePrice;
	///涨停板价
	TQdamFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TQdamFtdcPriceType	LowerLimitPrice;
	///今结算
	TQdamFtdcPriceType	SettlementPrice;
	///今虚实度
	TQdamFtdcRatioType	CurrDelta;
	///最新价
	TQdamFtdcPriceType	LastPrice;
	///数量
	TQdamFtdcVolumeType	Volume;
	///成交金额
	TQdamFtdcMoneyType	Turnover;
	///持仓量
	TQdamFtdcLargeVolumeType	OpenInterest;
	///申买价一
	TQdamFtdcPriceType	BidPrice1;
	///申买量一
	TQdamFtdcVolumeType	BidVolume1;
	///申卖价一
	TQdamFtdcPriceType	AskPrice1;
	///申卖量一
	TQdamFtdcVolumeType	AskVolume1;
	///申买价二
	TQdamFtdcPriceType	BidPrice2;
	///申买量二
	TQdamFtdcVolumeType	BidVolume2;
	///申买价三
	TQdamFtdcPriceType	BidPrice3;
	///申买量三
	TQdamFtdcVolumeType	BidVolume3;
	///申卖价二
	TQdamFtdcPriceType	AskPrice2;
	///申卖量二
	TQdamFtdcVolumeType	AskVolume2;
	///申卖价三
	TQdamFtdcPriceType	AskPrice3;
	///申卖量三
	TQdamFtdcVolumeType	AskVolume3;
	///申买价四
	TQdamFtdcPriceType	BidPrice4;
	///申买量四
	TQdamFtdcVolumeType	BidVolume4;
	///申买价五
	TQdamFtdcPriceType	BidPrice5;
	///申买量五
	TQdamFtdcVolumeType	BidVolume5;
	///申卖价四
	TQdamFtdcPriceType	AskPrice4;
	///申卖量四
	TQdamFtdcVolumeType	AskVolume4;
	///申卖价五
	TQdamFtdcPriceType	AskPrice5;
	///申卖量五
	TQdamFtdcVolumeType	AskVolume5;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///最后修改时间
	TQdamFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TQdamFtdcMillisecType	UpdateMillisec;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///总卖出数量
	TQdamFtdcVolumeType	VolumeAskLot;
	///总买入数量
	TQdamFtdcVolumeType	VolumeBidLot;
	///合约状态
	TQdamFtdcInstrumentStatusType	InstrumentStatus;
	///申卖价六
	TQdamFtdcPriceType	AskPrice6;
	///申卖量六
	TQdamFtdcVolumeType	AskVolume6;
	///申卖价七
	TQdamFtdcPriceType	AskPrice7;
	///申卖量七
	TQdamFtdcVolumeType	AskVolume7;
	///申卖价八
	TQdamFtdcPriceType	AskPrice8;
	///申卖量八
	TQdamFtdcVolumeType	AskVolume8;
	///申卖价九
	TQdamFtdcPriceType	AskPrice9;
	///申卖量九
	TQdamFtdcVolumeType	AskVolume9;
	///申买价六
	TQdamFtdcPriceType	BidPrice6;
	///申买量六
	TQdamFtdcVolumeType	BidVolume6;
	///申买价七
	TQdamFtdcPriceType	BidPrice7;
	///申买量七
	TQdamFtdcVolumeType	BidVolume7;
	///申买价八
	TQdamFtdcPriceType	BidPrice8;
	///申买量八
	TQdamFtdcVolumeType	BidVolume8;
	///申买价九
	TQdamFtdcPriceType	BidPrice9;
	///申买量九
	TQdamFtdcVolumeType	BidVolume9;
	///申卖价十
	TQdamFtdcPriceType	AskPrice10;
	///申卖量十
	TQdamFtdcVolumeType	AskVolume10;
	///申买价十
	TQdamFtdcPriceType	BidPrice10;
	///申买量十
	TQdamFtdcVolumeType	BidVolume10;
} CQdamFtdcDepthMarketDataField;

///订阅合约的相关信息
typedef struct
{
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
} CQdamFtdcSpecificInstrumentField;

///投资者权限
typedef struct
{
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///是否使用净持仓报单,投顾账户有效
	TQdamFtdcPositionTypeType	PositionType;
	///自成交处理方式,资金账户有效
	TQdamFtdcSelfTradeAvoidTypeType	SelfTradeAvoidType;
	///交易权限
	TQdamFtdcTradingRightType	TradingRight;
	///是否检查资金
	TQdamFtdcBoolType	CheckAccount;
	///是否检查持仓
	TQdamFtdcBoolType	CheckPosition;
	///报单是否报警
	TQdamFtdcBoolType	OrderWarning;
	///资金持仓是否上查
	TQdamFtdcBoolType	QryUpAccPosi;
	///投顾选择资金账户类型
	TQdamFtdcDistributeTypeType	DistributeType;
} CQdamFtdcInvestorRightField;

///交易所代码
typedef struct
{
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
} CQdamFtdcMarketDataExchangeIDField;

///共享内存行情查询
typedef struct
{
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///IP地址
	TQdamFtdcIPAddressType	IPAddress;
	///订阅号
	TQdamFtdcTopicIDType	TopicID;
} CQdamFtdcShmDepthMarketDataField;

///TOPIC查询
typedef struct
{
	///订阅号
	TQdamFtdcTopicIDType	TopicID;
} CQdamFtdcTopicSearchField;

///分价行情
typedef struct
{
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TQdamFtdcDirectionType	Direction;
	///价格
	TQdamFtdcPriceType	Price;
	///数量
	TQdamFtdcVolumeType	Volume;
	///最后修改时间
	TQdamFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TQdamFtdcMillisecType	UpdateMillisec;
} CQdamFtdcMBLMarketDataField;

///套利合约买卖总量
typedef struct
{
	///总卖出数量
	TQdamFtdcVolumeType	VolumeAskLot;
	///总买入数量
	TQdamFtdcVolumeType	VolumeBidLot;
} CQdamFtdcMarketDataCMBVolumeField;

///合约状态
typedef struct
{
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///合约交易状态
	TQdamFtdcInstrumentStatusType	InstrumentStatus;
} CQdamFtdcQmdInstrumentStateField;

///订阅合约的相关信息
typedef struct
{
	///合约代码
	TQdamFtdcSubInstrumentIDType	InstrumentID;
} CQdamFtdcSubSpecificInstrumentField;

///行情申卖六七属性
typedef struct
{
	///申卖价六
	TQdamFtdcPriceType	AskPrice6;
	///申卖量六
	TQdamFtdcVolumeType	AskVolume6;
	///申卖价七
	TQdamFtdcPriceType	AskPrice7;
	///申卖量七
	TQdamFtdcVolumeType	AskVolume7;
} CQdamFtdcMarketDataAsk67Field;

///行情申卖八九属性
typedef struct
{
	///申卖价八
	TQdamFtdcPriceType	AskPrice8;
	///申卖量八
	TQdamFtdcVolumeType	AskVolume8;
	///申卖价九
	TQdamFtdcPriceType	AskPrice9;
	///申卖量九
	TQdamFtdcVolumeType	AskVolume9;
} CQdamFtdcMarketDataAsk89Field;

///行情申买六七属性
typedef struct
{
	///申买价六
	TQdamFtdcPriceType	BidPrice6;
	///申买量六
	TQdamFtdcVolumeType	BidVolume6;
	///申买价七
	TQdamFtdcPriceType	BidPrice7;
	///申买量七
	TQdamFtdcVolumeType	BidVolume7;
} CQdamFtdcMarketDataBid67Field;

///行情申买八九属性
typedef struct
{
	///申买价八
	TQdamFtdcPriceType	BidPrice8;
	///申买量八
	TQdamFtdcVolumeType	BidVolume8;
	///申买价九
	TQdamFtdcPriceType	BidPrice9;
	///申买量九
	TQdamFtdcVolumeType	BidVolume9;
} CQdamFtdcMarketDataBid89Field;

///行情申买申卖十属性
typedef struct
{
	///申卖价十
	TQdamFtdcPriceType	AskPrice10;
	///申卖量十
	TQdamFtdcVolumeType	AskVolume10;
	///申买价十
	TQdamFtdcPriceType	BidPrice10;
	///申买量十
	TQdamFtdcVolumeType	BidVolume10;
} CQdamFtdcMarketDataAskBid10Field;

///行情合约状态
typedef struct
{
	///合约状态
	TQdamFtdcInstrumentStatusType	InstrumentStatus;
} CQdamFtdcMarketDataInstrumentStatusField;

///成交
typedef struct
{
	///交易日
	TQdamFtdcTradingDayType	TradingDay;
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///用户本地报单号
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TQdamFtdcCustomType	UserCustom;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///成交编号
	TQdamFtdcTradeIDType	TradeID;
	///报单编号
	TQdamFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TQdamFtdcDirectionType	Direction;
	///开平标志
	TQdamFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///成交价格
	TQdamFtdcPriceType	TradePrice;
	///成交数量
	TQdamFtdcVolumeType	TradeVolume;
	///成交时间
	TQdamFtdcTimeType	TradeTime;
	///清算会员编号
	TQdamFtdcParticipantIDType	ClearingPartID;
	///成交金额
	TQdamFtdcMoneyType	TradeAmnt;
	///交易类型
	TQdamFtdcTradeTypeType	TradeType;
	///营业部代码
	TQdamFtdcBranchIDType	BranchID;
	///营业部名称
	TQdamFtdcBranchNameType	BranchName;
} CQdamFtdcTradeField;

///报单
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///用户本地报单号
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TQdamFtdcCustomType	UserCustom;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///系统报单编号
	TQdamFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///报单类型
	TQdamFtdcOrderPriceTypeType	OrderPriceType;
	///买卖方向
	TQdamFtdcDirectionType	Direction;
	///开平标志
	TQdamFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///价格
	TQdamFtdcPriceType	LimitPrice;
	///数量
	TQdamFtdcVolumeType	Volume;
	///有效期类型
	TQdamFtdcTimeConditionType	TimeCondition;
	///GTD日期
	TQdamFtdcDateType	GTDDate;
	///成交量类型
	TQdamFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TQdamFtdcVolumeType	MinVolume;
	///止损价
	TQdamFtdcPriceType	StopPrice;
	///强平原因
	TQdamFtdcForceCloseReasonType	ForceCloseReason;
	///自动挂起标志
	TQdamFtdcBoolType	IsAutoSuspend;
	///业务单元
	TQdamFtdcBusinessUnitType	BusinessUnit;
	///业务类别
	TQdamFtdcBusinessTypeType	BusinessType;
	///交易日
	TQdamFtdcTradingDayType	TradingDay;
	///插入时间
	TQdamFtdcTimeType	InsertTime;
	///报单来源
	TQdamFtdcOrderSourceType	OrderSource;
	///报单状态
	TQdamFtdcOrderStatusType	OrderStatus;
	///撤销时间
	TQdamFtdcTimeType	CancelTime;
	///撤单用户编号
	TQdamFtdcUserIDType	CancelUserID;
	///已经成交数量
	TQdamFtdcVolumeType	VolumeTraded;
	///队列剩余数量
	TQdamFtdcVolumeType	VolumeRemain;
	///已经撤单数量
	TQdamFtdcVolumeType	VolumeCancled;
	///错误代码
	TQdamFtdcErrorIDType	ErrorID;
	///错误信息
	TQdamFtdcErrorMsgType	ErrorMsg;
	///比上次增加的撤单数量
	TQdamFtdcVolumeType	VolumeIncCancled;
	///比上次增加的成交数量
	TQdamFtdcVolumeType	VolumeIncTraded;
	///资金帐号
	TQdamFtdcAccountIDType	AccountID;
	///前置编号
	TQdamFtdcFrontIDType	FrontID;
	///会话编号
	TQdamFtdcSessionIDType	SessionID;
	///请求编号
	TQdamFtdcRequestIDType	RequestID;
	///每手手续费
	TQdamFtdcMoneyType	EachFee;
	///每手保证金
	TQdamFtdcMoneyType	EachMargin;
	///每手期权权利金收支
	TQdamFtdcMoneyType	EachPremium;
	///下单IP地址
	TQdamFtdcIPAddressType	IPAddress;
	///下单MAC地址
	TQdamFtdcMacAddressType	MacAddress;
	///营业部代码
	TQdamFtdcBranchIDType	BranchID;
	///记录编号
	TQdamFtdcSequenceNoType	RecNum;
	///硬盘序列号
	TQdamFtdcHDSerialIDType	HDSerialID;
	///营业部名称
	TQdamFtdcBranchNameType	BranchName;
} CQdamFtdcOrderField;

///数据流回退
typedef struct
{
	///序列系列号
	TQdamFtdcSequenceSeriesType	SequenceSeries;
	///交易日
	TQdamFtdcDateType	TradingDay;
	///数据中心代码
	TQdamFtdcDataCenterIDType	DataCenterID;
	///回退起始序列号
	TQdamFtdcSequenceNoType	StartSequenceNo;
	///回退结束序列号
	TQdamFtdcSequenceNoType	EndSequenceNo;
} CQdamFtdcFlowMessageCancelField;

///信息分发
typedef struct
{
	///序列系列号
	TQdamFtdcSequenceSeriesType	SequenceSeries;
	///序列号
	TQdamFtdcSequenceNoType	SequenceNo;
} CQdamFtdcDisseminationField;

///警告消息通知
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///修改用户编号
	TQdamFtdcUserIDType	UserID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///累加次数
	TQdamFtdcTotalNumsType	Nums;
	///警告级别
	TQdamFtdcErrorLevelType	WarnLevel;
	///警告编号
	TQdamFtdcErrorIDType	WarnID;
	///警告信息
	TQdamFtdcLargeErrorMsgType	WarnMsg;
	///警告时间
	TQdamFtdcTimeType	WarnTime;
} CQdamFtdcMessageNotifyField;

///工作流指令通知
typedef struct
{
	///投顾用户代码
	TQdamFtdcUserIDType	InvestorAdvicer;
	///投资经理
	TQdamFtdcUserIDType	InvestorManager;
	///交易员
	TQdamFtdcUserIDType	UserTrader;
	///冻结数量
	TQdamFtdcVolumeType	VolumeFrozen;
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///用户本地报单号
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TQdamFtdcCustomType	UserCustom;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///系统报单编号
	TQdamFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///报单类型
	TQdamFtdcOrderPriceTypeType	OrderPriceType;
	///买卖方向
	TQdamFtdcDirectionType	Direction;
	///开平标志
	TQdamFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///价格
	TQdamFtdcPriceType	LimitPrice;
	///数量
	TQdamFtdcVolumeType	Volume;
	///有效期类型
	TQdamFtdcTimeConditionType	TimeCondition;
	///GTD日期
	TQdamFtdcDateType	GTDDate;
	///成交量类型
	TQdamFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TQdamFtdcVolumeType	MinVolume;
	///止损价
	TQdamFtdcPriceType	StopPrice;
	///强平原因
	TQdamFtdcForceCloseReasonType	ForceCloseReason;
	///自动挂起标志
	TQdamFtdcBoolType	IsAutoSuspend;
	///业务单元
	TQdamFtdcBusinessUnitType	BusinessUnit;
	///业务类别
	TQdamFtdcBusinessTypeType	BusinessType;
	///交易日
	TQdamFtdcTradingDayType	TradingDay;
	///插入时间
	TQdamFtdcTimeType	InsertTime;
	///报单来源
	TQdamFtdcOrderSourceType	OrderSource;
	///报单状态
	TQdamFtdcOrderStatusType	OrderStatus;
	///撤销时间
	TQdamFtdcTimeType	CancelTime;
	///撤单用户编号
	TQdamFtdcUserIDType	CancelUserID;
	///已经成交数量
	TQdamFtdcVolumeType	VolumeTraded;
	///队列剩余数量
	TQdamFtdcVolumeType	VolumeRemain;
	///已经撤单数量
	TQdamFtdcVolumeType	VolumeCancled;
	///错误代码
	TQdamFtdcErrorIDType	ErrorID;
	///错误信息
	TQdamFtdcErrorMsgType	ErrorMsg;
	///比上次增加的撤单数量
	TQdamFtdcVolumeType	VolumeIncCancled;
	///比上次增加的成交数量
	TQdamFtdcVolumeType	VolumeIncTraded;
	///资金帐号
	TQdamFtdcAccountIDType	AccountID;
	///前置编号
	TQdamFtdcFrontIDType	FrontID;
	///会话编号
	TQdamFtdcSessionIDType	SessionID;
	///请求编号
	TQdamFtdcRequestIDType	RequestID;
	///每手手续费
	TQdamFtdcMoneyType	EachFee;
	///每手保证金
	TQdamFtdcMoneyType	EachMargin;
	///每手期权权利金收支
	TQdamFtdcMoneyType	EachPremium;
	///下单IP地址
	TQdamFtdcIPAddressType	IPAddress;
	///下单MAC地址
	TQdamFtdcMacAddressType	MacAddress;
	///营业部代码
	TQdamFtdcBranchIDType	BranchID;
	///记录编号
	TQdamFtdcSequenceNoType	RecNum;
	///指令单用户信息
	TQdamFtdcAdviceUserInfoType	AdviceUserInfo;
	///硬盘序列号
	TQdamFtdcHDSerialIDType	HDSerialID;
	///营业部名称
	TQdamFtdcBranchNameType	BranchName;
} CQdamFtdcAdviceOrderField;

///执行宣告通知
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///用户本地报单号
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TQdamFtdcCustomType	UserCustom;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///系统报单编号
	TQdamFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///开平标志
	TQdamFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///数量
	TQdamFtdcVolumeType	Volume;
	///业务单元
	TQdamFtdcBusinessUnitType	BusinessUnit;
	///执行类型
	TQdamFtdcActionTypeType	ActionType;
	///保留头寸申请的持仓方向
	TQdamFtdcPosiDirectionType	PosiDirection;
	///期权行权后是否保留期货头寸的标记
	TQdamFtdcReservePositionFlagTypeType	ReservePositionFlag;
	///期权行权后生成的头寸是否自动平仓
	TQdamFtdcCloseFlagTypeType	CloseFlag;
	///执行结果
	TQdamFtdcExecResultTypeType	ExecResultType;
	///交易日
	TQdamFtdcTradingDayType	TradingDay;
	///插入时间
	TQdamFtdcTimeType	InsertTime;
	///报单来源
	TQdamFtdcOrderSourceType	OrderSource;
	///报单状态
	TQdamFtdcOrderStatusType	OrderStatus;
	///撤销时间
	TQdamFtdcTimeType	CancelTime;
	///撤单用户编号
	TQdamFtdcUserIDType	CancelUserID;
	///已经成交数量
	TQdamFtdcVolumeType	VolumeTraded;
	///队列剩余数量
	TQdamFtdcVolumeType	VolumeRemain;
	///已经撤单数量
	TQdamFtdcVolumeType	VolumeCancled;
	///错误代码
	TQdamFtdcErrorIDType	ErrorID;
	///错误信息
	TQdamFtdcErrorMsgType	ErrorMsg;
	///比上次增加的撤单数量
	TQdamFtdcVolumeType	VolumeIncCancled;
	///比上次增加的成交数量
	TQdamFtdcVolumeType	VolumeIncTraded;
	///资金帐号
	TQdamFtdcAccountIDType	AccountID;
	///前置编号
	TQdamFtdcFrontIDType	FrontID;
	///会话编号
	TQdamFtdcSessionIDType	SessionID;
	///请求编号
	TQdamFtdcRequestIDType	RequestID;
	///每手手续费
	TQdamFtdcMoneyType	EachFee;
	///每手保证金
	TQdamFtdcMoneyType	EachMargin;
	///每手期权权利金收支
	TQdamFtdcMoneyType	EachPremium;
	///下单IP地址
	TQdamFtdcIPAddressType	IPAddress;
	///下单MAC地址
	TQdamFtdcMacAddressType	MacAddress;
	///营业部代码
	TQdamFtdcBranchIDType	BranchID;
	///记录编号
	TQdamFtdcSequenceNoType	RecNum;
} CQdamFtdcExecOrderField;

///询价流通知
typedef struct
{
	///交易日
	TQdamFtdcDateType	TradingDay;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///询价编号
	TQdamFtdcOrderSysIDType	OrderSysID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///插入时间
	TQdamFtdcTimeType	InsertTime;
} CQdamFtdcForQuoteRspField;

///报价通知
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///用户本地报单号
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TQdamFtdcCustomType	UserCustom;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///系统报单编号
	TQdamFtdcOrderSysIDType	OrderSysID;
	///应价编号
	TQdamFtdcOrderSysIDType	ForQuoteSysID;
	///卖价格
	TQdamFtdcPriceType	AskPrice;
	///卖数量
	TQdamFtdcVolumeType	AskVolume;
	///卖开平标志
	TQdamFtdcOffsetFlagType	AskOffsetFlag;
	///卖投机套保标志
	TQdamFtdcHedgeFlagType	AskHedgeFlag;
	///买价格
	TQdamFtdcPriceType	BidPrice;
	///买数量
	TQdamFtdcVolumeType	BidVolume;
	///买开平标志
	TQdamFtdcOffsetFlagType	BidOffsetFlag;
	///买投机套保标志
	TQdamFtdcHedgeFlagType	BidHedgeFlag;
	///业务单元
	TQdamFtdcBusinessUnitType	BusinessUnit;
	///买方本地报单编号
	TQdamFtdcUserOrderLocalIDType	BidOrderRef;
	///卖方本地报单编号
	TQdamFtdcUserOrderLocalIDType	AskOrderRef;
	///交易日
	TQdamFtdcTradingDayType	TradingDay;
	///插入时间
	TQdamFtdcTimeType	InsertTime;
	///报单来源
	TQdamFtdcOrderSourceType	OrderSource;
	///报单状态
	TQdamFtdcOrderStatusType	OrderStatus;
	///撤销时间
	TQdamFtdcTimeType	CancelTime;
	///撤单用户编号
	TQdamFtdcUserIDType	CancelUserID;
	///已经成交数量
	TQdamFtdcVolumeType	VolumeTraded;
	///队列剩余数量
	TQdamFtdcVolumeType	VolumeRemain;
	///已经撤单数量
	TQdamFtdcVolumeType	VolumeCancled;
	///错误代码
	TQdamFtdcErrorIDType	ErrorID;
	///错误信息
	TQdamFtdcErrorMsgType	ErrorMsg;
	///比上次增加的撤单数量
	TQdamFtdcVolumeType	VolumeIncCancled;
	///比上次增加的成交数量
	TQdamFtdcVolumeType	VolumeIncTraded;
	///资金帐号
	TQdamFtdcAccountIDType	AccountID;
	///前置编号
	TQdamFtdcFrontIDType	FrontID;
	///会话编号
	TQdamFtdcSessionIDType	SessionID;
	///请求编号
	TQdamFtdcRequestIDType	RequestID;
	///每手手续费
	TQdamFtdcMoneyType	EachFee;
	///每手保证金
	TQdamFtdcMoneyType	EachMargin;
	///每手期权权利金收支
	TQdamFtdcMoneyType	EachPremium;
	///下单IP地址
	TQdamFtdcIPAddressType	IPAddress;
	///下单MAC地址
	TQdamFtdcMacAddressType	MacAddress;
	///营业部代码
	TQdamFtdcBranchIDType	BranchID;
	///记录编号
	TQdamFtdcSequenceNoType	RecNum;
	///买方系统报单编号
	TQdamFtdcOrderSysIDType	BidOrderSysID;
	///卖方系统报单编号
	TQdamFtdcOrderSysIDType	AskOrderSysID;
} CQdamFtdcQuoteField;

///期权自对冲
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编码
	TQdamFtdcInvestorIDType	InvestorID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///期权自对冲引用
	TQdamFtdcOrderRefType	OptionSelfCloseRef;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///数量
	TQdamFtdcVolumeType	Volume;
	///请求编号
	TQdamFtdcRequestIDType	RequestID;
	///业务单元
	TQdamFtdcBusinessUnitType	BusinessUnit;
	///投机套保标志
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///期权行权的头寸是否自对冲
	TQdamFtdcOptSelfCloseFlagType	OptSelfCloseFlag;
	///本地期权自对冲编号
	TQdamFtdcOrderLocalIDType	OptionSelfCloseLocalID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///会员编号
	TQdamFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQdamFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TQdamFtdcExchangeInstIDType	ExchangeInstID;
	///交易所交易员代码
	TQdamFtdcTraderIDType	TraderID;
	///安装编号
	TQdamFtdcInstallIDType	InstallID;
	///期权自对冲提交状态
	TQdamFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///报单提示序号
	TQdamFtdcSequenceNoType	NotifySequence;
	///交易日
	TQdamFtdcDateType	TradingDay;
	///结算编号
	TQdamFtdcSettlementIDType	SettlementID;
	///期权自对冲操作编号
	TQdamFtdcOrderSysIDType	OptionSelfCloseSysID;
	///报单日期
	TQdamFtdcDateType	InsertDate;
	///插入时间
	TQdamFtdcTimeType	InsertTime;
	///撤销时间
	TQdamFtdcTimeType	CancelTime;
	///自对冲结果
	TQdamFtdcExecResultTypeType	ExecResultType;
	///清算会员编号
	TQdamFtdcParticipantIDType	ClearingPartID;
	///序号
	TQdamFtdcSequenceNoType	SequenceNo;
	///前置编号
	TQdamFtdcFrontIDType	FrontID;
	///会话编号
	TQdamFtdcSessionIDType	SessionID;
	///用户端产品信息
	TQdamFtdcProductInfoType	UserProductInfo;
	///状态信息
	TQdamFtdcStatusMsgType	StatusMsg;
	///操作用户代码
	TQdamFtdcUserIDType	ActiveUserID;
	///经纪公司报单编号
	TQdamFtdcSequenceNoType	BrokerOptionSelfCloseSeq;
	///营业部编号
	TQdamFtdcBranchIDType	BranchID;
	///投资单元代码
	TQdamFtdcInvestUnitIDType	InvestUnitID;
	///资金帐号
	TQdamFtdcAccountIDType	AccountID;
	///币种
	TQdamFtdcCurrencyType	Currency;
	///下单IP地址
	TQdamFtdcIPAddressType	IPAddress;
	///下单MAC地址
	TQdamFtdcMacAddressType	MacAddress;
} CQdamFtdcOptionSelfCloseField;

///锁定
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///用户本地报单号
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TQdamFtdcCustomType	UserCustom;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///数量
	TQdamFtdcVolumeType	Volume;
	///锁定类型
	TQdamFtdcLockTypeType	LockType;
	///业务单元
	TQdamFtdcBusinessUnitType	BusinessUnit;
	///交易日
	TQdamFtdcTradingDayType	TradingDay;
	///锁定编号
	TQdamFtdcOrderSysIDType	LockSysID;
	///插入时间
	TQdamFtdcTimeType	InsertTime;
	///锁定状态
	TQdamFtdcOrderActionStatusType	LockStatus;
	///撤销时间
	TQdamFtdcTimeType	CancelTime;
	///资金帐号
	TQdamFtdcAccountIDType	AccountID;
	///前置编号
	TQdamFtdcFrontIDType	FrontID;
	///会话编号
	TQdamFtdcSessionIDType	SessionID;
	///请求编号
	TQdamFtdcRequestIDType	RequestID;
	///下单IP地址
	TQdamFtdcIPAddressType	IPAddress;
	///下单MAC地址
	TQdamFtdcMacAddressType	MacAddress;
	///营业部代码
	TQdamFtdcBranchIDType	BranchID;
	///错误代码
	TQdamFtdcErrorIDType	ErrorID;
	///错误信息
	TQdamFtdcErrorMsgType	ErrorMsg;
	///记录编号
	TQdamFtdcSequenceNoType	RecNum;
} CQdamFtdcLockField;

///报单查询
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///报单编号
	TQdamFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
} CQdamFtdcQryOrderField;

///成交查询
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///成交编号
	TQdamFtdcTradeIDType	TradeID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
} CQdamFtdcQryTradeField;

///合约查询
typedef struct
{
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///产品代码
	TQdamFtdcProductIDType	ProductID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
} CQdamFtdcQryInstrumentField;

///合约查询应答
typedef struct
{
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///品种代码
	TQdamFtdcProductIDType	ProductID;
	///品种名称
	TQdamFtdcProductNameType	ProductName;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///合约名称
	TQdamFtdcInstrumentNameType	InstrumentName;
	///交割年份
	TQdamFtdcYearType	DeliveryYear;
	///交割月
	TQdamFtdcMonthType	DeliveryMonth;
	///限价单最大下单量
	TQdamFtdcVolumeType	MaxLimitOrderVolume;
	///限价单最小下单量
	TQdamFtdcVolumeType	MinLimitOrderVolume;
	///市价单最大下单量
	TQdamFtdcVolumeType	MaxMarketOrderVolume;
	///市价单最小下单量
	TQdamFtdcVolumeType	MinMarketOrderVolume;
	///数量乘数
	TQdamFtdcVolumeMultipleType	VolumeMultiple;
	///报价单位
	TQdamFtdcPriceTickType	PriceTick;
	///币种
	TQdamFtdcCurrencyType	Currency;
	///多头限仓
	TQdamFtdcVolumeType	LongPosLimit;
	///空头限仓
	TQdamFtdcVolumeType	ShortPosLimit;
	///跌停板价
	TQdamFtdcPriceType	LowerLimitPrice;
	///涨停板价
	TQdamFtdcPriceType	UpperLimitPrice;
	///昨结算
	TQdamFtdcPriceType	PreSettlementPrice;
	///合约交易状态
	TQdamFtdcInstrumentStatusType	InstrumentStatus;
	///创建日
	TQdamFtdcDateType	CreateDate;
	///上市日
	TQdamFtdcDateType	OpenDate;
	///到期日
	TQdamFtdcDateType	ExpireDate;
	///开始交割日
	TQdamFtdcDateType	StartDelivDate;
	///最后交割日
	TQdamFtdcDateType	EndDelivDate;
	///挂牌基准价
	TQdamFtdcPriceType	BasisPrice;
	///当前是否交易
	TQdamFtdcBoolType	IsTrading;
	///基础商品代码
	TQdamFtdcInstrumentIDType	UnderlyingInstrID;
	///基础商品乘数
	TQdamFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///持仓类型
	TQdamFtdcPositionTypeType	PositionType;
	///执行价
	TQdamFtdcPriceType	StrikePrice;
	///期权类型
	TQdamFtdcOptionsTypeType	OptionsType;
	///汇率
	TQdamFtdcRatioType	ExchangeRate;
	///产品类型
	TQdamFtdcProductClassType	ProductClass;
	///期权行权方式
	TQdamFtdcOptionsModeType	OptionsMode;
	///保证金算法类型
	TQdamFtdcMarginCombTypeType	MarginCombType;
} CQdamFtdcRspInstrumentField;

///投资者资金查询
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
} CQdamFtdcQryInvestorAccountField;

///投资者资金应答
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///资金帐号
	TQdamFtdcAccountIDType	AccountID;
	///上次结算准备金
	TQdamFtdcMoneyType	PreBalance;
	///上日可用资金
	TQdamFtdcMoneyType	PreAvailable;
	///入金金额
	TQdamFtdcMoneyType	Deposit;
	///出金金额
	TQdamFtdcMoneyType	Withdraw;
	///占用保证金
	TQdamFtdcMoneyType	Margin;
	///期权权利金收支
	TQdamFtdcMoneyType	Premium;
	///手续费
	TQdamFtdcMoneyType	Fee;
	///冻结的保证金
	TQdamFtdcMoneyType	FrozenMargin;
	///冻结权利金
	TQdamFtdcMoneyType	FrozenPremium;
	///冻结手续费
	TQdamFtdcMoneyType	FrozenFee;
	///平仓盈亏
	TQdamFtdcMoneyType	CloseProfit;
	///持仓盈亏
	TQdamFtdcMoneyType	PositionProfit;
	///可用资金
	TQdamFtdcMoneyType	Available;
	///结算准备金
	TQdamFtdcMoneyType	Balance;
	///多头占用保证金
	TQdamFtdcMoneyType	LongMargin;
	///空头占用保证金
	TQdamFtdcMoneyType	ShortMargin;
	///多头冻结的保证金
	TQdamFtdcMoneyType	LongFrozenMargin;
	///空头冻结的保证金
	TQdamFtdcMoneyType	ShortFrozenMargin;
	///动态权益
	TQdamFtdcMoneyType	DynamicRights;
	///风险度
	TQdamFtdcRatioType	Risk;
	///其他费用
	TQdamFtdcMoneyType	OtherFee;
	///质押金额
	TQdamFtdcMoneyType	Mortgage;
	///币种
	TQdamFtdcCurrencyType	Currency;
	///可取资金
	TQdamFtdcMoneyType	WithdrawQuota;
	///冻结的资金
	TQdamFtdcMoneyType	FrozenCash;
	///账户余额
	TQdamFtdcMoneyType	CurrentBalance;
	///总资产
	TQdamFtdcMoneyType	AssetBalance;
	///总市值
	TQdamFtdcMoneyType	MarketValue;
} CQdamFtdcRspInvestorAccountField;

///可用投资者查询
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
} CQdamFtdcQryUserInvestorField;

///可用投资者应答
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TQdamFtdcUserIDType	UserID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///默认用户代码
	TQdamFtdcUserIDType	NextUserID;
	///是否可下单
	TQdamFtdcAdviceUserOrderModeType	OrderMode;
	///自动或者手动
	TQdamFtdcAdviceRunModeType	RunMode;
	///工作流断线处理标示符
	TQdamFtdcAdviceSwitchFlagType	AdviceSwitchFlag;
} CQdamFtdcRspUserInvestorField;

///投资者关系查询
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
} CQdamFtdcQryInvestorRelationField;

///投资者关系应答
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///父投资者编号
	TQdamFtdcInvestorIDType	ParentInvestorID;
	///顺序编号
	TQdamFtdcSequenceNoType	SpecifyNo;
} CQdamFtdcRspInvestorRelationField;

///交易所查询请求
typedef struct
{
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
} CQdamFtdcQryExchangeField;

///交易所查询应答
typedef struct
{
	///交易日
	TQdamFtdcTradingDayType	TradingDay;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///交易所名称
	TQdamFtdcExchangeNameType	ExchangeName;
} CQdamFtdcRspExchangeField;

///投资者持仓查询请求
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
} CQdamFtdcQryInvestorPositionField;

///投资者持仓查询应答
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TQdamFtdcDirectionType	Direction;
	///投机套保标志
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///占用保证金
	TQdamFtdcMoneyType	UsedMargin;
	///总持仓量
	TQdamFtdcVolumeType	Position;
	///总持仓成本
	TQdamFtdcPriceType	PositionCost;
	///初始昨持仓量(当日不变)
	TQdamFtdcVolumeType	YdPosition;
	///初始昨日持仓成本(当日不变)
	TQdamFtdcMoneyType	YdPositionCost;
	///冻结的保证金
	TQdamFtdcMoneyType	FrozenMargin;
	///开仓冻结持仓
	TQdamFtdcVolumeType	FrozenPosition;
	///平仓冻结持仓
	TQdamFtdcVolumeType	FrozenClosing;
	///持仓盈亏
	TQdamFtdcMoneyType	PositionProfit;
	///冻结的权利金
	TQdamFtdcMoneyType	FrozenPremium;
	///最后一笔成交编号
	TQdamFtdcTradeIDType	LastTradeID;
	///最后一笔本地报单编号
	TQdamFtdcOrderLocalIDType	LastOrderLocalID;
	///总持仓可平仓数量(包括平仓冻结持仓)
	TQdamFtdcVolumeType	PositionClose;
	///昨持仓可平仓数量(包括平仓冻结持仓)
	TQdamFtdcVolumeType	YdPositionClose;
	///昨持仓平仓冻结持仓
	TQdamFtdcVolumeType	YdFrozenClosing;
	///今日开仓数量(不包括冻结)
	TQdamFtdcVolumeType	OpenVolume;
	///今日平仓数量(包括昨持仓的平仓,不包括冻结)
	TQdamFtdcVolumeType	CloseVolume;
	///平仓盈亏
	TQdamFtdcMoneyType	CloseProfit;
	///执行冻结持仓
	TQdamFtdcVolumeType	StrikeFrozenPosition;
	///放弃执行冻结持仓
	TQdamFtdcVolumeType	AbandonFrozenPosition;
	///成本价
	TQdamFtdcPriceType	CostPrice;
	///开仓成本
	TQdamFtdcMoneyType	OpenCost;
} CQdamFtdcRspInvestorPositionField;

///用户查询
typedef struct
{
	///交易用户代码
	TQdamFtdcUserIDType	StartUserID;
	///交易用户代码
	TQdamFtdcUserIDType	EndUserID;
} CQdamFtdcQryUserField;

///用户
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///用户登录密码
	TQdamFtdcPasswordType	Password;
	///是否活跃
	TQdamFtdcIsActiveType	IsActive;
	///用户名称
	TQdamFtdcUserNameType	UserName;
	///用户类型
	TQdamFtdcUserTypeType	UserType;
	///营业部
	TQdamFtdcDepartmentType	Department;
	///授权功能集
	TQdamFtdcGrantFuncSetType	GrantFuncSet;
	///最大在线数
	TQdamFtdcNumberType	MaxOnline;
	///IP地址
	TQdamFtdcIPAddressType	IPAddress;
	///是否检查连接产品
	TQdamFtdcBoolType	CheckProductInfo;
	///Mac地址
	TQdamFtdcMacAddressType	MacAddress;
	///是否检查IP和MAC
	TQdamFtdcBoolType	CheckIPMacAddr;
	///错误登陆次数限制
	TQdamFtdcNumberType	LoginErrorLimit;
	///目前错误登陆次数
	TQdamFtdcNumberType	LoginErrorCount;
	///硬盘序列号
	TQdamFtdcHDSerialIDType	HDSerialID;
	///密码是否更新
	TQdamFtdcIsUpdateType	IsUpdate;
} CQdamFtdcRspUserField;

///投资者手续费率查询
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
} CQdamFtdcQryInvestorFeeField;

///投资者手续费率
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///投资者编码
	TQdamFtdcInvestorIDType	InvestorID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///开仓手续费按比例
	TQdamFtdcRatioType	OpenFeeRate;
	///开仓手续费按手数
	TQdamFtdcRatioType	OpenFeeAmt;
	///平仓手续费按比例
	TQdamFtdcRatioType	OffsetFeeRate;
	///平仓手续费按手数
	TQdamFtdcRatioType	OffsetFeeAmt;
	///平今仓手续费按比例
	TQdamFtdcRatioType	OTFeeRate;
	///平今仓手续费按手数
	TQdamFtdcRatioType	OTFeeAmt;
} CQdamFtdcRspInvestorFeeField;

///投资者保证金率查询
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	TQdamFtdcHedgeFlagType	HedgeFlag;
} CQdamFtdcQryInvestorMarginField;

///投资者保证金率
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///投资者编码
	TQdamFtdcInvestorIDType	InvestorID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///多头占用保证金按比例
	TQdamFtdcRatioType	LongMarginRate;
	///多头保证金按手数
	TQdamFtdcRatioType	LongMarginAmt;
	///空头占用保证金按比例
	TQdamFtdcRatioType	ShortMarginRate;
	///空头保证金按手数
	TQdamFtdcRatioType	ShortMarginAmt;
} CQdamFtdcRspInvestorMarginField;

///投资者查询
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
} CQdamFtdcQryInvestorField;

///投资者应答
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///投资者名称
	TQdamFtdcInvestorNameType	InvestorName;
	///投资者类型
	TQdamFtdcInvestorTypeType	InvestorType;
	///投资者组编号
	TQdamFtdcInvestorIDType	GroupID;
	///投资者组名
	TQdamFtdcInvestorNameType	GroupName;
	///别名
	TQdamFtdcAliasType	Alias;
	///连接类型
	TQdamFtdcLinkTypeType	LinkType;
	///资金账户编号
	TQdamFtdcInvestorIDType	ParentInvestorID;
	///登录次数
	TQdamFtdcNumberType	LoginStatus;
	///是否使用净持仓报单,投顾账户有效
	TQdamFtdcPositionTypeType	PositionType;
	///自成交处理方式,资金账户有效
	TQdamFtdcSelfTradeAvoidTypeType	SelfTradeAvoidType;
	///交易权限
	TQdamFtdcTradingRightType	TradingRight;
	///是否检查资金
	TQdamFtdcBoolType	CheckAccount;
	///是否检查持仓
	TQdamFtdcBoolType	CheckPosition;
	///报单是否报警
	TQdamFtdcBoolType	OrderWarning;
	///资金持仓是否上查
	TQdamFtdcBoolType	QryUpAccPosi;
	///投顾选择资金账户类型
	TQdamFtdcDistributeTypeType	DistributeType;
} CQdamFtdcRspInvestorField;

///账号风险状况查询
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
} CQdamFtdcQryAccountRiskField;

///账号风险状况应答
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///资金帐号
	TQdamFtdcAccountIDType	AccountID;
	///设置准备金
	TQdamFtdcMoneyType	SetBalance;
	///开仓红线
	TQdamFtdcMoneyType	OpenAvailable;
	///平仓红线
	TQdamFtdcMoneyType	OffsetAvailable;
	///账户状态
	TQdamFtdcAccountStatusType	AccountStatus;
	///动态权益
	TQdamFtdcMoneyType	DynamicRights;
	///账户权限
	TQdamFtdcTradingRightType	TradingRight;
} CQdamFtdcRspAccountRiskField;

///交易用户会话查询
typedef struct
{
	///交易用户代码
	TQdamFtdcUserIDType	StartUserID;
	///交易用户代码
	TQdamFtdcUserIDType	EndUserID;
} CQdamFtdcQryUserSessionField;

///交易用户会话应答
typedef struct
{
	///经纪公司代码
	TQdamFtdcBrokerIDType	BrokerID;
	///交易用户代码
	TQdamFtdcUserIDType	UserID;
	///交易用户类型
	TQdamFtdcUserTypeType	UserType;
	///会话编号
	TQdamFtdcSessionIDType	SessionID;
	///前置编号
	TQdamFtdcFrontIDType	FrontID;
	///登录时间
	TQdamFtdcTimeType	LoginTime;
	///IP地址
	TQdamFtdcIPAddressType	IPAddress;
	///Mac地址
	TQdamFtdcMacAddressType	MacAddress;
	///用户端产品信息
	TQdamFtdcProductInfoType	UserProductInfo;
	///接口端产品信息
	TQdamFtdcProductInfoType	InterfaceProductInfo;
	///协议信息
	TQdamFtdcProtocolInfoType	ProtocolInfo;
	///硬盘序列号
	TQdamFtdcHDSerialIDType	HDSerialID;
} CQdamFtdcRspUserSessionField;

///行情查询
typedef struct
{
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
} CQdamFtdcQryMarketDataField;

///行情应答
typedef struct
{
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///交易日
	TQdamFtdcTradingDayType	TradingDay;
	///昨结算
	TQdamFtdcPriceType	PreSettlementPrice;
	///昨收盘
	TQdamFtdcPriceType	PreClosePrice;
	///昨持仓量
	TQdamFtdcLargeVolumeType	PreOpenInterest;
	///昨虚实度
	TQdamFtdcRatioType	PreDelta;
	///今开盘
	TQdamFtdcPriceType	OpenPrice;
	///最高价
	TQdamFtdcPriceType	HighestPrice;
	///最低价
	TQdamFtdcPriceType	LowestPrice;
	///今收盘
	TQdamFtdcPriceType	ClosePrice;
	///涨停板价
	TQdamFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TQdamFtdcPriceType	LowerLimitPrice;
	///今结算
	TQdamFtdcPriceType	SettlementPrice;
	///今虚实度
	TQdamFtdcRatioType	CurrDelta;
	///最新价
	TQdamFtdcPriceType	LastPrice;
	///数量
	TQdamFtdcVolumeType	Volume;
	///成交金额
	TQdamFtdcMoneyType	Turnover;
	///持仓量
	TQdamFtdcLargeVolumeType	OpenInterest;
	///申买价一
	TQdamFtdcPriceType	BidPrice1;
	///申买量一
	TQdamFtdcVolumeType	BidVolume1;
	///申卖价一
	TQdamFtdcPriceType	AskPrice1;
	///申卖量一
	TQdamFtdcVolumeType	AskVolume1;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///最后修改时间
	TQdamFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TQdamFtdcMillisecType	UpdateMillisec;
} CQdamFtdcRspMarketDataField;

///产品查询
typedef struct
{
	///产品代码
	TQdamFtdcProductIDType	ProductID;
} CQdamFtdcQryProductField;

///产品应答
typedef struct
{
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///产品代码
	TQdamFtdcProductIDType	ProductID;
	///投资者发行的产品名称
	TQdamFtdcProductNameType	ProductName;
	///币种
	TQdamFtdcCurrencyType	Currency;
	///汇率
	TQdamFtdcRatioType	ExchangeRate;
} CQdamFtdcRspProductField;

///内部来回消息
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///修改用户编号
	TQdamFtdcUserIDType	UserID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///编号
	TQdamFtdcSequenceNoType	SequenceNo;
	///用户自定义域
	TQdamFtdcCustomType	UserCustom;
} CQdamFtdcPingPongField;

///最大可交易数量查询请求
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TQdamFtdcDirectionType	Direction;
	///开平标志
	TQdamFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///价格
	TQdamFtdcPriceType	LimitPrice;
} CQdamFtdcQryMaxVolumeField;

///最大可交易数量查询应答
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TQdamFtdcDirectionType	Direction;
	///开平标志
	TQdamFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///价格
	TQdamFtdcPriceType	LimitPrice;
	///数量
	TQdamFtdcVolumeType	Volume;
} CQdamFtdcRspMaxVolumeField;

///工作流交易员查询请求
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///登录经纪公司编号
	TQdamFtdcBrokerIDType	LogBrokerID;
	///登录用户代码
	TQdamFtdcUserIDType	LogUserID;
	///用户端接口版本
	TQdamFtdcProductInfoType	ApiVersion;
	///用户端程序版本
	TQdamFtdcProductInfoType	UserVersion;
} CQdamFtdcQryAdviceTraderField;

///工作流交易员查询应答
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///关联用户代码
	TQdamFtdcUserIDType	RelationUserID;
	///关联用户名称
	TQdamFtdcUserNameType	RelationUserName;
} CQdamFtdcRspAdviceTraderField;

///组合持仓明细查询请求
typedef struct
{
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
} CQdamFtdcQryCmbPositionDetailField;

///组合持仓明细查询应答
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///单腿合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///单腿合约代码
	TQdamFtdcInstrumentIDType	CmbInstrumentID;
	///成交编号
	TQdamFtdcTradeIDType	TradeID;
	///报单编号
	TQdamFtdcOrderSysIDType	OrderSysID;
	///买卖方向
	TQdamFtdcDirectionType	Direction;
	///投机套保标志
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///持仓量
	TQdamFtdcVolumeType	Position;
	///单腿编号
	TQdamFtdcNumberType	LegQty;
	///交易日期
	TQdamFtdcTradingDayType	TradingDay;
} CQdamFtdcRspCmbPositionDetailField;

///投资者结算结果查询请求
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///交易日期
	TQdamFtdcTradingDayType	TradingDay;
} CQdamFtdcQrySettlementInfoField;

///投资者结算结果查询应答
typedef struct
{
	///交易日期
	TQdamFtdcTradingDayType	TradingDay;
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///序号
	TQdamFtdcSequenceNoType	SequenceNo;
	///消息正文
	TQdamFtdcContentType	Content;
} CQdamFtdcRspSettlementInfoField;

///查询结果集分页
typedef struct
{
	///结果集编号
	TQdamFtdcSessionIDType	ResultID;
	///总记录数
	TQdamFtdcNumberType	Count;
	///总页数
	TQdamFtdcNumberType	Pages;
	///剩余页数
	TQdamFtdcNumberType	Remain;
} CQdamFtdcQryResultPageField;

///查询持仓明细请求
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///单腿合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
} CQdamFtdcQryPositionDetailField;

///查询持仓明细应答
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///买卖方向
	TQdamFtdcDirectionType	Direction;
	///开仓日期
	TQdamFtdcDateType	OpenDate;
	///成交编号
	TQdamFtdcTradeIDType	TradeID;
	///数量
	TQdamFtdcVolumeType	Volume;
	///开仓价
	TQdamFtdcMoneyType	OpenPrice;
	///交易日
	TQdamFtdcDateType	TradingDay;
	///交易类型
	TQdamFtdcTradeTypeType	TradeType;
	///组合合约代码
	TQdamFtdcInstrumentIDType	CombInstrumentID;
	///逐日盯市平仓盈亏
	TQdamFtdcMoneyType	CloseProfitByDate;
	///逐笔对冲平仓盈亏
	TQdamFtdcMoneyType	CloseProfitByTrade;
	///逐日盯市持仓盈亏
	TQdamFtdcMoneyType	PositionProfitByDate;
	///逐笔对冲持仓盈亏
	TQdamFtdcMoneyType	PositionProfitByTrade;
	///投资者保证金
	TQdamFtdcMoneyType	Margin;
	///交易所保证金
	TQdamFtdcMoneyType	ExchMargin;
	///保证金率
	TQdamFtdcMoneyType	MarginRateByMoney;
	///保证金率(按手数)
	TQdamFtdcMoneyType	MarginRateByVolume;
	///昨结算价
	TQdamFtdcPriceType	LastSettlementPrice;
	///结算价
	TQdamFtdcPriceType	SettlementPrice;
	///平仓量
	TQdamFtdcVolumeType	CloseVolume;
	///平仓金额
	TQdamFtdcMoneyType	CloseAmount;
	///结算编号
	TQdamFtdcSettlementIDType	SettlementID;
	///投资单元代码
	TQdamFtdcInvestUnitIDType	InvestUnitID;
	///持仓明细编号
	TQdamFtdcNumberType	SeqNum;
	///用户自定义域
	TQdamFtdcCustomType	UserCustom;
} CQdamFtdcRspPositionDetailField;

///询价查询
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
} CQdamFtdcQryForQuoteField;

///询价查询应答
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///用户本地报单号
	TQdamFtdcUserOrderLocalIDType	UserOrderLocalID;
	///用户自定义域
	TQdamFtdcCustomType	UserCustom;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///本地报单编号
	TQdamFtdcOrderLocalIDType	OrderLocalID;
	///询价状态
	TQdamFtdcForQuoteStatusTypeType	ForQuoteStatus;
	///交易日
	TQdamFtdcDateType	TradingDay;
	///插入时间
	TQdamFtdcTimeType	InsertTime;
} CQdamFtdcForQuoteField;

///报价查询
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///系统报单编号
	TQdamFtdcOrderSysIDType	OrderSysID;
} CQdamFtdcQryQuoteField;

///投资者期权手续费率查询
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
} CQdamFtdcQryInvestorOptionFeeField;

///投资者期权手续费率
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///投资者编码
	TQdamFtdcInvestorIDType	InvestorID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///开仓手续费按比例
	TQdamFtdcRatioType	OpenFeeRate;
	///开仓手续费按手数
	TQdamFtdcRatioType	OpenFeeAmt;
	///平仓手续费按比例
	TQdamFtdcRatioType	OffsetFeeRate;
	///平仓手续费按手数
	TQdamFtdcRatioType	OffsetFeeAmt;
	///平今仓手续费按比例
	TQdamFtdcRatioType	OTFeeRate;
	///平今仓手续费按手数
	TQdamFtdcRatioType	OTFeeAmt;
	///执行手续费按比例
	TQdamFtdcRatioType	StrikeFeeRate;
	///执行手续费按手数
	TQdamFtdcRatioType	StrikeFeeAmt;
} CQdamFtdcRspInvestorOptionFeeField;

///执行宣告查询
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///用户代码
	TQdamFtdcUserIDType	UserID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///报单编号
	TQdamFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
} CQdamFtdcQryExecOrderField;

///投资者通知
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///投资者名称
	TQdamFtdcInvestorNameType	InvestorName;
	///投资者类型
	TQdamFtdcInvestorTypeType	InvestorType;
	///投资者组编号
	TQdamFtdcInvestorIDType	GroupID;
	///投资者组名
	TQdamFtdcInvestorNameType	GroupName;
	///别名
	TQdamFtdcAliasType	Alias;
	///连接类型
	TQdamFtdcLinkTypeType	LinkType;
	///资金账户编号
	TQdamFtdcInvestorIDType	ParentInvestorID;
	///登录次数
	TQdamFtdcNumberType	LoginStatus;
	///是否使用净持仓报单,投顾账户有效
	TQdamFtdcPositionTypeType	PositionType;
	///自成交处理方式,资金账户有效
	TQdamFtdcSelfTradeAvoidTypeType	SelfTradeAvoidType;
	///交易权限
	TQdamFtdcTradingRightType	TradingRight;
	///是否检查资金
	TQdamFtdcBoolType	CheckAccount;
	///是否检查持仓
	TQdamFtdcBoolType	CheckPosition;
	///报单是否报警
	TQdamFtdcBoolType	OrderWarning;
	///资金持仓是否上查
	TQdamFtdcBoolType	QryUpAccPosi;
	///投顾选择资金账户类型
	TQdamFtdcDistributeTypeType	DistributeType;
} CQdamFtdcRtnInvestorField;

///投资者资金通知
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///资金帐号
	TQdamFtdcAccountIDType	AccountID;
	///上次结算准备金
	TQdamFtdcMoneyType	PreBalance;
	///上日可用资金
	TQdamFtdcMoneyType	PreAvailable;
	///入金金额
	TQdamFtdcMoneyType	Deposit;
	///出金金额
	TQdamFtdcMoneyType	Withdraw;
	///占用保证金
	TQdamFtdcMoneyType	Margin;
	///期权权利金收支
	TQdamFtdcMoneyType	Premium;
	///手续费
	TQdamFtdcMoneyType	Fee;
	///冻结的保证金
	TQdamFtdcMoneyType	FrozenMargin;
	///冻结权利金
	TQdamFtdcMoneyType	FrozenPremium;
	///冻结手续费
	TQdamFtdcMoneyType	FrozenFee;
	///平仓盈亏
	TQdamFtdcMoneyType	CloseProfit;
	///持仓盈亏
	TQdamFtdcMoneyType	PositionProfit;
	///可用资金
	TQdamFtdcMoneyType	Available;
	///结算准备金
	TQdamFtdcMoneyType	Balance;
	///多头占用保证金
	TQdamFtdcMoneyType	LongMargin;
	///空头占用保证金
	TQdamFtdcMoneyType	ShortMargin;
	///多头冻结的保证金
	TQdamFtdcMoneyType	LongFrozenMargin;
	///空头冻结的保证金
	TQdamFtdcMoneyType	ShortFrozenMargin;
	///动态权益
	TQdamFtdcMoneyType	DynamicRights;
	///风险度
	TQdamFtdcRatioType	Risk;
	///其他费用
	TQdamFtdcMoneyType	OtherFee;
	///质押金额
	TQdamFtdcMoneyType	Mortgage;
	///币种
	TQdamFtdcCurrencyType	Currency;
	///可取资金
	TQdamFtdcMoneyType	WithdrawQuota;
	///冻结的资金
	TQdamFtdcMoneyType	FrozenCash;
	///账户余额
	TQdamFtdcMoneyType	CurrentBalance;
	///总资产
	TQdamFtdcMoneyType	AssetBalance;
	///总市值
	TQdamFtdcMoneyType	MarketValue;
} CQdamFtdcRtnInvestorAccountField;

///投资者风控权限通知
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///买开权限
	TQdamFtdcBoolType	BuyOpen;
	///买平权限
	TQdamFtdcBoolType	BuyClose;
	///卖开权限
	TQdamFtdcBoolType	SellOpen;
	///卖平权限
	TQdamFtdcBoolType	SellClose;
	///产品类型
	TQdamFtdcProductClassType	ProductClass;
} CQdamFtdcRtnInvestorTradingRightRiskField;

///投资者权限通知
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///合约交易权限
	TQdamFtdcTradingRightType	TradingRight;
	///产品类型
	TQdamFtdcProductClassType	ProductClass;
} CQdamFtdcRtnInvestorTradingRightField;

///交易汇率查询
typedef struct
{
	///币种
	TQdamFtdcCurrencyType	InstCurrency;
	///币种
	TQdamFtdcCurrencyType	AccCurrency;
} CQdamFtdcQryExchangeRateField;

///交易汇率
typedef struct
{
	///币种
	TQdamFtdcCurrencyType	InstCurrency;
	///币种
	TQdamFtdcCurrencyType	AccCurrency;
	///汇率
	TQdamFtdcRatioType	ExchangeRate;
} CQdamFtdcRspExchangeRateField;

///交易汇率通知
typedef struct
{
	///币种
	TQdamFtdcCurrencyType	InstCurrency;
	///币种
	TQdamFtdcCurrencyType	AccCurrency;
	///汇率
	TQdamFtdcRatioType	ExchangeRate;
} CQdamFtdcRtnExchangeRateField;

///新组合持仓明细查询请求
typedef struct
{
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
} CQdamFtdcQryCombPositionDetailField;

///新组合持仓明细查询应答
typedef struct
{
	///交易日期
	TQdamFtdcTradingDayType	TradingDay;
	///开仓日期
	TQdamFtdcDateType	OpenDate;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///结算编号
	TQdamFtdcSettlementIDType	SettlementID;
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///组合编号
	TQdamFtdcTradeIDType	ComTradeID;
	///成交编号
	TQdamFtdcTradeIDType	TradeID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///买卖方向
	TQdamFtdcDirectionType	Direction;
	///持仓量
	TQdamFtdcVolumeType	Position;
	///投资者保证金
	TQdamFtdcMoneyType	Margin;
	///交易所保证金
	TQdamFtdcMoneyType	ExchMargin;
	///保证金率
	TQdamFtdcMoneyType	MarginRateByMoney;
	///保证金率(按手数)
	TQdamFtdcMoneyType	MarginRateByVolume;
	///单腿编号
	TQdamFtdcLegIDType	LegID;
	///单腿乘数
	TQdamFtdcLegMultipleType	LegMultiple;
	///组合持仓合约代码
	TQdamFtdcInstrumentIDType	CmbInstrumentID;
	///成交组号
	TQdamFtdcTradeGroupIDType	TradeGroupID;
} CQdamFtdcRspCombPositionDetailField;

///投资者持仓通知
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TQdamFtdcDirectionType	Direction;
	///投机套保标志
	TQdamFtdcHedgeFlagType	HedgeFlag;
	///占用保证金
	TQdamFtdcMoneyType	UsedMargin;
	///总持仓量
	TQdamFtdcVolumeType	Position;
	///总持仓成本
	TQdamFtdcPriceType	PositionCost;
	///初始昨持仓量(当日不变)
	TQdamFtdcVolumeType	YdPosition;
	///初始昨日持仓成本(当日不变)
	TQdamFtdcMoneyType	YdPositionCost;
	///冻结的保证金
	TQdamFtdcMoneyType	FrozenMargin;
	///开仓冻结持仓
	TQdamFtdcVolumeType	FrozenPosition;
	///平仓冻结持仓
	TQdamFtdcVolumeType	FrozenClosing;
	///持仓盈亏
	TQdamFtdcMoneyType	PositionProfit;
	///冻结的权利金
	TQdamFtdcMoneyType	FrozenPremium;
	///最后一笔成交编号
	TQdamFtdcTradeIDType	LastTradeID;
	///最后一笔本地报单编号
	TQdamFtdcOrderLocalIDType	LastOrderLocalID;
	///总持仓可平仓数量(包括平仓冻结持仓)
	TQdamFtdcVolumeType	PositionClose;
	///昨持仓可平仓数量(包括平仓冻结持仓)
	TQdamFtdcVolumeType	YdPositionClose;
	///昨持仓平仓冻结持仓
	TQdamFtdcVolumeType	YdFrozenClosing;
	///今日开仓数量(不包括冻结)
	TQdamFtdcVolumeType	OpenVolume;
	///今日平仓数量(包括昨持仓的平仓,不包括冻结)
	TQdamFtdcVolumeType	CloseVolume;
	///平仓盈亏
	TQdamFtdcMoneyType	CloseProfit;
	///执行冻结持仓
	TQdamFtdcVolumeType	StrikeFrozenPosition;
	///放弃执行冻结持仓
	TQdamFtdcVolumeType	AbandonFrozenPosition;
	///成本价
	TQdamFtdcPriceType	CostPrice;
	///开仓成本
	TQdamFtdcMoneyType	OpenCost;
} CQdamFtdcRtnInvestorPositionField;

///期权自对冲查询
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编码
	TQdamFtdcInvestorIDType	InvestorID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///期权自对冲操作编号
	TQdamFtdcOrderSysIDType	OptionSelfCloseSysID;
	///开始时间
	TQdamFtdcTimeType	InsertTimeStart;
	///结束时间
	TQdamFtdcTimeType	InsertTimeEnd;
} CQdamFtdcQryOptionSelfCloseField;

///锁定证券仓位查询
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
} CQdamFtdcQryLockPositionField;

///锁定证券仓位
typedef struct
{
	///经纪公司编号
	TQdamFtdcBrokerIDType	BrokerID;
	///投资者编号
	TQdamFtdcInvestorIDType	InvestorID;
	///会员编号
	TQdamFtdcParticipantIDType	ParticipantID;
	///客户代码
	TQdamFtdcClientIDType	ClientID;
	///合约代码
	TQdamFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TQdamFtdcExchangeIDType	ExchangeID;
	///锁仓数量
	TQdamFtdcVolumeType	Volume;
	///冻结数量
	TQdamFtdcVolumeType	FrozenVolume;
	///今日锁定数量
	TQdamFtdcVolumeType	TodayVolume;
} CQdamFtdcLockPositionField;

#endif
