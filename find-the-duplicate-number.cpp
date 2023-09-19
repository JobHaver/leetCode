class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> numbers;
        for(int i : nums){
            if(numbers[i]++)
                return i;
        }

        return -1;
    }
};