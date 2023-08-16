class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> max;
        priority_queue<int> removed;
        vector<int> ans((nums.size() + 1) - k);

        for(int i = 0, size = k - 1; i < size; i++)// 1 less than k so don't add second time
            max.push(nums[i]);

        for(int i = k - 1, j = 0; i < nums.size(); i++, j++){
            max.push(nums[i]);
            ans[j] = max.top();
            removed.push(nums[j]);
            while(!removed.empty() && removed.top() == max.top())
                removed.pop(), max.pop();
        }

        return ans;
    }
};