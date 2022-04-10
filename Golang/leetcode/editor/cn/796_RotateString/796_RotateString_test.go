package RotateString

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestRotateString(t *testing.T) {
	assert.True(t, rotateString("aba", "aba"))
	assert.True(t, rotateString("abcde", "bcdea"))
	assert.True(t, rotateString("abcde", "cdeab"))
	assert.False(t, rotateString("abcde", "abced"))
	assert.False(t, rotateString("aaaa", "aaab"))
}
