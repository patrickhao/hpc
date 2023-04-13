package main

import (
	"fmt"
	"time"
)

func main() {
	// 用go承载一个有参，有返回值的函数
	go func(a int, b int) bool {
		fmt.Println(a, b)
		return true
	}(10, 20)

	for {
		time.Sleep(1 * time.Second)
	}
}
