package main

import "fmt"

// 切片是引用传递，传递的是指针
func printArray(myArray []int) {
	// _表示匿名变量
	for _, value := range myArray {
		fmt.Println("value = ", value)
	}
}

func main() {
	// 动态数组本身是指向内存中的指针的
	myArray := []int{1, 2, 3}

	fmt.Printf("myArray type is %T\n", myArray)

	printArray(myArray)
}
