/*
 * @lc app=leetcode.cn id=912 lang=cpp
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
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        merge_l(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void merge_l(vector<int> &nums, int l, int r)
    {
        if (l >= r)
        {
            return;
        }
        int mid = (r - l) / 2 + l;
        merge_l(nums, l, mid);
        merge_l(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }
    void merge(vector<int> &nums, int l, int mid, int r)
    {
        vector<int> nums_l(nums.begin() + l, nums.begin() + mid + 1);
        vector<int> nums_r(nums.begin() + mid + 1, nums.begin() + r + 1);
        int k = 0, t = 0;
        nums_l.emplace_back(INT_MAX);
        nums_r.emplace_back(INT_MAX);
        for (int i = l; i <= r; i++)
        {
            if (nums_l[k] < nums_r[t])
            {
                nums[i] = nums_l[k];
                k++;
            }
            else
            {
                nums[i] = nums_r[t];
                t++;
            }
        }
    }
};
// @lc code=end
