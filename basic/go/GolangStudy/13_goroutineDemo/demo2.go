package main

import (
	"fmt"
	"time"
)

func main() {
	// 用go承载一个形参为空，返回值为空的一个函数
	// 使用匿名方法
	go func() {
		defer fmt.Println("A.defer")

		func() {
			defer fmt.Println("B.defer")
			// 退出当前goroutine
			// runtime.Goexit()
			fmt.Println("B")
		}() // 定义函数并调用，函数后加()调用

		fmt.Println("A")
	}()

	// 死循环
	for {
		time.Sleep(1 * time.Second)
	}
}
