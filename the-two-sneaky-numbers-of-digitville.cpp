class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        bool checked[nums.size()];
        
        memset(checked, 0, sizeof(checked));

        for(int i : nums){
            if(checked[i])
                ans.push_back(i);
            
            checked[i] = true;
        }

        return ans;
    }
};