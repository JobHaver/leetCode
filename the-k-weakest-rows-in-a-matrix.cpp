#define pp pair<int, int>

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pp> weakest;
        for(int i = 0; i < mat.size(); i++){
            vector<int> &v = mat[i];
            int it = lower_bound(v.begin(), v.end(), 0, greater<int>()) - v.begin();
            if(weakest.size() < k)
                weakest.push({it, i});
            else if(weakest.top().first > it){
                weakest.pop();
                weakest.push({it, i});
            }
        }

        vector<int> ans(weakest.size());
        for(int i = weakest.size() - 1; !weakest.empty(); weakest.pop(), i--)
            ans[i] = weakest.top().second;
        
        return ans;

    }
};