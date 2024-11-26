class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> weaker(n);
        for(vector<int> &v : edges)
            weaker[v[1]] = true;
        
        int i = 0, ans = -1;
        for(; i < n; i++){
            if(!weaker[i]){
                ans = i++;
                break;
            }
        }

        for(; i < n; i++)
            if(!weaker[i])
                return -1;

        return ans;
    }
};