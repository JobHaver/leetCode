class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size() + 1;
        vector<bool> cnt(size);

        for(int i : nums)
            if(i > 0 && i < size)
                cnt[i] = true;

        for(int i = 1; i < size; i++)
            if(!cnt[i])
                return i;
            
        return size;
    }
};