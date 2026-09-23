package interview

import (
	"math"
	"testing"

	"github.com/stretchr/testify/require"
)

/*
标题：小于 n 的最大数

待实现函数：
func MaxNumberLessThanN(n int, digits []int) int

约定：
- digits 可无序，可能包含 0。
- 返回值不能有前导 0。
- 如果不存在小于 n 的合法非负整数，返回 -1。
*/

func TestMaxNumberLessThanN(t *testing.T) {
	tests := []struct {
		name   string
		n      int
		digits []int
		want   int
	}{
		{
			name:   "zero is a valid answer below one",
			n:      1,
			digits: []int{0, 2},
			want:   0,
		},
		{
			name:   "empty digit set has no valid answer",
			n:      100,
			digits: nil,
			want:   -1,
		},
		{
			name:   "unfinished prefix must not introduce unavailable zero digits",
			n:      2219,
			digits: []int{2, 4},
			want:   444,
		},
		{
			name:   "first digit failure uses the largest shorter number",
			n:      13,
			digits: []int{2, 3},
			want:   3,
		},
		{
			name:   "minimum int has no valid nonnegative answer",
			n:      math.MinInt,
			digits: []int{1},
			want:   -1,
		},
		{
			name:   "zero is valid when no positive number is smaller than n",
			n:      2,
			digits: []int{0, 2},
			want:   0,
		},
		{
			name:   "no valid answer",
			n:      1,
			digits: []int{2, 3},
			want:   -1,
		},
		{
			name:   "duplicate digits still require a strictly smaller number",
			n:      222,
			digits: []int{2, 2},
			want:   22,
		},
		{
			name:   "uses shorter length when first digit has no candidate",
			n:      20,
			digits: []int{2, 4},
			want:   4,
		},
		{
			name:   "backtracks past duplicate digits to a strictly smaller digit",
			n:      5530,
			digits: []int{8, 5, 4, 5},
			want:   5488,
		},
		{
			name:   "backtracks multiple positions when digits contain duplicates",
			n:      5440,
			digits: []int{5, 4, 8, 5},
			want:   4888,
		},
		{
			name:   "zero is a valid answer below one",
			n:      1,
			digits: []int{0, 2},
			want:   0,
		},
		{
			name:   "backtrack previous digit when current digit has no candidate",
			n:      5530,
			digits: []int{4, 5, 8},
			want:   5488,
		},
		{
			name:   "rebuilds all digits after backtracking requires a shorter length",
			n:      331,
			digits: []int{3, 5},
			want:   55,
		},
		{
			name:   "zero is the only available digit",
			n:      10,
			digits: []int{0},
			want:   0,
		},
		{
			name:   "uses shorter length when all same-length numbers are too large",
			n:      1000,
			digits: []int{0, 1, 9},
			want:   999,
		},
		{
			name:   "sample",
			n:      23121,
			digits: []int{2, 4, 9},
			want:   22999,
		},
		{
			name:   "same length with smaller suffix",
			n:      3456,
			digits: []int{3, 4, 5},
			want:   3455,
		},
		{
			name:   "strictly less than n",
			n:      222,
			digits: []int{2},
			want:   22,
		},
		{
			name:   "zero can be used but cannot be the leading digit",
			n:      200,
			digits: []int{2, 0},
			want:   22,
		},
		{
			name:   "zero in digits should not shift the first digit index",
			n:      250,
			digits: []int{0, 2, 4},
			want:   244,
		},
		{
			name:   "only smaller one-digit number exists",
			n:      5,
			digits: []int{1, 7},
			want:   1,
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			var got int
			require.NotPanics(t, func() {
				got = MaxNumberLessThanN(tt.n, tt.digits)
			})
			require.Equal(t, tt.want, got)
		})
	}
}
