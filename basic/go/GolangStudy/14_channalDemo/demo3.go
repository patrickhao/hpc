package main

import "fmt"

func main() {
	c := make(chan int)

	go func() {
		for i := 0; i < 5; i++ {
			c <- i
		}

		// close可以关闭一个channel
		// 若不关闭，main的goroutine读完五次后一直等待子goroutine写数据，会导致死锁
		// 关闭channel后可以继续接受数据，直到数据读取完毕
		// 对于nil channel，无论收发都会阻塞
		close(c)
	}()

	// for {
	// 	// ok为true表示channel没有关闭，为false表示channel已经关闭
	// 	if data, ok := <-c; ok {
	// 		fmt.Println(data)
	// 	} else {
	// 		break
	// 	}
	// }

	// 有数据就会返回，可以使用range来迭代不断操作的channel
	for data := range c {
		fmt.Println(data)
	}

	fmt.Println("main end")
}
