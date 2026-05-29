class Solution {
public:
    int minElement(vector<int>& nums) {
        int min = INT_MAX;
        for(int i : nums){
            int currNum = 0;
            for(; i; i /= 10)
                currNum += i % 10;

            min = std::min(currNum, min);
        }

        return min;
    }
};