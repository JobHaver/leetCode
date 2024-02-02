class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string nums = "123456789";
        vector<int> ans;

        for(int i = 1; i < 10; i++){
            for(int j = 0; j + i < 10; j++){
                int num = stoi(nums.substr(j, i));
                if(num > high)
                    return ans;
                if(num < low)
                    continue;
                ans.push_back(num);
            }
        }

        return ans;
    }
};