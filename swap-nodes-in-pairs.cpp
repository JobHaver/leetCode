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
    ListNode* swapPairs(ListNode* head) {
        ListNode *curr = head, *mid = head, *tail;
        int i = 1;

        if(!curr || !curr->next)
            return head;

        curr = curr->next;
        mid->next = curr->next;
        curr->next = mid;
        head = curr;
        swap(curr, mid);
        
        curr = curr->next;
        mid = mid->next;
        tail = head;

        while(curr){
            if(i++ % 2 == 0){
                // cout << tail->val << " " << mid->val << " " << curr->val << endl;
                tail->next = curr;
                mid->next = curr->next;
                curr->next = mid;
                swap(curr, mid);
            }

            curr = curr->next;
            mid = mid->next;
            tail = tail->next;
        }

        return head;
    }
};