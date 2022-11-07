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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        ListNode* temp;
        
        for(int i=0; i<lists.size(); i++){
            temp = lists[i];
            
            while(temp != NULL){
                min_heap.push(temp->val);
                temp = temp->next;
            }
        }
    
        
        if(min_heap.size() == 0)
            return NULL;
        
        ListNode* sorted = new ListNode(min_heap.top());
        temp = sorted;
        min_heap.pop();
        
        while(!min_heap.empty()){
            temp->next = new ListNode(min_heap.top());
            temp = temp->next;
            min_heap.pop();
        }
        return sorted;
    }
};