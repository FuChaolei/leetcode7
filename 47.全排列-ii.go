/*
 * @lc app=leetcode.cn id=47 lang=golang
 *
 * [47] 全排列 II
 *
 * https://leetcode.cn/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (65.48%)
 * Likes:    1346
 * Dislikes: 0
 * Total Accepted:    446.7K
 * Total Submissions: 682.1K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,1,2]
 * 输出：
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 *
 *
 */

// @lc code=start
func permuteUnique(ls []int) [][]int {
	sort.Ints(ls)
	res := [][]int{}
	path := []int{}
	n := len(ls)
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
			if used[i] == 1 || (i > 0 && used[i-1] == 0 && ls[i] == ls[i-1]) {
				continue
			}
			used[i] = 1
			path = append(path, ls[i])
			dfs()
			path = path[:len(path)-1]
			used[i] = 0
		}
	}
	dfs()
	return res
}

// @lc code=end

