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
    bool isEmpty(ListNode* l){
        return (l == NULL);
    }
    
    int countDigits(ListNode* l){
        int ans = 0;
        while(!isEmpty(l)){
            ans++;
            l = l->next;
        }
        return ans;
    }
    
    int carryOf(ListNode* l){
        if(isEmpty(l)){
           return 0; 
        }
        
        l->val += carryOf(l->next);
        if(l->val >= 10){
            l->val %= 10;
            return 1;
        } else {
            return 0;
        }
    }
    
    ListNode* offsetFromNode(ListNode* l, int i){
        ListNode* ans = l;
        while(i--) ans = ans->next;
        return ans;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1Digits = countDigits(l1);
        int l2Digits = countDigits(l2);
        ListNode* ans;
        if(l2Digits > l1Digits){
            ans = l1;
            l1 = l2;
            l2 = ans;
            int tmp = l1Digits;
            l1Digits = l2Digits;
            l2Digits = tmp;
        }
        
        ans = new ListNode(0);
        ans->next = l1;
        
        ListNode* last = offsetFromNode(ans, l1Digits-l2Digits);
        
        for(int i = 0; i < l2Digits; i++){
            last->next->val += l2->val;
            l2 = l2->next;
            last = last->next;
        }
        if(carryOf(ans->next)) ans->val++;
        
        return (ans->val==0)?(ans->next):ans;
    }
};