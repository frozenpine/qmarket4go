package qmarket4go

import (
	"time"
)

type direction int

const (
	// Buy 买方向
	Buy direction = iota
	// Sell 卖方向
	Sell
)

func (d direction) ToString() string {
	switch d {
	case Buy:
		return "买"
	case Sell:
		return "卖"
	}

	return ""
}

type insStatus int

const (
	// BeforeTrading 开盘前
	BeforeTrading insStatus = iota
	// NoTrading 非交易
	NoTrading
	// Continous 连续交易
	Continous
	// AuctionOrdering 集合竞价报价
	AuctionOrdering
	// AuctionBalance 集合竞价平衡
	AuctionBalance
	// AuctionMatch 集合竞价撮合
	AuctionMatch
	// Closed 收盘
	Closed
	// SGEDeryApp 金交所交割申报
	SGEDeryApp
	// SGEDeryMatch 金交所交割申报撮合
	SGEDeryMatch
	// SGEMidApp 金交所中立仓申报
	SGEMidApp
	// SGEMidMatch 金交所中立仓申报撮合
	SGEMidMatch
)

type priceItem struct {
	Price  float64
	Volume int
}

// GoQdamFtdcRspInfoField 响应信息
type GoQdamFtdcRspInfoField struct {
	ErrorID  int
	ErrorMsg string
}

// GoQdamFtdcDepthMarketDataField 深度行情
type GoQdamFtdcDepthMarketDataField struct {
	TradingDay         string
	PreSettlementPrice float64
	PreClosePrice      float64
	PreOpenInterest    float64
	PreDelta           float64
	OpenPrice          float64
	HighestPrice       float64
	LowestPrice        float64
	ClosePrice         float64
	UpperLimitPrice    float64
	LowerLimitPrice    float64
	SettlementPrice    float64
	CurrDelta          float64
	LastPrice          float64
	Volume             int
	Turnover           float64
	OpenInterest       float64
	Asks               []priceItem
	VolumeAskLot       int
	Bids               []priceItem
	VolumeBidLot       int
	InstrumentID       string
	UpdateTime         time.Time
	ExchangeID         string
	InstrumentStatus   insStatus
}

// GoQdamFtdcRspUserLoginField 用户登录应答
type GoQdamFtdcRspUserLoginField struct {
	TradingDay        string
	BrokerID          string
	UserID            string
	LoginTime         time.Time
	MaxOrderLocalID   int
	TradingSystemName string
	DataCenterID      int
	PrivateFlowSize   int
	UserFlowSize      int
	LoginInfo         string
	SessionID         int
	FrontID           int
}

// GoQdamFtdcRspUserLogoutField 用户登出应答
type GoQdamFtdcRspUserLogoutField struct {
	BrokerID string
	UserID   string
}

// GoQdamFtdcSpecificInstrumentField 订阅合约的相关信息
type GoQdamFtdcSpecificInstrumentField struct {
	InstrumentID string
}

// GoQdamFtdcMBLMarketDataField 分价行情
type GoQdamFtdcMBLMarketDataField struct {
	InstrumentID string
	Direction    direction
	Price        float64
	Volume       int
	UpdateTime   time.Time
}

// GoQdamFtdcQmdInstrumentStateField 合约状态
type GoQdamFtdcQmdInstrumentStateField struct {
	ExchangeID       string
	InstrumentID     string
	InstrumentStatus insStatus
}

// GoQdamFtdcDisseminationField 信息分发
type GoQdamFtdcDisseminationField struct {
	SequenceSeries int
	SequenceNo     int
}

// GoQdamFtdcRspMarketDataField 行情应答
type GoQdamFtdcRspMarketDataField struct {
	ExchangeID         string
	TradingDay         string
	PreSettlementPrice float64
	PreClosePrice      float64
	PreOpenInterest    float64
	PreDelta           float64
	OpenPrice          float64
	HighestPrice       float64
	LowestPrice        float64
	ClosePrice         float64
	UpperLimitPrice    float64
	LowerLimitPrice    float64
	SettlementPrice    float64
	CurrDelta          float64
	LastPrice          float64
	Volume             int
	Turnover           float64
	OpenInterest       float64
	BidPrice           float64
	BidVolume          int
	AskPrice           float64
	AskVolume          int
	InstrumentID       string
	UpdateTime         time.Time
}

// GoQdamFtdcShmDepthMarketDataField 共享内存行情查询
type GoQdamFtdcShmDepthMarketDataField struct {
	InstrumentID string
	IPAddress    string
	TopicID      int
}

// GoQdamFtdcReqUserLoginField 系统用户登录请求
type GoQdamFtdcReqUserLoginField struct {
	UserID               string
	BrokerID             string
	Password             string
	UserProductInfo      string
	InterfaceProductInfo string
	OneTimePassword      string
	AuthCode             string
	FieldContent         string
}

// GoQdamFtdcReqUserLogoutField 用户登出请求
type GoQdamFtdcReqUserLogoutField struct {
	BrokerID string
	UserID   string
}
