class Solution {
public:
    int getLastMoment(int n, vector<int>& l, vector<int>& r) {
        return max(l.empty() ? 0 : *max_element(l.begin(), l.end()) , r.empty() ? 0 : n - *min_element(r.begin(), r.end()));
    }
};