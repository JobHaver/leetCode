class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int cap = 1;
        sort(arr.begin(), arr.end());

        for(int i : arr){
            if(i >= cap)
                cap++;
        }

        return --cap;
    }
};