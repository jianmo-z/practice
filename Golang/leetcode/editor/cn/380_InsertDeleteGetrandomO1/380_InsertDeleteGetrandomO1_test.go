package InsertDeleteGetrandomO1

import (
	"github.com/stretchr/testify/assert"
	"math/rand"
	"testing"
)

//实现RandomizedSet 类：
//
//
//
//
// RandomizedSet() 初始化 RandomizedSet 对象
// bool insert(int val) 当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false 。
// bool remove(int val) 当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false 。
// int getRandom() 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。每个元素应该有 相同的概率 被返回。
//
//
// 你必须实现类的所有函数，并满足每个函数的 平均 时间复杂度为 O(1) 。
//
//
//
// 示例：
//
//
//输入
//["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove",
//"insert", "getRandom"]
//[[], [1], [2], [2], [], [1], [2], []]
//输出
//[null, true, false, true, 2, true, false, 2]
//
//解释
//RandomizedSet randomizedSet = new RandomizedSet();
//randomizedSet.insert(1); // 向集合中插入 1 。返回 true 表示 1 被成功地插入。
//randomizedSet.remove(2); // 返回 false ，表示集合中不存在 2 。
//randomizedSet.insert(2); // 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
//randomizedSet.getRandom(); // getRandom 应随机返回 1 或 2 。
//randomizedSet.remove(1); // 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
//randomizedSet.insert(2); // 2 已在集合中，所以返回 false 。
//randomizedSet.getRandom(); // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
//
//
//
//
// 提示：
//
//
// -2³¹ <= val <= 2³¹ - 1
// 最多调用 insert、remove 和 getRandom 函数 2 * 10⁵ 次
// 在调用 getRandom 方法时，数据结构中 至少存在一个 元素。
//
//
//
// Related Topics 设计 数组 哈希表 数学 随机化 👍 539 👎 0

//leetcode submit region begin(Prohibit modification and deletion)
type RandomizedSet struct {
	nums []int       // 下标 --> 数字
	data map[int]int // 数字 --> 下标
}

func Constructor() RandomizedSet {
	return RandomizedSet{
		nums: make([]int, 0),
		data: make(map[int]int),
	}
}

func (this *RandomizedSet) Insert(val int) bool {
	_, has := this.data[val]
	if has {
		return false
	}

	this.data[val] = len(this.nums)
	this.nums = append(this.nums, val)

	return true
}

func (this *RandomizedSet) Remove(val int) bool {
	index, has := this.data[val]
	if !has {
		return false
	}

	// 用最后一个元素的下表填充，要删除的值

	last := len(this.nums) - 1

	// 更新map
	this.data[this.nums[last]] = index

	// 更新nums
	this.nums[index] = this.nums[last]

	// 删除值
	delete(this.data, val)
	this.nums = this.nums[:last]

	return true
}

func (this *RandomizedSet) GetRandom() int {
	return this.nums[rand.Intn(len(this.nums))]
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Insert(val);
 * param_2 := obj.Remove(val);
 * param_3 := obj.GetRandom();
 */
//leetcode submit region end(Prohibit modification and deletion)

func TestInsertDeleteGetrandomO1(t *testing.T) {
	randomizedSet := Constructor()
	assert.True(t, randomizedSet.Insert(1))  // 向集合中插入 1 。返回 true 表示 1 被成功地插入。
	assert.False(t, randomizedSet.Remove(2)) // 返回 false ，表示集合中不存在 2 。
	assert.True(t, randomizedSet.Insert(2))  // 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
	assert.False(t, randomizedSet.Insert(2)) // 向集合中插入 2 。返回 false 。集合现在包含 [1,2] 。
	//randomizedSet.GetRandom() // getRandom 应随机返回 1 或 2 。
	assert.True(t, randomizedSet.Remove(1))       // 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
	assert.False(t, randomizedSet.Insert(2))      // 2 已在集合中，所以返回 false 。
	assert.Equal(t, 2, randomizedSet.GetRandom()) // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。

	randomizedSet = Constructor()
	assert.True(t, randomizedSet.Insert(2))       // 向集合中插入 12 。返回 true 表示 2 被成功地插入。
	assert.False(t, randomizedSet.Remove(1))      // 返回 false ，表示集合中不存在 1 。
	assert.Equal(t, 2, randomizedSet.GetRandom()) // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
}
