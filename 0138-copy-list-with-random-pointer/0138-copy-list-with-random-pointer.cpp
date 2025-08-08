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
        map<Node*, Node*> mp;
        map<Node*, Node*> mp_random;


        Node* ptr = head;
        if(ptr == nullptr){
            return nullptr;
        }

        Node* copy_head = new Node(head->val);
        Node* copy_ptr = copy_head;

        mp[head] = copy_head; 
        mp_random[ptr] = ptr->random;

        ptr = ptr->next;

        while(ptr){
            Node* copy_newNode = new Node(ptr->val);
            copy_ptr->next = copy_newNode;
            copy_ptr = copy_ptr->next;
            mp[ptr] = copy_newNode;
            ptr=ptr->next;
        }

        ptr = head;
        while(ptr){
            if(ptr->random){
                mp[ptr]->random = mp[ptr->random];
            }

            ptr = ptr->next;
        }

        return copy_head;
    }
};