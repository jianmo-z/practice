package main

import (
	"fmt"
	"time"
)

func main() {
	var mem [][]byte

	sum := uint64(0)

	for i := 0; i < 8*1024; i++ {
		memCnt := uint64(1024 * 1024)
		data := make([]byte, 0, memCnt) // 1MB
		sum += memCnt
		fmt.Println("alloc:", sum/1024/1024)
		mem = append(mem, data)
	}

	time.Sleep(time.Hour * 1)
}
