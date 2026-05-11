class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int num : nums){
            int count = 0;
            for(; num; num /= 10, count++)
                ans.push_back(num % 10);

            for(int i = 1; i < count; i++, count--)
                swap(ans[ans.size()-i], ans[ans.size()-count]);
        }

        return ans;
    }
};