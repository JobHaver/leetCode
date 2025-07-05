class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = -1, i = 0, count = 0, curr = arr[0];

        while(i < arr.size()){
            while(i < arr.size() && arr[i++] == curr)
                count++;

            if(count == curr)
                ans = curr;

            curr = arr[i-1];
            count = 1;
        }

        return ans;
    }
};