package main

import "fmt"

// golang中，变量要么是int、string等static type，要么是interface指向的concrete type
// 反射可以获得变量的type
func main() {
	var s string
	// pair<statictype:string, value:"a">
	s = "a"

	// pair<type:string, value:"a">
	// 赋值时a的pair传递过来
	var allType interface{}
	allType = s

	// value, ok
	str, _ := allType.(string)
	fmt.Println(str)
}
