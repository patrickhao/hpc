package main

import (
	"encoding/json"
	"fmt"
)

type Movie struct {
	Title  string   `json:"title"` // json告诉库该属性的含义
	Year   int      `json:"year"`
	Price  int      `json:"rmb"`
	Actors []string `json:"actors"`
}

func main() {
	movie := Movie{"Movie", 2000, 10, []string{"Tom", "Mike"}}
	// 编码
	jsonStr, err := json.Marshal(movie)
	if err != nil {
		fmt.Println("json marshal error ", err)
		return
	}
	fmt.Printf("jsonStr = %s\n", jsonStr)

	// 解码
	my_movie := Movie{}
	err = json.Unmarshal(jsonStr, &my_movie)
	if err != nil {
		fmt.Println("json unmarshal error ", err)
		return
	}
	fmt.Println(my_movie)
}
