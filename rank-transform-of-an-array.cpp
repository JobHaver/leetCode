class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> m;

        for(int n : arr)
            m[n];

        int i = 1;
        for(auto &p : m)
            p.second = i++;

        for(int &n : arr)
            n = m[n];

        return arr;
    }
};