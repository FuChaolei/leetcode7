//go:build ignore

package main

import "fmt"

//"fmt"
//"container/list"
//"sort"
//"math/rand"
//"math"
//"strings"
type abstractApple interface {
	ShowName()
}
type ChinaApple struct{}

func (apple *ChinaApple) ShowName() {
	fmt.Println("i`m chinese apple")
}

type USAApple struct{}

func (apple *USAApple) ShowName() {
	fmt.Println("i`m usa apple")
}

type abstractBanana interface {
	ShowName()
}
type ChinaBanana struct{}

func (banana *ChinaBanana) ShowName() {
	fmt.Println("i`m chinese Banana")
}

type USABanana struct{}

func (banana *USABanana) ShowName() {
	fmt.Println("i`m usa Banana")
}

type AbstractFactory interface {
	CreateApple() abstractApple
	CreateBanana() abstractBanana
}
type ChinaFactory struct{}

func (factory *ChinaFactory) CreateApple() abstractApple {
	return new(ChinaApple)
}
func (factory *ChinaFactory) CreateBanana() abstractBanana {
	return new(ChinaBanana)
}

type USAFactory struct{}

func (factory *USAFactory) CreateApple() abstractApple {
	return new(USAApple)
}
func (factory *USAFactory) CreateBanana() abstractBanana {
	return new(USABanana)
}

func main() {
	var factory AbstractFactory
	var fruit abstractApple
	factory = new(ChinaFactory)
	fruit = factory.CreateApple()
	fruit.ShowName()
}
