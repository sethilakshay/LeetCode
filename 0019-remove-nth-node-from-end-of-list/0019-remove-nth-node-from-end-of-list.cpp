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
        int len = 0;
        ListNode* temp = head;
        
        while(temp != NULL){
            temp = temp->next;
            len++;
        }
        
        if(len==n)
            return head->next;
        
        int stop = len-n;
        temp = head;
        
        while(stop > 1){
            temp = temp->next;
            stop--;
        }
        
        temp->next = temp->next->next;
        return head;
        
    }
};