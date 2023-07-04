class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> count;

        for(int i : nums)
            count[i]++;

        for(auto &i : count){
            if(i.second < 3)
                return i.first;
        }

        return -1;
    }
};