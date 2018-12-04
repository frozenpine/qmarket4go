package qmarket4go

import (
	"sync/atomic"
	"testing"
	"time"
)

type myAPI struct {
	QMdAPI
}

var (
	shutdown         int64
	ins1, ins2, ins3 int
)

func (md *myAPI) OnFrontConnected() {
	md.QMdAPI.OnFrontConnected()

	login := GoQdamFtdcReqUserLoginField{}
	login.UserID = "230855"
	login.BrokerID = "0001"
	login.Password = "230855"

	md.Login(&login)
}

func (md *myAPI) OnRspUserLogin(rsp *GoQdamFtdcRspUserLoginField, err *GoQdamFtdcRspInfoField, reqID int, isLast bool) {
	md.QMdAPI.OnRspUserLogin(rsp, err, reqID, isLast)

	md.SubMarketData("fu1901", "rb1901", "CL1901")
}

func (md *myAPI) OnRtnDepthMarketData(rtn *GoQdamFtdcDepthMarketDataField) {
	md.QMdAPI.OnRtnDepthMarketData(rtn)

	switch rtn.InstrumentID {
	case "fu1901":
		ins1++
	case "rb1901":
		ins2++
	case "CL1901":
		ins3++
	}

	if ins1 > 0 && ins2 > 0 && ins3 > 0 {
		atomic.StoreInt64(&shutdown, 1)
	}
}

func TestMdApi(t *testing.T) {
	api := myAPI{}

	api.InitAPI("./flow/")
	api.RegisterCallback(&api)
	api.RegisterFront("tcp://122.144.129.233:30027")
	api.Init()

	for {
		time.Sleep(1 * 1000 * 1000 * 1000)
		if atomic.LoadInt64(&shutdown) > 0 {
			t.Log("All market data received.")
			break
		}
	}
}
