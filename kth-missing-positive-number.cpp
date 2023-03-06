class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int expected = 1;

        for(int& i : arr){
            if(expected == i)
                expected++;
            else{
                int dif = i - expected;
                if(dif >= k)
                    return expected + k - 1;
                   
                k -= dif;
                expected = i + 1;
            }
        }

        return arr[arr.size()-1] + k;
    }
};