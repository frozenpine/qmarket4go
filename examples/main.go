package main

import (
	"flag"
	"fmt"
	"strings"
	"time"

	. "github.com/frozenpine/qmarket4go"
)

type myAPI struct {
	QMdAPI
}

var (
	userID   string
	brokerID string
	password string
	subList  []string
)

func (md *myAPI) OnFrontConnected() {
	md.QMdAPI.OnFrontConnected()

	md.Login(&GoQdamFtdcReqUserLoginField{UserID: userID, BrokerID: brokerID, Password: password})
}

func (md *myAPI) OnRspUserLogin(rsp *GoQdamFtdcRspUserLoginField, err *GoQdamFtdcRspInfoField, reqID int, isLast bool) {
	md.QMdAPI.OnRspUserLogin(rsp, err, reqID, isLast)

	if err.ErrorID == 0 {
		for _, ins := range subList {
			md.SubMarketData(ins)
		}
	}
}

func main() {
	ptrFrontAddress := flag.String("front", "", "Front conn string")
	ptrSubInstruments := flag.String("sub", "*", "Subscribe market datas")

	ptrUserID := flag.String("user", "123456", "UserID")
	ptrBrokerID := flag.String("broker", "0001", "BrokerID")
	ptrPassword := flag.String("pass", "111111", "Password")

	flag.Parse()

	userID = *ptrUserID
	brokerID = *ptrBrokerID
	password = *ptrPassword

	if *ptrFrontAddress == "" {
		fmt.Println("Front address must be specified by -front")
		return
	}

	subList = strings.Split(*ptrSubInstruments, ",")

	api := myAPI{}
	api.InitAPI("./flow/")
	api.RegisterCallback(&api)
	api.RegisterFront(*ptrFrontAddress)
	api.Init()

	for {
		time.Sleep(1 * 1000 * 1000 * 1000)
	}
}
