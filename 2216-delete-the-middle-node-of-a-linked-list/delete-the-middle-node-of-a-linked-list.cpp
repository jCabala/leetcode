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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ios::sync_with_stdio(0); cin.tie(0);

        int size = 0;
        ListNode* cur = head;
        while(cur != nullptr) {
            cur = cur->next;
            size++;
        };

        if(size == 1) return nullptr;
        int toRemove = size / 2;

        cur = head;
        for(int i = 1; i < toRemove; i++) cur = cur->next;

        cur->next = cur->next->next;
        return head;
    }
};