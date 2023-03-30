package main

import (
	"fmt"
	"time"
)

func main() {
	c := make(chan int, 3) // 带有缓冲的channel
	// len当前channel中包含的元素的数量，cap当前的容量
	fmt.Printf("len(c) = %d, cap(c) = %d\n", len(c), cap(c))

	go func() {
		defer fmt.Println("go end")
		// 满了之后，会等待主go程取程序，取出程序之后，再执行子routine
		// channel已经满了之后再写数据就会阻塞
		for i := 0; i < 5; i++ {
			c <- i
			fmt.Printf("goroutine is running, len(c) = %d, cap(c) = %d\n", len(c), cap(c))
		}
	}()

	time.Sleep(2 * time.Second)

	// 若i < 3，则读完channel中的3个元素后main的goroutine结束，随机子gouroutine结束
	// channel已经空了再取元素也会阻塞
	for i := 0; i < 5; i++ {
		num := <-c // 从c中接受数据，并赋值给num
		fmt.Println("num = ", num)
	}

	fmt.Println("main routine running")
}
