/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* cur = ans;
        ListNode* last;
        while (l1 != NULL || l2 != NULL){
            if (l1 != NULL){
                cur->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL){
                cur->val += l2->val;
                l2 = l2->next;
            }
            
            cur->next = new ListNode((cur->val)>=10?1:0);
            cur->val %= 10;
            last = cur;
            cur = cur->next;
        }
        if (cur->val == 0) last->next = NULL;
        return ans;
    }
};