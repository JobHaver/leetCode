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
        unordered_map<Node*, Node*> m;

        for(Node* temp = head; temp; temp = temp->next)
            m[temp] = new Node(temp->val);

        for(Node* temp = head; temp; temp = temp->next){
            Node* &curr = m[temp];
            curr->next = m[temp->next];
            curr->random = m[temp->random];
        }  

        return m[head];
    }
};