struct node{
    int val;
    node* next;
    node* prev;

    node() : next{NULL}, prev{NULL} {}
};

class LRUCache {
private:
    unordered_map<int, node*> m;
    int n;
    node *head, *tail;

    void moveNode(node* curr){
        if(curr != tail){ //if already tail don't have to move
            if(curr == head)
                head = curr->next;
            else{
                curr->next->prev = curr->prev;
                curr->prev->next = curr->next;
            }

            tail->next = curr;
            curr->prev = tail;
            tail = curr;
        }
    }

public:
    LRUCache(int capacity) : n{capacity}{
        head = NULL;
        tail = NULL;
    }
    
    int get(int key) {
        node *&curr = m[key];
        if(!curr || curr->val < 0)
            return -1;

        moveNode(curr);

        return curr->val;
    }
    
    void put(int key, int value) {
        node *&curr = m[key];
        if(!curr || curr->val < 0){
            if(!curr)
                curr = new node();

            if(--n < 0){
                head->val = -1;
                head = head->next;
            }
                
            if(!head)
                head = curr;
            else{
                tail->next = curr;
                curr->prev = tail;
            }

            tail = curr;
        }
        else
            moveNode(curr);

        curr->val = value;
    }
};