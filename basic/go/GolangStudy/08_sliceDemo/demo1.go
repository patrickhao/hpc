package main

import "fmt"

// 传递是值拷贝
func printArray(a [3]int) {
	// 使用range返回的第一个是索引，第二个是数组中的值
	for index, value := range a {
		fmt.Println("index = ", index, "value = ", value)
	}
}

func main() {
	// 固定长度数组
	var myArray1 [10]int

	myArray2 := [10]int{1, 2, 3, 4}

	for i := 0; i < len(myArray1); i++ {
		fmt.Println(myArray1[i])
		fmt.Println(myArray2[i])
	}

	for index, value := range myArray2 {
		fmt.Println(index, value)
	}

	// 查看数组的数据类型
	fmt.Printf("myArray1 types = %T\n", myArray1)
	fmt.Printf("myArray2 types = %T\n", myArray2)

	myArray3 := [3]int{1, 2, 3}
	printArray(myArray3)

	// 需要数组长度匹配，否则会报错
	// printArray(myArray1)
}
