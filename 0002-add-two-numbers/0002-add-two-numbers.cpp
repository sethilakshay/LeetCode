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
        
        ListNode* newList = new ListNode(INT_MIN);
        ListNode* ptr = newList;
        
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        
        int carry = 0, curSum = 0;
        
        while(temp1 != NULL && temp2 != NULL){
            curSum = temp1->val + temp2->val + carry;
            ptr->next = new ListNode(curSum%10);
            
            temp1 = temp1->next;
            temp2 = temp2->next;
            ptr = ptr->next;
            
            carry = curSum/10;
        }
        
        while(temp1 != NULL){
            curSum = temp1->val + carry;
            ptr->next = new ListNode(curSum%10);
            
            temp1 = temp1->next;
            ptr = ptr->next;
            
            carry = curSum/10;
        }
        
        while(temp2 != NULL){
            curSum = temp2->val + carry;
            ptr->next = new ListNode(curSum%10);
            
            temp2 = temp2->next;
            ptr = ptr->next;
            
            carry = curSum/10;
        }
        
        while(carry != 0){
            ptr->next = new ListNode(carry%10);
            carry /= 10;
        }
        
        return newList->next;
    }
};