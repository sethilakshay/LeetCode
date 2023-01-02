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
        
        unordered_map<Node*, Node*> hash_map;
        Node* temp = head;
        
        while(temp != NULL){
            
            hash_map[temp] = new Node(temp->val);
            temp = temp->next;
        }
        
        hash_map[NULL] = NULL;
        
        Node* res = new Node(INT_MIN);
        Node* temp1 = res;
        
        temp = head;
        
        while(temp != NULL){
            
            temp1->next = hash_map[temp];
            temp1->next->next = hash_map[temp->next];
            temp1->next->random = hash_map[temp->random];
            
            temp1 = temp1->next;
            temp = temp->next;
        }
        
        return res->next;
    }
};