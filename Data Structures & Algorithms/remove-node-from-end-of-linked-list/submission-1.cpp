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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;

        int size = 0;

        while(curr!=NULL){
            curr = curr->next;
            size++;
        }

        size = size - n;

        int remove = 0;
        curr = head;
        ListNode* prev = NULL;

        while(remove!=size && curr!=NULL){
            prev = curr;
            curr = curr->next;
            remove++;
        }

        if(prev == NULL){
            return head->next;
        }

        prev ->next = curr->next;
        curr->next = NULL;
        delete curr;

        return head;

    }
};
