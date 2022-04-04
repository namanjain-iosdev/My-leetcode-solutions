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
        ListNode* list1 = l1, *list2 = l2;
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        ListNode* res = new ListNode(-1);
        ListNode* dummy = res;
        int carry=0, sum = 0;
        while(l1 || l2 ){
            
            
            sum = ((l1)? l1->val: 0) + ((l2) ? l2->val: 0)+carry;
            carry = (sum)/10;
            // sum = sum%10;
            res->next = new ListNode(sum%10);
            res = res->next;
            l1 = (l1) ? l1->next : l1;
            l2 = (l2) ? l2->next : l2;
        }
        if(carry>0){
            res->next = new ListNode(carry);
            res = res->next;
        }
        return dummy->next;
    }
};