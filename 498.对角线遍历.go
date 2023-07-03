/*
 * @lc app=leetcode.cn id=498 lang=golang
 *
 * [498] 对角线遍历
 *
 * https://leetcode.cn/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (55.72%)
 * Likes:    445
 * Dislikes: 0
 * Total Accepted:    106K
 * Total Submissions: 190K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,4,7,5,3,6,8,9]
 *
 *
 * 示例 2：
 *
 *
 * 输入：mat = [[1,2],[3,4]]
 * 输出：[1,2,3,4]
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 10^4
 * 1 <= m * n <= 10^4
 * -10^5 <= mat[i][j] <= 10^5
 *
 *
 */
// https://www.bilibili.com/video/BV1jD4y1W77P/
// @lc code=start
func findDiagonalOrder(mat [][]int) []int {
	t := len(mat)
	r := len(mat[0])
	res := make([]int, r*t)
	if t == 0 {
		return res
	}
	l, b := 0, 0
	idx := 0
	for i := 0; i < r+t-1; i++ {
		//判断对角线奇偶性
		if i%2 == 0 {
			for l < r && b >= 0 {
				res[idx] = mat[b][l]
				b--
				l++
				idx++
			}
			if l == r {
				b += 2
				l--
			} else {
				b++
			}
		} else {
			for l >= 0 && b < t {
				res[idx] = mat[b][l]
				b++
				l--
				idx++
			}
			if b == t {
				l += 2
				b--
			} else {
				l++
			}
		}
	}
	return res
}

// @lc code=end

