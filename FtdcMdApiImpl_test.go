package qmarket4go

import (
	"testing"
	"time"
)

func TestMdApi(t *testing.T) {
	api := QMdAPI{}

	api.InitAPI("./flow/")
	api.RegisterCallback(&api)
	api.RegisterFront("tcp://122.144.129.233:30027")
	api.Init()

	for {
		if api.Connected {
			login := GoQdamFtdcReqUserLoginField{}
			login.UserID = "230855"
			login.BrokerID = "0001"
			login.Password = "230855"
			api.Login(&login)
		}
		if api.Logged {
			break
		}
		time.Sleep(1 * 1000 * 1000 * 1000)
	}
}
