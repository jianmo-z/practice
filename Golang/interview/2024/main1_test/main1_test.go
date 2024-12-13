package interview

import (
	"fmt"
	"sync"
	"testing"
	"time"
)

/*
两个协程交替交替输出 奇偶数
*/

func PrintNum1(pipe chan int, lock1, lock2 *sync.Mutex) {
	for {
		lock2.Lock()

		begin := <-pipe
		fmt.Println("go1: ", begin)

		time.Sleep(time.Millisecond * 200)

		pipe <- begin + 1

		lock1.Unlock()
	}
}

func PrintNum2(pipe chan int, lock1, lock2 *sync.Mutex) {
	for {
		lock1.Lock()

		begin := <-pipe
		fmt.Println("go2: ", begin)

		time.Sleep(time.Millisecond * 100)

		pipe <- begin + 1

		lock2.Unlock()
	}
}

func TestMain1(t *testing.T) {

	lock1 := &sync.Mutex{}
	lock2 := &sync.Mutex{}

	lock1.Lock()

	pipe := make(chan int, 1)
	pipe <- 1

	go PrintNum1(pipe, lock1, lock2)
	go PrintNum2(pipe, lock1, lock2)

	time.Sleep(time.Hour * 1)
}
