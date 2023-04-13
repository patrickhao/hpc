package main

import (
	// 下划线+空格，匿名导入，未使用也不报错，同时调用lib1的init方法
	// 无法使用包中的方法，但是会使用init方法
	_ "GolangStudy/05_initDemo/lib1"
	// 也可以使用其他别名，然后使用别名调用
	// lib22 "GolangStudy/05_initDemo/lib2"
	// 或者使用. 这样在使用时可以不说明包名，直接调用方法
	// 谨慎使用，因为有可能不同的包中有冲突
	// . "GolangStudy/05_initDemo/lib2"
	"GolangStudy/05_initDemo/lib2"
)

func main() {
	// lib1.Test1()
	lib2.Test2()
}
