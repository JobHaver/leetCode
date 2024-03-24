class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        bitset<100001> numbers;
        for(int i : nums){
            if(numbers[i])
                return i;
            
            numbers.set(i);
        }

        return -1;
    }
};