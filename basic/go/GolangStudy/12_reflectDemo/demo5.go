package main

import (
	"fmt"
	"reflect"
)

type People struct {
	// json标签中，:左右两侧不能有空格，否则该标签不被接受
	// 不是json格式的文件，而是一种标签，用来对该属性进行一些说明
	Name   string `info:"name" doc:"name_doc"`
	Gender string `info:"gender"`
}

func findTag(str interface{}) {
	t := reflect.TypeOf(str).Elem()

	for i := 0; i < t.NumField(); i++ {
		taginfo := t.Field(i).Tag.Get("info")
		tagdoc := t.Field(i).Tag.Get("doc")
		fmt.Println(taginfo, tagdoc)
	}

}

func main() {
	var a People
	// 由于是interface{}，传递指针进去
	findTag(&a)
}
