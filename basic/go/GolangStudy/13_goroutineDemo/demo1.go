package main

import (
	"fmt"
	"time"
)

// 从goroutine
// 依赖于主goroutine，主goroutine退出则其也退出
func newTask() {
	i := 0
	for {
		i++
		fmt.Println("new Gorotine : i = ", i)
		time.Sleep(1 * time.Second)
	}
}

// 主goroutine
func main() {
	// 创建一个go程，去执行newTask()流程
	go newTask()

	// 主进程继续
	fmt.Println("main goroutine exit")

	// 和协程各跑各的
	// i := 0
	// for {
	// 	i++
	// 	fmt.Println("main Gorotine : i = ", i)
	// 	time.Sleep(1 * time.Second)
	// }

	// 主进程退出，协程也会退出

}
