package main

import "fmt"

func fibonacii(c, quit chan int) {
	x, y := 1, 1
	for {
		select {
		case c <- x:
			// 如果c可写，则该case就会进来
			x = y
			y = x + y
		case <-quit:
			// 当quit可读
			fmt.Println("quit")
			return
		}
	}
}

// 正常只能监听一个channel，使用select可以监听多个channel的状态
func main() {
	c := make(chan int)
	quit := make(chan int)

	go func() {
		for i := 0; i < 6; i++ {
			fmt.Println(<-c)
		}
		quit <- 0
	}()

	fibonacii(c, quit)

}
