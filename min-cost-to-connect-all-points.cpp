class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int size = points.size(), group = 1;
        vector<int> set(size);
        vector<pair<int, pair<int, int>>> distances;
        int ans = 0;

        for(int i = 0; i < size; i++){
            for(int j = i + 1; j < size; j++){
                distances.push_back({abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), {i, j}});
            }
        }

        sort(distances.begin(), distances.end());

        for(pair<int, pair<int, int>> &p : distances){
            int &s1 = set[p.second.first], &s2 = set[p.second.second];
            if(s1 && s1 == s2)
                continue;

            ans += p.first;
            if(!s1 && !s2){
                s1 = group++;
                s2 = s1;
            }
            else if(!s1)
                s1 = s2;
            else if(!s2)
                s2 = s1;
            else if(s1 != s2){
                int temp = s2;
                for(int &i : set){
                    if(i == temp)
                        i = s1;
                }
            }
        }

        return ans;
    }
};