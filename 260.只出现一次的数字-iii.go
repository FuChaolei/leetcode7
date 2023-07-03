/*
 * @lc app=leetcode.cn id=260 lang=golang
 *
 * [260] 只出现一次的数字 III
 *
 * https://leetcode.cn/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (72.17%)
 * Likes:    723
 * Dislikes: 0
 * Total Accepted:    111.8K
 * Total Submissions: 155.1K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * 给你一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。
 *
 * 你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,1,3,2,5]
 * 输出：[3,5]
 * 解释：[5, 3] 也是有效的答案。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [-1,0]
 * 输出：[-1,0]
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [0,1]
 * 输出：[1,0]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= nums.length <= 3 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * 除两个只出现一次的整数外，nums 中的其他数字都出现两次
 *
 *
 */

// @lc code=start
func singleNumber(nums []int) []int {
	ret, n := 0, len(nums)
	for i := 0; i < n; i++ {
		ret ^= nums[i]
	}
	h := 1
	for (ret & h) == 0 {
		h <<= 1
	}
	a, b := 0, 0
	for i := 0; i < n; i++ {
		if (nums[i] & h) == 0 {
			a ^= nums[i]
		} else {
			b ^= nums[i]
		}
	}
	return []int{a, b}
}

// @lc code=end

