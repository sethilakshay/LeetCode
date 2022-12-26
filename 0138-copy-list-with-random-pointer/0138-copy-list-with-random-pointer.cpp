/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> list_map;
        Node* temp = head;
        
        while(temp != NULL){
            list_map[temp] = new Node(temp->val);
            temp = temp->next;
        }
        
        list_map[NULL] = NULL;
        
        temp = head;
        Node* res = new Node(INT_MIN);
        Node* temp1 = res;
        
        while(temp != NULL){
            
            temp1->next = list_map[temp];
            temp1->next->next = list_map[temp->next];
            temp1->next->random = list_map[temp->random];
            
            temp = temp->next;
            temp1 = temp1->next;
        }
        return res->next;
    }
};