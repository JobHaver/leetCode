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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // ListNode *head = new ListNode(INT_MIN);
        // ListNode *curr, *currL;

        // for(ListNode *list : lists){
        //     currL = list, curr = head;
        //     while(curr->next && currL){
        //         if(curr->next->val > currL->val){
        //             curr->next = new ListNode(currL->val, curr->next);
        //             currL = currL->next;
        //         }

        //         curr = curr->next;
        //     }

        //     while(currL){
        //         curr->next = new ListNode(currL->val);
        //         curr = curr->next;
        //         currL = currL->next;
        //     }
        // }

        // return head->next;
        //-----------------------------------------------------------------------
        ListNode *head = new ListNode(INT_MIN);
        ListNode *curr = head, *currL;
        map<int, int> nums;

        for(ListNode *&list : lists){
            currL = list;
            while(currL){
                nums[currL->val]++;
                currL = currL->next;
            }
        }

        for(pair<const int, int> &i : nums){
            while(i.second--){
                curr->next = new ListNode(i.first);
                curr = curr->next;
            }
        }

        return head->next;
    }
};