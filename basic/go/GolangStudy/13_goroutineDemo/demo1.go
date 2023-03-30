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

	fmt.Println("main goroutine exit")

	// i := 0
	// for {
	// 	i++
	// 	fmt.Println("main Gorotine : i = ", i)
	// 	time.Sleep(1 * time.Second)
	// }

}
