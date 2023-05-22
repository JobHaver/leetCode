class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> numCount;
        vector<int> ans;
        int prev = INT_MAX;
        
        sort(nums.begin(), nums.end());

        for(int i : nums){
            if(i != prev){
                prev = i;
                numCount.push_back({0, i});
            }

            numCount.back().first++;
        }

        // for(auto i : numCount)
        //     cout << i.second << " " << i.first << endl;

        sort(numCount.begin(), numCount.end(), std::greater<>());

        for(int i = 0; i < k; i++)
            ans.push_back(numCount[i].second);

        return ans;
    }
};