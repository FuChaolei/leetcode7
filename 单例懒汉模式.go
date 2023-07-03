//go:build ignore

package main

import (
	"fmt"
	//"container/list"
	//"sort"
	//"math/rand"
	//"math"
	//"strings"
	"sync"
)

var once sync.Once

type Lazy struct{}

var lazy *Lazy

func getInstance() *Lazy {
	once.Do(func() {
		lazy = new(Lazy)
	})
	return lazy
}
func (l *Lazy) dosome() {
	fmt.Println("fdgsfd")
}

func main() {
	tmp := getInstance()
	tmp.dosome()
}
