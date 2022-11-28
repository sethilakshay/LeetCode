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
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        
        ListNode* out = new ListNode(INT_MIN);
        ListNode* temp = out;
        
        while(temp1 != NULL && temp2 != NULL){
            
            if(temp1->val <= temp2->val){
                temp->next = new ListNode(temp1->val);
                temp = temp->next;
                temp1 = temp1->next;
            }
            else{
                temp->next = new ListNode(temp2->val);
                temp = temp->next;
                temp2 = temp2->next;
            }
        }
        
        if(temp1 != NULL){
            temp->next = temp1;
        }
        
        if(temp2 != NULL){
            temp->next = temp2;
        }
        
        return out->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size() == 0){
            return NULL;
        }
        
        while(lists.size() > 1){
            vector<ListNode*> temp;
            int i, n = lists.size();
            
            for(i=1; i<n; i+=2){
                temp.push_back(merge(lists[i], lists[i-1]));
            }
            
            if(i==n){
                temp.push_back(lists[n-1]);
            }
            
            lists = temp;
        }
        
        return lists[0];
        
    }
};