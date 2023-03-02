class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // problem asked for O(nlog(n)), std::sort on a vector is merge sort and O(nlog(n)) time
        return nums;
    }
};