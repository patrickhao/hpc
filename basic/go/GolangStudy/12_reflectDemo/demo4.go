package main

import (
	"fmt"
	"reflect"
)

type User struct {
	Id   int
	Name string
	Age  int
}

func (this User) Call() {
	fmt.Println("user is called")
	fmt.Println(this)
}

func main() {
	user := User{1, "Tom", 18}
	DoFileAndMethod(user)

}

func DoFileAndMethod(input interface{}) {
	// 获取input的type
	inputType := reflect.TypeOf(input)
	fmt.Println("inputType is ", inputType.Name())

	// 获取input的value
	inputValue := reflect.ValueOf(input)
	fmt.Println("inputValue is ", inputValue)

	// 通过type获取里面的字段
	// 获取interface的reflcet.Type，通过Type得到Numfiled，进行遍历
	// 得到每个field，数据类型
	// 通过filed的Interface()方法得到对应的value
	for i := 0; i < inputType.NumField(); i++ {
		filed := inputType.Field(i)
		value := inputValue.Field(i).Interface()
		fmt.Printf("%s : %v = %v\n", filed.Name, filed.Type, value)
	}

	// 通过type获取里面的方法
	// Call传指针无法打印，传值可以
	for i := 0; i < inputType.NumMethod(); i++ {
		m := inputType.Method(i)
		fmt.Printf("%s : %v\n", m.Name, m.Type)
	}
}
