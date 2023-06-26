class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;

        if(candidates * 2 < costs.size()){
            int l = candidates, r = costs.size()-candidates;
            //have to r-- here because of how ranges work in the constructor
            priority_queue<int, vector<int>, greater<int>> ql(costs.begin(), costs.begin()+l), qr(costs.begin()+r--, costs.end());

            for(int i = 0; i < k; i++){
                if((ql.empty() ? INT_MAX : ql.top()) <= (qr.empty() ? INT_MAX : qr.top())){
                    ans += ql.top();
                    ql.pop();
                    if(l <= r)
                        ql.push(costs[l++]);
                }
                else{
                    ans += qr.top();
                    qr.pop();
                    if(r >= l)
                        qr.push(costs[r--]);
                }
            }
        }
        else{
            sort(costs.begin(), costs.end());

            for(int i = 0; i < k; i++)
                ans += costs[i];
        }

        return ans;
    }
};