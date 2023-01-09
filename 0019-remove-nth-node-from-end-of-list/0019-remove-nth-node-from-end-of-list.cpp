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
        
        int list_size = 0;
        ListNode* temp = head;
        
        while(temp != NULL){
            temp = temp->next;
            list_size++;
        }
        
        n = list_size - n + 1;
        
        if(n == 1){
            return head->next;
        }
        
        int cnt = n-2;
        temp = head;
        
        while(temp != NULL && cnt > 0){
            temp = temp->next;
            cnt--;
        }
        
        temp->next = temp->next->next;
        return head;
    }
};