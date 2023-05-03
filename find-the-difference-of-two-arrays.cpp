class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        vector<int> n1(2001);
        vector<int> n2(2001);

        for(int& i : nums1)
            n1[i+1000]++;
        
        for(int& i : nums2)
            n2[i+1000]++;

        for(int i = 0; i < 2001; i++){
            if(n1[i] && !n2[i])
                ans[0].push_back(i-1000);
            else if(!n1[i] && n2[i])
                ans[1].push_back(i-1000);
        }

        return ans;
    }
};