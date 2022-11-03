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
        //Initialzing a Minimum Heap and pushing elements into it
        priority_queue<int, vector<int>, greater<int>> min_heap;
        
        for(int i=0; i<lists.size(); i++){
            ListNode* temp = lists[i];
            
            while(temp != NULL){
                min_heap.push(temp->val);
                temp = temp->next;
            }
        }
        
        //Sanity Check for the base case
        if(min_heap.size() == 0)
            return NULL;
        
        //Unpacking the heap into a LinkedList
        ListNode* root = new ListNode(min_heap.top());
        ListNode* temp = root;
        min_heap.pop();
        
        while(!min_heap.empty()){
            temp->next = new ListNode(min_heap.top());
            temp = temp->next;
            min_heap.pop();
        }
        
        return root;
    }
};