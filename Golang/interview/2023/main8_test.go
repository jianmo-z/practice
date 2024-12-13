package interview

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"strconv"
	"strings"
	"testing"
)

/*
计算两个日期之间相差多少天
编写一个程序来计算两个日期之间相隔多少天。日期以字符串格式 `YYYY-MM-DD` 给出，比如 “2010-12-01”。

- 日期范围：1970 年到 2100 年之间的任何一天
- 不能使用系统内置日期模块

参考资料：

- 一年当中，1,3,5,7,8,10,12 月包含31天，2月包含28天，剩余月份为30天
- 闰年的2月包含29天
- 判断某年份是否为闰年：(year % 4 == 0 && year % 100 != 0) || year % 400 == 0

执行样例：


GetDaysBetween("2019-06-29", "2019-06-30")
// 返回结果：1
GetDaysBetween("2020-01-15", "2019-12-31")
// 返回结果：15
*/

var monthDays = [][]int{
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
}

type Date struct {
	Year  int
	Month int
	Day   int
}

func (d *Date) IsRun() bool {
	return (d.Year%4 == 0 && d.Year%100 != 0) || d.Year%400 == 0
}

func (d *Date) GetDays() int {
	d.Year -= 1970

	sum := 0

	sum += d.Year*365 - d.Year/4 + d.Year/100 - d.Year/400

	days := monthDays[0]
	if d.IsRun() {
		days = monthDays[1]
	}

	for i, day := range days {
		if d.Month > i+1 {
			sum += day
		}
	}

	return sum + d.Day
}

func RangeDays(bData, eData *Date) int {
	return bData.GetDays() - eData.GetDays()
}

func IsGreater(begin, end *Date) bool {
	if begin.Year > end.Year {
		return true
	}
	if begin.Month > end.Month {
		return true
	}

	return begin.Day > end.Day
}

func ParseDate(date string) (*Date, error) {
	list := strings.Split(date, "-")
	if len(list) != 3 {
		return nil, fmt.Errorf("wrong date format")
	}

	year, err := strconv.Atoi(list[0])
	if err != nil {
		return nil, err
	}
	month, err := strconv.Atoi(list[1])
	if err != nil {
		return nil, err
	}
	day, err := strconv.Atoi(list[2])
	if err != nil {
		return nil, err
	}

	return &Date{
		Year:  year,
		Month: month,
		Day:   day,
	}, nil

}

func GetDaysBetween(begin, end string) int {
	bDate, err := ParseDate(begin)
	if err != nil {
		return -1
	}
	eDate, err := ParseDate(end)
	if err != nil {
		return -1
	}

	if !IsGreater(bDate, eDate) {
		bDate, eDate = eDate, bDate
	}

	return RangeDays(bDate, eDate)
}

func TestMain8(t *testing.T) {
	assert.Equal(t, 1, GetDaysBetween("2019-06-29", "2019-06-30"))
	assert.Equal(t, 15, GetDaysBetween("2020-01-15", "2019-12-31"))
}
