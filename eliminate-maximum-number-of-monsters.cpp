class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<float> turns(dist.size());

        #pragma unroll
        for(int i = 0; i < dist.size(); i++)
            turns[i] = (float)dist[i] / speed[i];
        
        sort(turns.begin(), turns.end());

        int i = 1;
        for(i = 1; i < turns.size() && i < turns[i]; i++){}

        return i;
    }
};