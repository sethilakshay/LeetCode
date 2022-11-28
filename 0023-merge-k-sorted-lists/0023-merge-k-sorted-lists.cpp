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
        ListNode* out = new ListNode(INT_MIN);
        ListNode* temp = out;
        
        while(list1 != NULL && list2 != NULL){
    
            if(list1->val < list2->val){
                temp->next = new ListNode(list1->val);
                temp = temp->next;
                list1 = list1->next;
            }
            else{
                temp->next = new ListNode(list2->val);
                temp = temp->next;
                list2 = list2->next;
            }
        }
        
        if(list1 != NULL){
            temp->next = list1;
        }
        
        if(list2 != NULL){
            temp->next = list2;
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
                
                temp.push_back(merge(lists[i-1], lists[i]));
            }
            
            if(i == n){
                temp.push_back(lists[n-1]);
            }
            lists = temp;
        }
        
        return lists[0];
    }
};