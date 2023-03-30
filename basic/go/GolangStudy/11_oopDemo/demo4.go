package main

import "fmt"

// interface{}是万能数据类型，空接口，各种基本数据类型都实现了interface
// 可以使用interface类型引用任意的数据类型
func myFunc(arg interface{}) {
	fmt.Println("myFunc is called")
	fmt.Println(arg)

	// interface{}如何区分此是引用的是哪个数据类型
	// 断言机制，仅支持interface{}
	value, ok := arg.(string)

	if !ok {
		fmt.Println("arg is not string type")
	} else {
		fmt.Println("arg is string type, value = ", value)
		fmt.Printf("value type is %T\n", value)
	}
}

type Book struct {
	auth string
}

func main() {
	book := Book{"Golang"}
	myFunc(book)
	myFunc("String")
}
