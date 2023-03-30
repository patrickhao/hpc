package main

import "fmt"

func main() {
	// 第一种声明方式
	var myMap1 map[string]string
	myMap1 = make(map[string]string, 10)

	myMap1["one"] = "c"
	myMap1["two"] = "c++"
	myMap1["three"] = "go"

	fmt.Println(myMap1)

	// 第二种声明方式
	myMap2 := make(map[int]string)
	myMap2[1] = "c"
	myMap2[2] = "c++"
	myMap2[3] = "go"
	fmt.Println(myMap2)

	// 第三种声明方式
	myMap3 := map[string]string{
		"one":   "c",
		"two":   "c++",
		"three": "go",
	}
	fmt.Println(myMap3)

}
