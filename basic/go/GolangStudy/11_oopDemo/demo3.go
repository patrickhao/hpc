package main

import "fmt"

// 本质是一个指针
type AnimalIF interface {
	Sleep()
	GetColor() string // 获取动物颜色
	GetType() string  // 获取动物种类
}

// 具体的类
// 不需要显示的继承接口，只需要实现接口中的所有方法，就相当于继承了接口
// 可以使用接口实现多态
type Cat struct {
	color string
}

// 想要使用接口，必须重写全部方法
func (this *Cat) Sleep() {
	fmt.Println("Cat Sleep")
}

func (this *Cat) GetColor() string {
	return this.color
}

func (this *Cat) GetType() string {
	return "Cat"
}

type Dog struct {
	color string
}

// 想要使用接口，必须重写全部方法
func (this *Dog) Sleep() {
	fmt.Println("Dog Sleep")
}

func (this *Dog) GetColor() string {
	return this.color
}

func (this *Dog) GetType() string {
	return "Dog"
}

// 多态
func showAnimal(animal AnimalIF) {
	animal.Sleep()
	fmt.Println("color = ", animal.GetColor())
}

func main() {
	// 接口数据类型，父类指针
	var animal AnimalIF
	animal = &Cat{"Yellow"}
	// 调用的Cat的Sleep方法
	animal.Sleep()

	animal = &Dog{"Blue"}
	animal.Sleep()

	cat := Cat{"Yellow"}
	dog := Dog{"Blue"}

	// 接口是指针，因此传递指针进去
	showAnimal(&cat)
	showAnimal(&dog)
}
