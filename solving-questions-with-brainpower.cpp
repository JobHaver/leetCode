class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int size = questions.size();
        vector<long long> ans(size+1);
        long long high = 0;

        for(int i = 0; i < questions.size(); i++){
            long long &question = ans[min(i+questions[i][1]+1, size)];
            high = max(ans[i], high);
            question = max(question, high + questions[i][0]);
        }

        return ans[size];
    }
};