class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> s;
        vector<int> ans(t.size());
        for(int i = 0; i < t.size(); i++){
            for(; !s.empty() && t[s.top()] < t[i]; s.pop())
                ans[s.top()] = i - s.top();
            s.push(i);
        }

        return ans;
    }
};