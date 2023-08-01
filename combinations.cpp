class Solution {
private:
    vector<vector<int>> ans;
    vector<int> comb;
    int size;

    void helper(int k, int j){
        if(k == 0){
            ans.push_back(comb);
            return;
        }

        for(int i = j + 1, pos = comb.size() - k, next = k - 1; i < size; i++){
            comb[pos] = i;
            helper(next, i);
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        size = n + 1;
        comb.resize(k);
        helper(k, 0);

        return ans;
    }
};