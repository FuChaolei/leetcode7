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

var wg sync.WaitGroup
var res int
var mu sync.Mutex

func add(s int) {
	for i := s; i < s+100; i++ {
		mu.Lock()
		res += i
		mu.Unlock()
	}
	wg.Done()
}
func main() {
	res = 0
	for i := 1; i <= 100; i++ {
		go add((i - 1) * 100)
		wg.Add(1)
	}
	wg.Wait()
	fmt.Println(res)
}
