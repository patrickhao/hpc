package main

import "fmt"

func main() {
	// channel用于goroutine之间的通信，可以用不同的channel在不同的goroutine间通信
	// 该处定义的是无缓冲的channel
	// 关于无缓冲的channel，先到达channel的goroutine会等待另一个goroutine取出数据再向下执行
	c := make(chan int)

	go func() {
		defer fmt.Println("goroutine end")
		fmt.Println("goroutine running...")
		c <- 6 // 向channel中增加数据
	}()

	// channel中有同步两侧操作的能力
	// 若main的goroutine先到该行，则会阻塞等待子goroutine的写入操作
	// 等到数据写入之后再唤醒main的goroutine
	// 若子goroutine先写入了，也会阻塞，等到main的goroutine读出后再继续
	// channel会调节两侧goroutine的执行，达到一种同步的效果
	// 若c中没有元素，执行该句会造成死锁，因为一直在等待子goroutine写入元素，但是子goroutine已经没有元素写了
	// 导致main的goroutine一直阻塞
	num := <-c // 从c中接受数据，并赋值给c
	fmt.Println(num)
	// 子goroutine和主goroutine结束先后不一定，根据具体的调度情况
	fmt.Println("main goroutine end")
}
