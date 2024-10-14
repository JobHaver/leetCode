class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());

        long long ans = 0;
        for(int i = 0; i < k; i++){
            ans += pq.top();
            pq.push(ceil(pq.top() / 3.0));
            pq.pop();
        }

        return ans;
    }
};