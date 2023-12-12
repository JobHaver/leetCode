class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m1 = 0, m2 = 0;

        #pragma unroll
        for(int i : nums){
            if(i > m1){
                m1 = i;
                if(m1 > m2)
                    swap(m1, m2);
            }
        }

        return (m1-1) * (m2-1);
    }
};