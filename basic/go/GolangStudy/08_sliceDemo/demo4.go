package main

import (
	"fmt"
)

func main() {
	// 长度为3，容量为5
	// 长度是里面现在存的数的数量，容量是该切片能存的容量
	var numbers = make([]int, 3, 5)

	fmt.Printf("len = %d, slice = %d, value = %v\n", len(numbers), cap(numbers), numbers)

	// 向numbers切片追加一个元素1
	numbers = append(numbers, 1)
	fmt.Printf("len = %d, slice = %d, value = %v\n", len(numbers), cap(numbers), numbers)

	numbers = append(numbers, 2)
	fmt.Printf("len = %d, slice = %d, value = %v\n", len(numbers), cap(numbers), numbers)

	// 再次追加，已经满了，go会动态的增加切片长度，容量翻倍
	numbers = append(numbers, 3)
	fmt.Printf("len = %d, slice = %d, value = %v\n", len(numbers), cap(numbers), numbers)

}
