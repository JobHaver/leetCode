class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        //could use sort to solve this instantly but can get it down to n time
        int max1 = 0, max2 = 0, min1 = INT_MAX, min2 = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(max1 < nums[i]){
                max1 = nums[i];
                if(max1 > max2)
                    swap(max1, max2);
            }
            
            if(min1 > nums[i]){
                min1 = nums[i];
                if(min1 < min2)
                    swap(min1, min2);
            }
        }

        return (max1 * max2) - (min1 * min2);
    }
};