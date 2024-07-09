class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long wait = 0;
        int curr = 0;
        for(vector<int> &v : customers){
            curr = v[1] + max(curr, v[0]);
            wait += curr - v[0];
        }

        return double(wait) / customers.size();
    }
};