class Solution {
public:

    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry != 0) {

            int sum = carry;

            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            int val = sum % 10;
            carry = sum / 10;

            tail->next = new ListNode(val);
            tail = tail->next;
        }

        ListNode* ans = reverse(dummy->next);

        delete dummy;

        return ans;
    }
};