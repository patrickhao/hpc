package main

import "fmt"

// 类名首字母大写，表示该属性能够对外访问
type Hero struct {
	Name  string
	Ad    int
	Level int
}

// this是调用该方法的对象的一个副本（拷贝）
// 方法首字母大写，其他包中可以访问，否则只有当前方法内能访问
func (this Hero) Show() {
	fmt.Println(this.Name)
	fmt.Println(this.Ad)
	fmt.Println(this.Level)
}

func (this Hero) GetName() string {
	return this.Name
}

// *Hero不再是一个拷贝，是指针，直接指向其地址
// 可以理解为this是Hero指针类型，是一种特殊的变量名，表示该类的实例
func (this *Hero) SetName(newName string) {
	this.Name = newName
}

func main() {
	// 创建一个对象
	hero := Hero{Name: "Tom", Ad: 100, Level: 1}
	hero.Show()

	hero.SetName("Mike")
	hero.Show()
}
