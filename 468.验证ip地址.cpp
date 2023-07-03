/*
 * @lc app=leetcode.cn id=468 lang=cpp
 *
 * [468] 验证IP地址
 *
 * https://leetcode.cn/problems/validate-ip-address/description/
 *
 * algorithms
 * Medium (28.15%)
 * Likes:    232
 * Dislikes: 0
 * Total Accepted:    62.2K
 * Total Submissions: 220.7K
 * Testcase Example:  '"172.16.254.1"'
 *
 * 给定一个字符串 queryIP。如果是有效的 IPv4 地址，返回 "IPv4" ；如果是有效的 IPv6 地址，返回 "IPv6"
 * ；如果不是上述类型的 IP 地址，返回 "Neither" 。
 *
 * 有效的IPv4地址 是 “x1.x2.x3.x4” 形式的IP地址。 其中 0 <= xi <= 255 且 xi 不能包含 前导零。例如:
 * “192.168.1.1” 、 “192.168.1.0” 为有效IPv4地址， “192.168.01.1” 为无效IPv4地址;
 * “192.168.1.00” 、 “192.168@1.1” 为无效IPv4地址。
 *
 * 一个有效的IPv6地址 是一个格式为“x1:x2:x3:x4:x5:x6:x7:x8” 的IP地址，其中:
 *
 *
 * 1 <= xi.length <= 4
 * xi 是一个 十六进制字符串 ，可以包含数字、小写英文字母( 'a' 到 'f' )和大写英文字母( 'A' 到 'F' )。
 * 在 xi 中允许前导零。
 *
 *
 * 例如 "2001:0db8:85a3:0000:0000:8a2e:0370:7334" 和
 * "2001:db8:85a3:0:0:8A2E:0370:7334" 是有效的 IPv6 地址，而
 * "2001:0db8:85a3::8A2E:037j:7334" 和
 * "02001:0db8:85a3:0000:0000:8a2e:0370:7334" 是无效的 IPv6 地址。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：queryIP = "172.16.254.1"
 * 输出："IPv4"
 * 解释：有效的 IPv4 地址，返回 "IPv4"
 *
 *
 * 示例 2：
 *
 *
 * 输入：queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
 * 输出："IPv6"
 * 解释：有效的 IPv6 地址，返回 "IPv6"
 *
 *
 * 示例 3：
 *
 *
 * 输入：queryIP = "256.256.256.256"
 * 输出："Neither"
 * 解释：既不是 IPv4 地址，又不是 IPv6 地址
 *
 *
 *
 *
 * 提示：
 *
 *
 * queryIP 仅由英文字母，数字，字符 '.' 和 ':' 组成。
 *
 *
 */

// @lc code=start
class Solution
{
public:
    string validIPAddress(string ip)
    {
        int n = ip.size();
        string res1 = "IPv4", res2 = "IPv6", res3 = "Neither";
        int flag = 0;
        if (ip.find('.') != -1)
        {
            flag = 1;
        }
        else if (ip.find(':') != -1)
        {
            flag = 2;
        }
        else
        {
            return res3;
        }
        if (flag == 1)
        {
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                string s = "";
                while (i < n && isnum(ip[i]))
                {
                    s += ip[i];
                    i++;
                }
                int t = s.size();
                if (t == 0)
                {
                    return res3;
                }
                if (t > 3 || cal(s) > 255)
                {
                    return res3;
                }
                if (t > 1 && s[0] == '0')
                {
                    return res3;
                }
                if (i < n && ip[i] != '.')
                {
                    return res3;
                }
                if (ip[i] == '.')
                {
                    cnt++;
                }
            }
            if (cnt != 3)
            {
                return res3;
            }
            if (ip[n - 1] == '.')
            {
                return res3;
            }
        }
        else
        {
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                string s = "";
                while (i < n && isalnum(ip[i]))
                {
                    s += ip[i];
                    i++;
                }
                int t = s.size();
                if (t == 0)
                {
                    return res3;
                }
                if (t > 4)
                {
                    return res3;
                }
                if (i < n && ip[i] != ':')
                {
                    return res3;
                }
                if (ip[i] == ':')
                {
                    cnt++;
                }
            }
            if (cnt != 7)
            {
                return res3;
            }
            if (ip[n - 1] == ':')
            {
                return res3;
            }
        }
        if (flag == 1)
        {
            return res1;
        }
        else
        {
            return res2;
        }
        return res3;
    }

private:
    int cal(string s)
    {
        int num = 0;
        for (int i = 0; i < s.size(); i++)
        {
            num = num * 10 + (s[i] - '0');
        }
        return num;
    }
    bool isnum(char a)
    {
        if (a >= '0' && a <= '9')
        {
            return true;
        }
        return false;
    }
    bool isalnum(char a)
    {
        if ((a >= '0' && a <= '9') || (a >= 'a' && a <= 'f') || (a >= 'A' && a <= 'F'))
        {
            return true;
        }
        return false;
    }
};
// @lc code=end
