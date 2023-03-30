package main

import (
	"fmt"
	"reflect"
)

func reflectNum(arg interface{}) {
	// 反射出interface{}的type和value
	fmt.Println("type: ", reflect.TypeOf(arg))
	fmt.Println("value: ", reflect.ValueOf(arg))
}

func main() {
	var num float64 = 1.2345
	reflectNum(num)
}
