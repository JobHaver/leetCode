class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        #pragma unroll
        for(int frac = arr.size() / 4, i = 0, start; i < arr.size();){
            start = i;
            for(i + 1; i < arr.size() && arr[i] == arr[start]; i++);

            if(i - start > frac)
                return arr[i - 1];
        }

        return -1;
    }
};