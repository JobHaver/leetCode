struct node{
    node* next[26];
    bool endOfWord = false;
};

class Trie {
private:
    node *head;

public:
    Trie() {
        head = new node();
    }
    
    void insert(string word) {
        node *curr = head;
        for(char &c : word){
            node *&temp = curr->next[c-'a'];
            if(!temp)
                temp = new node();

            curr = temp;
        }

        curr->endOfWord = true;
    }
    
    bool search(string word) {
        node *curr = head;
        for(char &c : word){
            node *&temp = curr->next[c-'a'];
            if(!temp)
                return false;

            curr = temp;
        }

        return curr->endOfWord == true;
    }
    
    bool startsWith(string prefix) {
        node *curr = head;
        for(char &c : prefix){
            node *&temp = curr->next[c-'a'];
            if(!temp)
                return false;

            curr = temp;
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */