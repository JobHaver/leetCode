class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int curr = 0, last = 0, max = 0;

        for(int i : nums){
            if(i)
                curr++;
            else{
                max = std::max(max, curr + last);

                last = curr;
                curr = 0;
            }
        }

        max = std::max(max, curr + last);

        return max == nums.size() ? nums.size()-1 : max;
    }
};