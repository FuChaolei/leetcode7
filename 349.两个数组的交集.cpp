/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 *
 * https://leetcode.cn/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (74.27%)
 * Likes:    618
 * Dislikes: 0
 * Total Accepted:    346.9K
 * Total Submissions: 467.1K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[9,4]
 * 解释：[4,9] 也是可通过的
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> hs(1005, 0);
        for (int i = 0; i < nums1.size(); i++)
        {
            hs[nums1[i]] = 1;
        }
        unordered_set<int> st;
        for (auto i : nums2)
        {
            if (hs[i] != 0)
            {
                st.insert(i);
            }
        }
        return vector<int>(st.begin(), st.end());
        // unordered_set<int> st(nums1.begin(), nums1.end());
        // unordered_set<int> st2(nums2.begin(), nums2.end());
        // vector<int> res;
        // for (auto i : st)
        // {
        //     if (st2.find(i) != st2.end())
        //     {
        //         res.emplace_back(i);
        //     }
        // }
        // return res;
    }
};
// @lc code=end
