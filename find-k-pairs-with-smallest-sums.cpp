class Solution {
private:
    typedef pair<int, pair<int, int>> p;
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        //used vector originally, bad performance, tried int[3] and push kinda died
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<vector<int>> ans(k);
        int i;

        for(i = 0; i < nums1.size(); i++)
            pq.push({nums1[i] + nums2[0], {i, 0}});

        for(i = 0; i < k && !pq.empty(); i++){
            pair<int,int> ref = pq.top().second;
            pq.pop();
            ans[i] = {nums1[ref.first], nums2[ref.second]};
            if(++ref.second < nums2.size())
                pq.push({nums1[ref.first] + nums2[ref.second], {ref.first, ref.second}});
        }

        if(i < k)
            ans.resize(i);

        return ans;
    }
};