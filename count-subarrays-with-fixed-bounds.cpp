class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int valid = -1, minI = -1, maxI = -1; //inline because I see this as initalizing an obj
        //int* begin = &nums[0];
        
        for(int& i : nums){ //faster than cmp nums[i] in a regular for loop
            if(i >= minK && i <= maxK){//instead of || so it can short circuit
                if(i == minK) minI = &i-&nums[0]; //idk man, leetcode seems to think this is fastest way, beats 99.58%
                if(i == maxK) maxI = &i-&nums[0];
                    
                if(min(minI, maxI) > -1)
                    ans += min(minI, maxI) - valid;
            }
            else
                valid = &i-&nums[0], minI = -1, maxI = -1; //inline because I see this as initalizing an obj
        }

        return ans;
    }
};