package main // 程序的包名

// import "fmt"
// 多个包
import (
	"fmt"
	"time"
)

func main() {
	// golang中的语句加不加分号都一样，推荐不加
	fmt.Println("hello, world")
	time.Sleep(1 * time.Second)
	fmt.Println("1 second after")
}
