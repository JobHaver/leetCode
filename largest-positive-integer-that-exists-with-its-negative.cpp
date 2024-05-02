class Solution {
public:
    int findMaxK(vector<int>& nums) {
        bitset<2001> vals;
        int max = -1;

        for(int i : nums){
            vals[1001 + i] = true;
            if(vals[1001 + (i * -1)])
                max = std::max(max, abs(i));
        }

        return max;
    }
};