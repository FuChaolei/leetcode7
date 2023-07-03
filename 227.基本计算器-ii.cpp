/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 *
 * https://leetcode.cn/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (44.45%)
 * Likes:    689
 * Dislikes: 0
 * Total Accepted:    146.5K
 * Total Submissions: 329.7K
 * Testcase Example:  '"3+2*2"'
 *
 * 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
 *
 * 整数除法仅保留整数部分。
 *
 * 你可以假设给定的表达式总是有效的。所有中间结果将在 [-2^31, 2^31 - 1] 的范围内。
 *
 * 注意：不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "3+2*2"
 * 输出：7
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = " 3/2 "
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = " 3+5 / 2 "
 * 输出：5
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 3 * 10^5
 * s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开
 * s 表示一个 有效表达式
 * 表达式中的所有整数都是非负整数，且在范围 [0, 2^31 - 1] 内
 * 题目数据保证答案是一个 32-bit 整数
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int calculate(string s)
    {
        char pretype = '+';
        vector<int> st;
        int n = s.size();
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + (s[i] - '0');
            }
            if (((s[i] < '0' || s[i] > '9') && s[i] != ' ') || i == n - 1)
            {
                if (pretype == '/')
                {
                    st.back() /= num;
                }
                else if (pretype == '*')
                {
                    st.back() *= num;
                }
                else if (pretype == '-')
                {
                    st.emplace_back(-num);
                }
                else
                {
                    st.emplace_back(num);
                }
                num = 0;
                pretype = s[i];
            }
        }
        int res = 0;
        for (int i = 0; i < st.size(); i++)
        {
            res += st[i];
        }
        return res;
    }
};
// @lc code=end
