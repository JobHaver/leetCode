class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++)
            for(int j = i + 1; j < nums.size(); j++)
                mp[nums[i] * nums[j]]++;

        for(auto &p : mp)
            if(p.second > 1)
                ans += ((p.second-1) * (p.second)) / 2;
        
        return ans * 8;
    }
};