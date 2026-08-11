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
    ListNode* insertionSortList(ListNode* head) {
        for (ListNode* cur = head->next; cur; cur = cur->next) {
            for (ListNode* tmp = head; tmp != cur; tmp = tmp->next) {
                if (tmp->val > cur->val) {
                    swap(tmp->val, cur->val);
                }
            }
        }
        return head;
    }
};;