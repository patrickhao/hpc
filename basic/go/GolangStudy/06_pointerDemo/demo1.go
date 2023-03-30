package main

import "fmt"

func swap(a *int, b *int) {
	// 若只交换a, b指向的地址，本质上还是在改变传递进来的值，而没有改变地址上的内容
	var temp int
	temp = *a
	*a = *b
	*b = temp
}

func main() {
	a := 1
	b := 2
	swap(&a, &b)

	fmt.Println(a)
	fmt.Println(b)
}
