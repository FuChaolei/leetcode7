/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode-cn.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (66.71%)
 * Likes:    1288
 * Dislikes: 0
 * Total Accepted:    207.4K
 * Total Submissions: 310.9K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
 *
 * 进阶：
 *
 *
 * 你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [4,2,1,3]
 * 输出：[1,2,3,4]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [-1,5,3,4,0]
 * 输出：[-1,0,3,4,5]
 *
 *
 * 示例 3：
 *
 *
 * 输入：head = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目在范围 [0, 5 * 10^4] 内
 * -10^5 
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *tmp = head;
        int l = 0;
        while (tmp != nullptr)
        {
            l++;
            tmp = tmp->next;
        }
        cout << l;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy;
        for (int i = 1; i < l; i <<= 1)
        {
            ListNode *tail = pre;
            ListNode *cur = pre->next;
            while (cur)
            {
                ListNode *l = cur;
                ListNode *r = m_split(cur, i);
                cur = m_split(r, i);
                auto tmp = merge(l, r);
                tail->next = tmp.first;
                tail = tmp.second;
            }
        }
        return dummy.next;
    }

private:
    ListNode *m_split(ListNode *l, int n)
    {
        ListNode *tmp = l;
        while (tmp && n > 1)
        {
            tmp = tmp->next;
            n--;
        }
        if (tmp)
        {
            ListNode *res = tmp->next;
            tmp->next = nullptr;
            return res;
        }
        return nullptr;
    }
    pair<ListNode *, ListNode *> merge(ListNode *l, ListNode *r)
    {
        ListNode dummy(0);
        ListNode *pre = &dummy;
        while (l && r)
        {
            if (l->val < r->val)
            {
                pre->next = l;
                l = l->next;
            }
            else
            {
                pre->next = r;
                r = r->next;
            }
            pre = pre->next;
        }
        if (l)
        {
            pre->next = l;
        }
        if (r)
        {
            pre->next = r;
        }
        while (pre->next)
        {
            pre = pre->next;
        }
        return {dummy.next, pre};
    }
};
// @lc code=end
