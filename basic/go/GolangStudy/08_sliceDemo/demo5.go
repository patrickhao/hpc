package main

import "fmt"

// 切片的截取
func main() {
	s := []int{1, 2, 3}

	s1 := s[0:2]

	fmt.Println(s1)

	// 长度为2，容量为3，拷贝了s中的前两个，但是容量为s的容量
	fmt.Printf("%d, %d, %v\n", len(s1), cap(s1), s1)

	// 指向同一个地址，改变s1，s中的元素也会改变
	s1[0] = 100
	fmt.Println(s)
	fmt.Println(s1)

	// copy 可以将底层数组的slice一起拷贝
	s2 := make([]int, 3)

	// 将s中的值依此拷贝到s2中
	// s2指向另一个地址
	copy(s2, s)
	fmt.Println(s2)
}
