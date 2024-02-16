class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> nums;
        for(int i : arr)
            nums[i]++;

        vector<int> freq;
        for(auto &p : nums)
            freq.push_back(p.second);

        sort(freq.begin(), freq.end());

        int i;
        for(i = 0; i < freq.size(); i++)
            if((k -= freq[i]) < 0)
                break;

        return freq.size() - i;
    }
};