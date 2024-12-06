class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans = 0, sum = 0;
        sort(banned.begin(), banned.end());
        for(int i = 1, j = 0; i <= n && sum + i <= maxSum; i++){
            if(j < banned.size() && i == banned[j])
                for(int curr = banned[j]; j < banned.size() && banned[j] == curr; j++);
            else
                sum += i, ans++;
        }

        return ans; 
    }
};