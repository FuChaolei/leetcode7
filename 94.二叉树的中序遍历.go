/*
 * @lc app=leetcode.cn id=94 lang=golang
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Easy (75.60%)
 * Likes:    1089
 * Dislikes: 0
 * Total Accepted:    546.6K
 * Total Submissions: 723.1K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树的根节点 root ，返回它的 中序 遍历。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,null,2,3]
 * 输出：[1,3,2]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [1]
 * 输出：[1]
 *
 *
 * 示例 4：
 *
 *
 * 输入：root = [1,2]
 * 输出：[2,1]
 *
 *
 * 示例 5：
 *
 *
 * 输入：root = [1,null,2]
 * 输出：[1,2]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [0, 100] 内
 * -100
 *
 *
 *
 *
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
func inorderTraversal(root *TreeNode) []int {
	st := []*TreeNode{}
	res := []int{}
	if root == nil {
		return res
	}
	cur := root
	for cur != nil || len(st) > 0 {
		if cur != nil {
			st = append(st, cur)
			cur = cur.Left
		} else {
			cur = st[len(st)-1]
			st = st[:len(st)-1]
			res = append(res, cur.Val)
			cur = cur.Right
		}
	}
	return res
}

// @lc code=end

