class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        bitset<100001> dup;
        vector<int> ans;
        for(int i : nums){
            if(dup[i])
                ans.push_back(i);
            else
                dup.set(i);
        }

        return ans;
    }
};