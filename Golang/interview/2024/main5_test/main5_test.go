package interview

import (
	"errors"
	"fmt"
	"sync/atomic"
	"testing"
	"time"
)

type Limit struct {
	limit int
	Slot  int
	Count uint32
}

var curClimt = &Limit{}

func timerUpdate() {
	timer := time.Tick(time.Second)

	for {
		select {
		case <-timer:
			curSlot := time.Now().Second() / 60
			if curClimt.Slot != curSlot {
				curClimt = &Limit{
					Slot: curSlot,
				}
			}
		}
	}
}

func NewReq() error {
	newValue := atomic.AddUint32(&curClimt.Count, 1)
	if int(newValue) > curClimt.limit {
		return errors.New("over limit")
	}

	return nil
}

func TestMain5(t *testing.T) {
	a := 0.1
	b := 0.2
	fmt.Println(0.1 + 0.2)
	fmt.Println(a + b)
}
