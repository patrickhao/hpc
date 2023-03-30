package main

import (
	"fmt"
)

/**
四种声明变量的方式
*/

// 声明全局变量可以用方法一、二、三，但是不能用方法四

func main() {
	// 方式一
	// 默认的值是0
	var a int
	fmt.Println("a = ", a)
	fmt.Printf("type of a is %T\n", a)

	// 方式二
	// 声明一个变量，初始化一个值
	var b int = 100
	fmt.Println("b = ", b)
	fmt.Printf("type of b is %T\n", b)

	// 方式三
	// 在初始化的时候赋值，可以省略数据类型
	var c = 100
	fmt.Println("c = ", c)

	// 方法四
	// 省略关键字，直接自动匹配
	// 只能用在函数体内
	d := 100
	fmt.Println("d = ", d)

	// 声明多个变量
	// 多个相同类型的变量
	// 声明并赋值
	var x1, x2 int = 1, 2

	// 先声明后赋值
	var xx1, xx2 int
	xx1 = 1
	xx2 = 2
	fmt.Println(xx1, xx2)

	fmt.Println(x1, x2)

	// 多个类型不同的变量
	var y1, y2 = 1, "y2"
	fmt.Println(y1, y2)

	// 多个类型不同的变量的另一种声明形式
	var (
		z1 int    = 1
		z2 string = "z2"
	)
	fmt.Println(z1, z2)
}
