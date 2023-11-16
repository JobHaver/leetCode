class Solution {
public:
    string findDifferentBinaryString(vector<string>& s) {
        vector<int> nums(s.size());
        
        for(int i = 0; i < s.size(); i++)
            nums[i] = std::stoi(s[i], nullptr, 2);
        
        sort(nums.begin(), nums.end());

        int i;
        for(i = 0; i < nums.size() && nums[i] == i; i++){}

        string ans = string(s[0].size(), '0');
        for(char &c : ans){
            if(i & 1)
                c = '1';
            i >>= 1;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};