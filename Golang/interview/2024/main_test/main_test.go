package interview

import (
	"fmt"
	"testing"
)

// 生产者 消费者模型

func Product(pipe chan int, done chan int) {
	for i := range 100 {
		pipe <- i
	}

	done <- 1

}

func Comsumer(pipe chan int, done chan int) {
	for i := range pipe {
		fmt.Printf("%d ", i)
	}

	done <- 1
}

func TestMain(t *testing.T) {
	sDone := make(chan int, 1)
	rDone := make(chan int, 1)
	pipe := make(chan int, 1)

	defer close(rDone)
	defer close(sDone)

	go Product(pipe, sDone)
	go Comsumer(pipe, rDone)

	<-sDone
	close(pipe)
	<-rDone

	fmt.Println("hello")
}
