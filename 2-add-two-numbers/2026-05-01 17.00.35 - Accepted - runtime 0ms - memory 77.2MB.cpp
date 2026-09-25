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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *ans = dummy;
        int carry = 0;
        while (l1 != NULL && l2 != NULL) {
            int sum = carry + l1->val + l2->val;
            int last = sum % 10;
            carry = sum / 10;
            ListNode *temp = new ListNode(last);
            dummy->next = temp;
            l1 = l1->next;
            l2 = l2->next;
            dummy = dummy->next;
        }
        while (l1 != NULL) {
            int sum = carry + l1->val;
            int last = sum % 10;
            carry = sum / 10;
            ListNode *temp = new ListNode(last); 
            dummy->next = temp;
            dummy = dummy->next;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            int sum = carry + l2->val;
            int last = sum % 10;
            carry = sum / 10;
            ListNode *temp = new ListNode(last); 
            dummy->next = temp;
            dummy = dummy->next;
            l2 = l2->next;
        }
        if (carry) {
            ListNode *temp = new ListNode(carry); 
            dummy->next = temp;
        }
        return ans->next;
    }
};