/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode.cn/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (49.26%)
 * Likes:    1280
 * Dislikes: 0
 * Total Accepted:    332.4K
 * Total Submissions: 674.6K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1
 * -100
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int l = 0, t = 0, b = matrix.size() - 1, r = matrix[0].size() - 1;
        vector<int> res;
        while (true)
        {
            for (int i = l; i <= r; i++)
            {
                res.emplace_back(matrix[t][i]);
            }
            t += 1;
            if (t > b)
            {
                break;
            }
            for (int i = t; i <= b; i++)
            {
                res.emplace_back(matrix[i][r]);
            }
            r -= 1;
            if (r < l)
            {
                break;
            }
            for (int i = r; i >= l; i--)
            {
                res.emplace_back(matrix[b][i]);
            }
            b -= 1;
            if (t > b)
            {
                break;
            }
            for (int i = b; i >= t; i--)
            {
                res.emplace_back(matrix[i][l]);
            }
            l += 1;
            if (l > r)
            {
                break;
            }
        }
        return res;
    }
};
// @lc code=end
