class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i : nums)
            map[i]++;
        
        vector<int> ans;
        int n = nums.size() / 3;
        for(auto p : map){
            if(p.second > n)
                ans.push_back(p.first);
        }

        return ans;
    }
};