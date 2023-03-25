class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> groups;
        vector<int> nodes(n);
        int group = 1;
        long long ans = 0;

        groups.push_back({}); //done so we can use group 1 desination

        for(const vector<int> &v : edges){
            int &n0 = nodes[v[0]];
            int &n1 = nodes[v[1]];

            if(n0 && n1){
                if(n0 != n1){
                    int temp = n1;
                    for(int &n : groups[temp]){ // overwrite group n1
                        nodes[n]= n0;
                        groups[n0].push_back(n);
                    }

                    groups[temp].clear();
                }
            }
            else if(n0){
                n1 = n0;
                groups[n1].push_back(v[1]);
            }
            else if(n1){
                n0 = n1;
                groups[n1].push_back(v[0]);
            }
            else{
                n0 = group++;
                n1 = n0;
                groups.push_back({v[1], v[0]});
            }
        }

        for(const vector<int> &v : groups){
            n -= v.size();
            ans += v.size() * n;
        }

        while(n-- > 1)
            ans += n;

        return ans;
    }
};