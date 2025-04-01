class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long ans = 0;

        vector<long long> previousPoints(questions.size());
        for(int i = questions.size()-1; i >= 0; i--){
            int nextQuestion = questions[i][1] + i + 1;
            long long currpoints = questions[i][0] + (nextQuestion < questions.size() ? previousPoints[nextQuestion] : 0);

            if(currpoints > ans)
                ans = currpoints;

            previousPoints[i] = ans;
        }

        return ans;
    }
};