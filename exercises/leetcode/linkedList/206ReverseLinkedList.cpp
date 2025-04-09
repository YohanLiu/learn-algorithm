/**
* @author yohan
* @Date 2025/04/08 
*/

#include <bits/stdc++.h>

using namespace std;

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
// 206反转链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }

        // 下个节点
        ListNode* pre = nullptr;

        // 当前节点
        ListNode* curr = head;
        while(curr) {
            // 找到下个节点临时记录
            ListNode* next = curr -> next;

            // 当前节点的下个就是pre节点
            curr -> next = pre;

            // pre节点更新
            pre = curr;

            // 链表往下继续扫描
            curr = next;
        }

        return pre;
    }
};

int main() {
    Solution solution;
    return 0;
}