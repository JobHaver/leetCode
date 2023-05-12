class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> ans(questions.size()+1);
        long long size = questions.size(), high = 0;

        for(int i = 0; i < questions.size(); i++){
            long long score = questions[i][0], cost = questions[i][1], &question = ans[min(i+cost+1, size)];
            high = max(ans[i], high);
            question = max(question, high + score);
        }

        return max(ans[questions.size()], ans[questions.size()-1]);
    }
};