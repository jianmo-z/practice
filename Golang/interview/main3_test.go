package interview

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func isSame(old, cur int, str string) bool {
	if old >= cur {
		return false
	}

	end := cur
	for old < end {
		if cur >= len(str) {
			return false
		}
		if str[old] != str[cur] {
			return false
		}
		old++
		cur++
	}

	return true
}

func IsSubStr(sub, str string) bool {

	for i := range str {
		if str[i] != sub[i%len(sub)] {
			return false
		}
	}

	return true
}

func IsRepeat(str string) bool {
	if len(str) <= 1 {
		return false
	}

	set := map[int][]int{}

	for i, ch := range str {
		idxs, has := set[int(ch)]
		set[int(ch)] = append(set[int(ch)], i)
		if !has {
			continue
		}

		for _, idx := range idxs {
			if isSame(idx, i, str) {
				subStr := str[idx : i-idx]

				if IsSubStr(subStr, str) {
					return true
				}
			}
		}

	}

	return false
}

func TestMain3(t *testing.T) {
	assert.False(t, IsRepeat(""))
	assert.False(t, IsRepeat("a"))
	assert.True(t, IsRepeat("aaaa"))
	assert.True(t, IsRepeat("ababab"))
	assert.True(t, IsRepeat("abababab"))
	assert.False(t, IsRepeat("abcab"))
	assert.False(t, IsRepeat("abcdbcd"))
	assert.True(t, IsRepeat("abcdaabcda"))
}

/*
1111

0-1 -> 0-15 -> 1/16 -> 1/16 * 9 -> 10/16 -> 1 -> 1/16 -> 10/16 -> (1/16 / 10/16) = 1/10

[0, 15]

[0, 9] [10, 15]

16 -> 6 = 6 / 16 -> 1

x^2 -> 10
 1 2 4 8 16 32 64 -> 1024 -> 102 * 10 ··· 4 -> 4 / 1024 -> 102 -> [1, 7, 0]


*/
