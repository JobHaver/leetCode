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
    vector<ListNode*> list; //bc linked list does not change after solution call this is valid

    Solution(ListNode* head) { //(O(n))
        list.clear();
        while(head){
            list.push_back(head);
            head = head->next;
        }
    }
    
    int getRandom() { //O(1)
        return list[rand() % list.size()]->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */