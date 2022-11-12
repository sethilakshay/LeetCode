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
        
        unordered_map<Node*, Node*> map;
        Node* temp = head;
        
        while(temp != NULL){
            map[temp] = new Node(temp->val);
            temp = temp->next;
        }
        
        temp = head;
        map[NULL] = NULL;
        
        Node* out = new Node(INT_MIN);
        Node* temp_out  = out;
        
        while(temp != NULL){
            //Setting up value
            temp_out->next = map[temp];
            
            //Setting pointers
            temp_out->next->next = map[temp->next];
            temp_out->next->random = map[temp->random];
            
            temp_out = temp_out->next;
            temp = temp->next;
        }
        return out->next;
    }
};