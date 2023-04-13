package main

import "fmt"

// 声明一种新的数据类型myint
type myint int

type Book struct {
	title string
	auth  string
}

// 正常传递副本
// 可使用指针
func changeBook(book *Book) {
	book.auth = "Mike"
}

func main() {
	var book1 Book
	book1.title = "go"
	book1.auth = "Tom"

	fmt.Println(book1)
	changeBook(&book1)
	fmt.Println(book1)
}
