class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> previous; 
        int ans = 1;

        for(int i : arr)
            ans = max(ans, previous[i] = 1 + previous[i - difference]);

        return ans;
    }
};