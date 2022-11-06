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
    bool hasCycle(ListNode *head) {
        
        unordered_set<ListNode*> s_unique;
        ListNode* temp = head;
        
        while(temp != NULL){
            
            if(s_unique.find(temp) != s_unique.end())
                return true;
            else
                s_unique.insert(temp);
            
            temp = temp->next;
        }
        return false;
    }
};