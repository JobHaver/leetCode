class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            int sumOfDigits = sumOfDigitsHelper(nums[i]);
            if(i == sumOfDigits)
                ans = min(ans, sumOfDigits);
        }

        return ans == INT_MAX ? -1 : ans;
    }

    int sumOfDigitsHelper(int i){
        int sum = 0;

        for(; i; i /= 10)
            sum += i % 10;

        return sum;
    }
};