package main

import (
	"flag"
	"fmt"
	"strings"
	"time"

	"github.com/frozenpine/qmarket4go"
)

type myAPI struct {
	qmarket4go.QMdAPI
}

var (
	front    string
	userID   string
	brokerID string
	password string
	sub      string
	subList  []string
)

func (md *myAPI) OnFrontConnected() {
	md.QMdAPI.OnFrontConnected()

	md.Login(&qmarket4go.GoQdamFtdcReqUserLoginField{UserID: userID, BrokerID: brokerID, Password: password})
}

func (md *myAPI) OnRspUserLogin(
	rsp *qmarket4go.GoQdamFtdcRspUserLoginField,
	err *qmarket4go.GoQdamFtdcRspInfoField,
	reqID int, isLast bool,
) {
	md.QMdAPI.OnRspUserLogin(rsp, err, reqID, isLast)

	if err.ErrorID == 0 {
		for _, ins := range subList {
			md.SubMarketData(ins)
		}
	}
}

func init() {
	flag.StringVar(&front, "front", "", "Front conn string")
	flag.StringVar(&sub, "sub", "*", "Subscribe market datas")
	flag.StringVar(&userID, "user", "123456", "UserID")
	flag.StringVar(&brokerID, "broker", "0001", "BrokerID")
	flag.StringVar(&password, "pass", "111111", "Password")
}

func main() {
	if !flag.Parsed() {
		flag.Parse()
	}

	if front == "" {
		fmt.Println("Front address must be specified by -front")
		return
	}

	subList = strings.Split(sub, ",")

	api := myAPI{}
	api.InitAPI("./flow/")
	api.RegisterCallback(&api)
	api.RegisterFront(front)
	api.Init()

	for {
		time.Sleep(1 * 1000 * 1000 * 1000)
	}
}
