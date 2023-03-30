package main

import "fmt"

type Human struct {
	name   string
	gender string
}

func (this *Human) Eat() {
	fmt.Println("Human eat")
}

func (this *Human) Walk() {
	fmt.Println("Human walk")
}

type SuperMan struct {
	Human // SuperMan类继承了Human类的方法
	level int
}

// 重写
func (this *SuperMan) Eat() {
	fmt.Println("SuperMan eat")
}

// 子类的新方法
func (this *SuperMan) Fly() {
	fmt.Println("SuperMan fly")
}

func main() {
	h := Human{"Tom", "female"}
	h.Eat()
	h.Walk()

	// s := SuperMan{Human{"Tom", "man"}, 8}
	var s SuperMan
	s.name = "Tom"
	s.gender = "man"
	s.level = 8
	s.Eat()
	s.Walk()
}
