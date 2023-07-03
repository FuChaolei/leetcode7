/*
 * @lc app=leetcode.cn id=179 lang=cpp
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
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> st;
        for (auto i : nums)
        {
            st.emplace_back(to_string(i));
        }
        sort(st.begin(), st.end(), [](string a, string b)
             { return a + b > b + a; });
        string res = "";
        for (string s : st)
        {
            res += s;
        }
        if (res[0] == '0')
        {
            return "0";
        }
        return res;
    }
};
// @lc code=end
