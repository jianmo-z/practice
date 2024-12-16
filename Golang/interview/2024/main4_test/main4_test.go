package main

import (
	"fmt"
	"sync"
	"testing"

	"github.com/stretchr/testify/assert"
)

/*
	时间复杂度：
	zadd, zset, zscore

	select
		grade, count(*) as count
	from students
	where
		gender = 0 and name != '' and name is not null
	group by
		grade
	order by
		count desc

	订单表：uid, oid, status


	[
		(2,1,A),(1,1,B)
		(1,1,C)
	]

*/

func countX(arr [][]int) int {
	xCount := len(arr)

	total := 0

	for i := 0; i < xCount; {
		val := arr[i][0]
		i += val
		total += val
	}

	return total
}

func TestCountX(t *testing.T) {
	res := countX([][]int{
		{2, 1},
		{1},
		{1, 1},
	})

	assert.Equal(t, 3, res)
}

// 并发获取用户年龄，map[int]int key 是用户ID，value 是年龄
func ParellelGetUserAges(ids []int) map[int]int {
	res := make([]int, len(ids)) // idx -> age
	sig := sync.WaitGroup{}
	sig.Add(len(ids))

	for i := 0; i < len(ids); i++ {
		go func(i int) {
			defer sig.Done()

			age := getUserAgeFromDB(ids[i])
			res[i] = age
		}(i)
	}

	sig.Wait()

	records := map[int]int{} // id -> age
	for i := 0; i < len(res); i++ {
		records[ids[i]] = res[i]
	}

	return records
}

// 为了简化，假设 getUserAgeFromDB 就是从数据库获取用户的年龄
// 上面的函数需要并发的调用这个函数
func getUserAgeFromDB(id int) int {
	return id - 1
}

func TestParellelGetUserAges(t *testing.T) {
	records := ParellelGetUserAges([]int{2, 4, 6, 8, 10})
	fmt.Println(records)
}
