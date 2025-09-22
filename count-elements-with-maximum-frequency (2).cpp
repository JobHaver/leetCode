class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> frq(101);

        for(int i : nums)
            frq[i]++;

        int ans = 0;
        for(int i = 0, max = 0; i < frq.size(); i++){
            if(frq[i] > max)
                ans = max = frq[i];
            else if(frq[i] == max)
                ans += max;
        }

        return ans;
    }
};