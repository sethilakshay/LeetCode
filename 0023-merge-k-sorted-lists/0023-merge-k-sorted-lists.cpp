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
    ListNode* merge2Lists(ListNode* list1, ListNode* list2){
        
        ListNode* res = new ListNode(INT_MIN);
        ListNode* temp = res;
        
        while(list1 != NULL && list2 != NULL){
            
            if(list1->val < list2->val){
                temp->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else{
                temp->next = new ListNode (list2->val);
                list2 = list2->next;
            }
            temp = temp->next;
        }
        
        if(list1 != NULL){
            temp->next = list1;
        }
        
        if(list2 != NULL){
            temp->next = list2;
        }
        
        return res->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }

        while(lists.size() > 1){
            vector<ListNode*> res;
            int i, n = lists.size();
            
            for(i=1; i<n; i+= 2){
                res.push_back(merge2Lists(lists[i-1], lists[i]));
            }
            
            if(i == n){
                res.push_back(lists[n-1]);
            }
            lists = res;
        }
        return lists[0];
    }
};