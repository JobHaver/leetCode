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
private:
    int gcd(int a, int b) {
        int result = min(a, b); 
        while (result > 0 && (a % result != 0 || b % result != 0))
            result--;

        return result; 
    } 

public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        for(ListNode *front = head, *back = head ? head->next : NULL;
            back;
            front = back, back = back->next)
                front->next = new ListNode(gcd(front->val, back->val), back);

        return head;
    }
};