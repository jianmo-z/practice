package interview_test

import (
	"fmt"
	"testing"
)

/*

回旋输出矩阵
示例：
输入 2，输出：
	1 2
	4 3

输入3，输出：
	1 2 3
	8 9 4
	7 6 5
*/

func generateMatrix(n int) [][]int {
	matrix := make([][]int, n)

	for i := range matrix {
		matrix[i] = make([]int, n)
	}

	return matrix
}

func PrintMatrix(n int) [][]int {
	matrix := generateMatrix(n)

	midX, midY := n/2, n/2
	x, y := 0, 0
	startX, startY := 0, 0
	endX, endY := n-1, n-1

	index := 0
	for x <= midX && y <= midY {

		if x == midX && y == midY {
			if n%2 == 1 {
				index++
				matrix[x][y] = index
			}
			break
		}

		// (上)左 -> 右
		for ; y < endY; y++ {
			index++
			matrix[x][y] = index
		}

		// (右)上 -> 下
		for ; x < endX; x++ {
			index++
			matrix[x][y] = index
		}

		// (下)右 -> 左
		for ; y > startY; y-- {
			index++
			matrix[x][y] = index
		}

		// (左)下 -> 上
		for ; x > startX; x-- {
			index++
			matrix[x][y] = index
		}

		x += 1
		y += 1
		startX += 1
		startY += 1
		endX -= 1
		endY -= 1
	}

	return matrix
}

func printMatrix(items [][]int) {
	for _, item := range items {
		fmt.Println(item)
	}
}

func TestMain6(t *testing.T) {
	printMatrix(PrintMatrix(1))
	printMatrix(PrintMatrix(2))
	printMatrix(PrintMatrix(3))
}
