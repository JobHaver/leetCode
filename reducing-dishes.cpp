class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int sum = 0;
        int ans = 0;

        sort(satisfaction.begin(), satisfaction.end());
        //prev had custom sort function so I didn't have to go in reverse, but this is faster
        for(int i = satisfaction.size(); --i > -1 && sum + satisfaction[i] > 0;){
            ans += sum + satisfaction[i];
            sum += satisfaction[i];
        }

        return ans;
    }
};