package qmarket4go

import (
	"testing"
	"time"
)

type myAPI struct {
	QMdAPI
}

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

func TestMdApi(t *testing.T) {
	api := myAPI{}

	api.InitAPI("./flow/")
	api.RegisterCallback(&api)
	api.RegisterFront("tcp://122.144.129.233:30027")
	api.Init()

	for i := 0; i < 10; i++ {
		time.Sleep(1 * 1000 * 1000 * 1000)
	}
}
