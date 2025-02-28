class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> set(arr.begin(), arr.end());

        int ans = 0;
        for(int i = 0; i < arr.size(); i++){
            for(int j = i+1; j < arr.size(); j++){
                int currCount = 0, fib1 = arr[i], fib2 = arr[j];
                for(; set.contains(fib1 + fib2); fib2 = fib1 + fib2, fib1 = fib2 - fib1)
                    currCount++;

                ans = max(ans, currCount);
            }
        }

        return ans ? ans + 2 : 0;
    }
};