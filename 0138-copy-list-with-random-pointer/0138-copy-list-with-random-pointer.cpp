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
        
        temp = head;
        
        hash_map[NULL] = NULL;
        
        Node* deep_copy = new Node (INT_MIN);
        Node* temp_copy = deep_copy;
        
        while(temp != NULL){
            
            temp_copy->next = hash_map[temp];
            temp_copy->next->next = hash_map[temp->next];
            temp_copy->next->random = hash_map[temp->random];
            
            temp = temp->next;
            temp_copy = temp_copy->next;
        }
        return deep_copy->next;
    }
};