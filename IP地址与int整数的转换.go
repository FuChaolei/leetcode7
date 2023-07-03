//go:build ignore

package main

import (
	"fmt"
	"strconv"
	"strings"
)

//"fmt"
//"container/list"
//"sort"
//"math/rand"
//"math"
//"strings"
//https://blog.csdn.net/yzf279533105/article/details/81238758
func ipTouint(ip string) uint32 {
	var res uint32
	ls := strings.Split(ip, ".")
	nums := make([]int, 4)
	for i := 0; i < 4; i++ {
		nums[i], _ = strconv.Atoi(ls[i])
		res <<= 8
		res |= uint32(nums[i])
	}
	return res
}
func uintTouip(k uint32) string {
	res := ""
	for i := 0; i < 4; i++ {
		if i == 0 {
			res = strconv.Itoa(int(k & 255))
		} else {
			res = strconv.Itoa(int(k&255)) + "." + res
		}
		k >>= 8
	}
	return res
}

func main() {
	//res := get_res()
	a := ""
	var b uint32
	for {
		n, _ := fmt.Scan(&a, &b)
		if n == 0 {
			break
		} else {
			fmt.Println(ipTouint(a))
			fmt.Println(uintTouip(b))
		}
	}
}
