/*
 * @lc app=leetcode.cn id=912 lang=golang
 *
 * [912] 排序数组
 *
 * https://leetcode-cn.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (56.57%)
 * Likes:    361
 * Dislikes: 0
 * Total Accepted:    211.9K
 * Total Submissions: 375.1K
 * Testcase Example:  '[5,2,3,1]'
 *
 * 给你一个整数数组 nums，请你将该数组升序排列。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [5,2,3,1]
 * 输出：[1,2,3,5]
 *
 *
 * 示例 2：
 *
 * 输入：nums = [5,1,1,2,0,0]
 * 输出：[0,0,1,1,2,5]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 50000
 * -50000 <= nums[i] <= 50000
 *
 *
 */

// @lc code=start
func sortArray(nums []int) []int {
	merge := func(l, mid, r int) {
		num1 := append([]int{}, nums[l:mid+1]...)
		num2 := append([]int{}, nums[mid+1:r+1]...)
		num1 = append(num1, math.MaxInt32)
		num2 = append(num2, math.MaxInt32)
		l1, l2 := 0, 0
		for i := l; i <= r; i++ {
			if num1[l1] < num2[l2] {
				nums[i] = num1[l1]
				l1++
			} else {
				nums[i] = num2[l2]
				l2++
			}
		}
	}
	var mergeSort func(int, int)
	mergeSort = func(l, r int) {
		if l >= r {
			return
		}
		mid := (r-l)/2 + l
		mergeSort(l, mid)
		mergeSort(mid+1, r)
		merge(l, mid, r)
	}
	n := len(nums)
	mergeSort(0, n-1)
	return nums
}

// @lc code=end

