package main

import "fmt"

// 传递map，传递的是指针
func printMap(m map[string]string) {
	for key, value := range m {
		fmt.Println(key, value)
	}
}

func main() {
	cityMap := make(map[string]string)

	// 添加
	cityMap["China"] = "Beijing"
	cityMap["Japan"] = "Tokyo"

	// 遍历
	for key, value := range cityMap {
		fmt.Println(key, value)
	}

	// 删除
	delete(cityMap, "Japan")

	// 修改
	cityMap["China"] = "Shanghai"
}
