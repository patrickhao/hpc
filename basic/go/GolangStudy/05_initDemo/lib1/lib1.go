package lib1

import "fmt"

// 在golang中，方法名首字母小写只有包内可访问，类似于private，首字母大写可在其他包中访问，类似于public

func Test1() {
	fmt.Println("lib1Test...")
}

func init() {
	fmt.Println("lib1 init...")
}
