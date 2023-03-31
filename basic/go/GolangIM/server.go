package main

import (
	"fmt"
	"io"
	"net"
	"sync"
	"time"
)

type Server struct {
	Ip   string
	Port int

	// 在线用户的列表
	OnlineMap map[string]*User
	// 用户表的锁，可能有多个用户同时上线，加锁防止冲突，保证数据安全性
	mapLock sync.RWMutex

	// 用来广播的channel
	Message chan string
}

// 创建一个server的接口
func NewServer(ip string, port int) *Server {
	// 指向Server对象的指针
	server := &Server{
		Ip:        ip,
		Port:      port,
		OnlineMap: make(map[string]*User),
		Message:   make(chan string),
	}

	return server
}

// 监听Message广播消息channel的协程，一旦有消息就发送给全部在线User
func (this *Server) ListenMessage() {
	for {
		msg := <-this.Message

		// 将msg发送给全部的在线User
		this.mapLock.Lock()
		for _, cli := range this.OnlineMap {
			cli.C <- msg
		}
		this.mapLock.Unlock()
	}
}

// 广播消息
func (this *Server) BroadCase(user *User, msg string) {
	sendMsg := "[" + user.Addr + "]" + user.Name + msg

	this.Message <- sendMsg
}

func (this *Server) Handler(conn net.Conn) {
	// 处理当前连接的业务
	// fmt.Println("连接建立成功")

	user := NewUser(conn, this)

	// 广播当前用户上线消息
	user.Online()

	// 监听用户是否活跃的channel
	// 注意是个协程执行的函数，每个用户连接之后都有一个自己的Handler，这里的channel和后面的计时器都是针对当前用户的
	isLive := make(chan bool)

	// 用来接受客户端发送的消息
	go func() {
		buf := make([]byte, 4096)
		for {
			n, err := conn.Read(buf)
			if n == 0 {
				user.Offline()
				return
			}

			if err != nil && err != io.EOF {
				fmt.Println("Conn Read err:", err)
				return
			}

			// 提取用户的消息，去除'\n'
			msg := string(buf[:n-1])

			// 将得到的消息进行广播
			user.DoMessage(msg)

			// 用户的任意消息，表示当前用户是活跃的
			isLive <- true
		}
	}()

	// 当前handler阻塞
	for {
		select {
		// 使用 select 语句非阻塞地从两个通道中获取数据
		case <-isLive:
			// 当前用户是活跃的，应该重置定时器
			// 一旦出发这个case，什么都不写的话，会触发下面case的条件
			// 不做任何事情，激发下面的定时器
		case <-time.After(time.Second * 60): // 执行这句话的时候就表示重置了计时器
			// 已经超时

			// 将当前的User强制关闭
			user.SendMsg("你被踢了")

			// 销毁用户资源
			close(user.C)

			// 关闭连接
			conn.Close()

			return
			// runtime.Goexit()
		}
	}
}

// 启动服务器的借口
func (this *Server) Start() {
	// socket listen
	listener, err := net.Listen("tcp", fmt.Sprintf("%s:%d", this.Ip, this.Port))
	if err != nil {
		fmt.Println("net.Listen err:", err)
		return
	}
	// close listen socket
	defer listener.Close()

	// 启动监听message的协程
	go this.ListenMessage()

	for {
		// accept
		conn, err := listener.Accept()
		if err != nil {
			fmt.Println("listener accept err:", err)
			continue
		}

		// do handler
		go this.Handler(conn)

	}

	// clost listen socket
}
