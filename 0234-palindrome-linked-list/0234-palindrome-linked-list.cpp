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
        stack<int> stk;
        
        while(runner != NULL && runner->next != NULL){
            stk.push(walker->val);
            walker = walker->next;
            runner = runner->next->next;
        }
        
        if(runner != NULL){
            walker = walker->next;
        }
        
        while(walker != NULL){
            
            if(stk.empty() || stk.top() != walker->val){
                return false;
            }
            walker = walker->next;
            stk.pop();
        }
        return true;
    }
};