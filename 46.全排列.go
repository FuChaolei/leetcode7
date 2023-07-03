/*
 * @lc app=leetcode.cn id=46 lang=golang
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (78.27%)
 * Likes:    1543
 * Dislikes: 0
 * Total Accepted:    409.6K
 * Total Submissions: 523.3K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,1]
 * 输出：[[0,1],[1,0]]
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1]
 * 输出：[[1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * -10
 * nums 中的所有整数 互不相同
 *
 *
 */

// @lc code=start
func permute(nums []int) [][]int {
	n := len(nums)
	res := [][]int{}
	path := []int{}
	used := make([]int, n)
	var dfs func()
	dfs = func() {
		if len(path) == n {
			tmp := make([]int, n)
			copy(tmp, path)
			res = append(res, tmp)
			return
		}
		for i := 0; i < n; i++ {
			if used[i] == 1 {
				continue
			}
			used[i] = 1
			path = append(path, nums[i])
			dfs()
			path = path[:len(path)-1]
			used[i] = 0
		}
	}
	dfs()
	return res
}

// @lc code=end

