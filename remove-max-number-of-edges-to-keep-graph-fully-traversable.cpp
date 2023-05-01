class Solution {
private:
    int ans = 0;

    void unionHelper(vector<vector<int>>& edges, vector<int>& both, vector<vector<int>>& groups, int& group, int key){
        for(vector<int>& v : edges){
            if(v[0] == key){
                int &n1 = both[v[1]], &n2 = both[v[2]];
                if(n1 && n2){
                    if(n1 == n2)
                        ans++;
                    else{
                        int temp = n2;
                        for(int i : groups[temp]){
                            groups[n1].push_back(i);
                            both[i] = n1;
                        }
                        groups[temp].clear();
                    }
                }
                else if(n1){
                    n2 = n1;
                    groups[n1].push_back(v[2]);
                }
                else if(n2){
                    n1 = n2;
                    groups[n2].push_back(v[1]);
                }
                else{
                    groups.push_back({v[1], v[2]});
                    n1 = group;
                    n2 = group++;
                }
            }
        }
    }
    
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> both(n+1);
        vector<vector<int>> groups;
        int group = 1;
        
        groups.push_back({});
        unionHelper(edges, both, groups, group, 3);

        vector<int> both2(both);
        vector<vector<int>> groups2(groups);

        unionHelper(edges, both2, groups2, group, 2);
        for(int i = 1; i < both2.size(); i++){
            if(!both2[i] || both2[1] != both2[i])
                return -1;
        }
        
        unionHelper(edges, both, groups, group, 1);
        for(int i = 1; i < both.size(); i++){
            if(!both[i] || both[1] != both[i])
                return -1;
        }
        
        return ans;
    }
};