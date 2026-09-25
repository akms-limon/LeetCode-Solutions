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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode();
        ListNode *ans = dummy;
        int i = 1;
        while (i < left) {
            dummy->next = head;
            dummy = dummy->next;
            head = head->next;
            i++;
        }
        --i;
        //cout<<i<<" "<<head->val<<'\n';
        ListNode *start = head;
        ListNode *l = NULL, *r = head;
        while (i < right) {
            ListNode* temp = r->next;
            //cout<<r->val<<" ";
            r->next = l;
            l = r;
            r = temp;
            i++;
        }
        dummy->next = l;
        start->next = r;
        // while (head != NULL) {
        //     dummy->next = head;
        //     dummy = dummy->next;
        //     head = head->next;
        // }
        return ans->next;
    }
};