class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int max = tickets[k], ans = 0;

        for(int i = 0; i < k; i++)
            ans += min(max, tickets[i]);

        max--;
        for(int i = k; i < tickets.size(); i++)
            ans += min(max, tickets[i]);

        return ans + 1;
    }
};