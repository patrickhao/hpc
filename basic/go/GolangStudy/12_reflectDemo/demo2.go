package main

import "fmt"

type Reader interface {
	ReadBook()
}

type Writer interface {
	WriteBook()
}

type Book struct {
}

func (this Book) ReadBook() {
	fmt.Println("Read book")
}

func (this Book) WriteBook() {
	fmt.Println("Write book")
}

func main() {
	// b: pair<type:Book, value:Book{}地址>
	b := &Book{}

	var r Reader
	// r: pair<type:Book, value:Book{}地址>
	r = b
	r.ReadBook()

	var w Writer
	w = r.(Writer)
	// w: pair<type:Book, value:Book{}地址>
	// 此处的断言成功，因为其中的w和r的type是一致的，都是Book
	// Book重写了Reader和Writer，因此两个都可以指向Book
	w.WriteBook()

	value, ok := r.(Writer)
	fmt.Println(value)
	fmt.Println(ok)
}
