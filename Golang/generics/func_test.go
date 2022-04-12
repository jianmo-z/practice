package generics

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func add[T ~int | float64](a ...T) T {
	var sum T
	for _, t := range a {
		sum += t
	}

	return sum
}

type myType = int

func TestAdd(t *testing.T) {
	assert.Equal(t, 10, add(1, 2, 3, 4))
	assert.Equal(t, 10.4, add(1.1, 2.1, 3.1, 4.1))
	assert.Equal(t, myType(10), add(myType(1), myType(2), myType(3), myType(4)))
}
