package main

func main() {
	// 都属于main包，同一个包中无需import
	server := NewServer("127.0.0.1", 8888)
	server.Start()
}
