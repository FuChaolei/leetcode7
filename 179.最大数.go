/*
 * @lc app=leetcode.cn id=179 lang=golang
 *
 * [179] 最大数
 *
 * https://leetcode.cn/problems/largest-number/description/
 *
 * algorithms
 * Medium (41.16%)
 * Likes:    1121
 * Dislikes: 0
 * Total Accepted:    196.1K
 * Total Submissions: 476.7K
 * Testcase Example:  '[10,2]'
 *
 * 给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
 *
 * 注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [10,2]
 * 输出："210"
 *
 * 示例 2：
 *
 *
 * 输入：nums = [3,30,34,5,9]
 * 输出："9534330"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 10^9
 *
 *
 */

// @lc code=start
func largestNumber(nums []int) string {
	sort.Slice(nums, func(i, j int) bool {
		sx, sy := 10, 10
		x, y := nums[i], nums[j]
		for sx <= x {
			sx *= 10
		}
		for sy <= y {
			sy *= 10
		}
		return sy*x+y > sx*y+x
	})
	res := ""
	if nums[0] == 0 {
		return "0"
	}
	for _, s := range nums {
		res += strconv.Itoa(s)
	}
	return res
}

// @lc code=end

