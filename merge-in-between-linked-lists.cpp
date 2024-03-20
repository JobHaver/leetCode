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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *list2End, *curr = list1;
        for(list2End = list2; list2End->next; list2End = list2End->next);

        for(int i = 1; i < a; i++, curr = curr->next);
        ListNode *temp = curr;
        curr = curr->next;
        temp->next = list2;

        for(int i = a - 1; i < b; i++, curr = curr->next);
        list2End->next = curr;

        return list1;
    }
};