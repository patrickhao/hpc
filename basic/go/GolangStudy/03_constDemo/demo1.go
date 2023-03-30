package main

import (
	"fmt"
)

func main() {
	const length int = 10

	// const定义枚举
	//const (
	//	BEIJING = 0
	//	SHANGHAI = 1
	//	SHENZHEN = 2
	//)
	// 可以在const()中添加iota关键字，每行的iota都会累加1，第一行默认值是0
	// iota只能配合const使用
	const (
		// BEIJING = 10 * iota 之后的都会使用该公式
		BEIJING  = iota // iota = 0
		SHANGHAI        // iota = 1
		SHENZHEN        // iota = 2
	)

	const (
		a, b = iota + 1, iota + 2 // iota = 0, a = iota + 1, b = iota + 2
		c, d // iota = 1, c = iota + 1, d = iota + 2
		e, f // iota = 2, e = iota + 2, d = iota + 2
		// 在这里之后iota的算法开始改变
		g, h = iota * 2, iota * 3 // iota = 3, g = iota * 2, h = iota * 3
		i, j // iota = 4, i = iota * 2, j = iota * 3
	)

	fmt.Println(a, b)
	fmt.Println(c, d)
	fmt.Println(e, f)
	fmt.Println(g, h)
	fmt.Println(i, j)

	fmt.Println(length)
}
