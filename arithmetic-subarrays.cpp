class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size());

        for(int i = 0; i < l.size(); i++){
            vector<int> sub(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(sub.begin(), sub.end());
            int dif = sub[1] - sub[0];
            
            int j;
            for(j = 2; j < sub.size() && sub[j] - sub[j-1] == dif; j++){}

            ans[i] = j == sub.size();
        }

        return ans;
    }
};