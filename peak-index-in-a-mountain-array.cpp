class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1, m;

        while(l < r){
            if(arr[m = l + r + 1  / 2] > arr[m-1])//huh there are no edge cases at 0 or arr.size()-1
                l = m + 1;
            else
                r = m - 1;
        }

        return r;
    }
};