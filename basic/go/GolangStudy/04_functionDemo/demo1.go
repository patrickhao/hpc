package main

import (
	"fmt"
)

func foo1(a string, b int) int {
	fmt.Println(a, b)
	c := 100
	return c
}

func foo2() (int, int) {
	return 1, 2
}

// 返回多个值，有形参名称
// r1 r2属于foo3的形参，默认为0，作用域空间是foo3
func foo3() (r1 int, r2 int) {
	r1 = 1
	r2 = 2
	return
}

func foo4() (r1, r2 int) {
	r1 = 1
	r2 = 2
	return
}

func main() {
	aa := foo1("a", 1)
	fmt.Println(aa)

	bb1, bb2 := foo2()
	fmt.Println(bb1, bb2)

	cc1, cc2 := foo3()
	fmt.Println(cc1, cc2)

	dd1, dd2 := foo4()
	fmt.Println(dd1, dd2)
}
