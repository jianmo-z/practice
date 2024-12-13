package interview

import (
	"fmt"
	"sync"
	"testing"
	"time"
)

/*
编写一个并发程序，从2个函数getfromdb,getfromcache,获取数据，要求2个函数获取数据合并后返回，
其中db的超时时间不能超过100ms，cache获取不超过50ms，整个函数不超过200ms，
要求不能有协程泄露
*/

func getFromDB() int {
	time.Sleep(time.Millisecond * 100)
	return 1
}

func getFromCache() int {
	time.Sleep(time.Millisecond * 100)
	return 2
}

func WithDDL(task func() int, duration time.Duration) (data int, has bool) {
	taskDone := make(chan int, 0)

	go func() {
		taskDone <- task()
	}()

	select {
	case <-time.After(duration):
		return -1, false
	case data = <-taskDone:
		return data, true
	}
}

func QueryData() (int, int) {
	group := sync.WaitGroup{}
	group.Add(2)
	db, cache := -1, -1

	go func() {
		defer group.Done()

		dbData, dbOk := WithDDL(getFromDB, time.Millisecond*100)
		if dbOk {
			db = dbData
		}
	}()

	go func() {
		defer group.Done()

		cacheData, cacheOk := WithDDL(getFromCache, time.Millisecond*50)
		if cacheOk {
			cache = cacheData
		}
	}()

	group.Wait()

	return db, cache
}

func TestMain2(t *testing.T) {
	var dbData, cacheData int

	WithDDL(func() int {
		dbData, cacheData = QueryData()
		return 0
	}, time.Millisecond*200)

	fmt.Println(dbData, cacheData)
}
