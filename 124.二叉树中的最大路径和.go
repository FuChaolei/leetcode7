/*
 * @lc app=leetcode.cn id=124 lang=golang
 *
 * [124] 二叉树中的最大路径和
 *
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (44.38%)
 * Likes:    1223
 * Dislikes: 0
 * Total Accepted:    156.6K
 * Total Submissions: 352.6K
 * Testcase Example:  '[1,2,3]'
 *
 * 路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个
 * 节点，且不一定经过根节点。
 *
 * 路径和 是路径中各节点值的总和。
 *
 * 给你一个二叉树的根节点 root ，返回其 最大路径和 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,3]
 * 输出：6
 * 解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
 *
 * 示例 2：
 *
 *
 * 输入：root = [-10,9,20,null,null,15,7]
 * 输出：42
 * 解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目范围是 [1, 3 * 10^4]
 * -1000
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxPathSum(root *TreeNode) int {
	if root == nil {
		return 0
	}
	res := math.MinInt32
	var maxR func(*TreeNode) int
	maxR = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		l := max(maxR(root.Left), 0)
		r := max(maxR(root.Right), 0)
		res = max(res, l+r+root.Val)
		return max(l, r) + root.Val
	}
	maxR(root)
	return res
}
func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

// @lc code=end

