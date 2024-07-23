class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int i : nums)
            mp[i]++;
        
        vector<pair<int, int>> freq;
        for(pair<const int, int> &p : mp)
            freq.push_back({p.second, p.first});
        
        sort(freq.begin(), freq.end(), [] (const pair<int, int> &p1, const pair<int, int> &p2) {return p1.first == p2.first ? p1.second > p2.second : p1.first < p2.first;});
        for(int j = 0, i = 0; j < freq.size(); j++)
            while(freq[j].first--)
                nums[i++] = freq[j].second;

        return nums;
    }
};