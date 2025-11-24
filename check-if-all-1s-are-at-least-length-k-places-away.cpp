class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int count = k;
        for(int i : nums){
            if(i){
                if(count < k)
                    return false;

                count = 0;
            }
            else
                count++;
        }

        return true;
    }
};