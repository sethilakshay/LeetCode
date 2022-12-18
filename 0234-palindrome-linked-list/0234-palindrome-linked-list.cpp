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
    bool isPalindrome(ListNode* head) {
        ListNode* walker = head;
        ListNode* runner = head;
        
        stack<int> pal_stk;
        
        while(runner != NULL && runner->next != NULL){
            
            pal_stk.push(walker->val);
            walker = walker->next;
            runner = runner->next->next;
        }
        
        // To check if there are even/ odd numbers of elements in linked list
        if(runner != NULL){
            walker = walker->next;
        }
        
        while(walker != NULL){
            
            if(walker->val != pal_stk.top()){
                return false;
            }
            
            walker = walker->next;
            pal_stk.pop();
        }
        return true;
    }
};