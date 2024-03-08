class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxSize = 101;
        vector<int> numCount(maxSize);
        
        for(int i : nums)
            numCount[i]++;

        int max = INT_MIN, count = 0;
        for(int c : numCount){
            if(c > max)
                max = c, count = 1;
            else if(c == max)
                count++;
        }

        return count * max;
    }
};