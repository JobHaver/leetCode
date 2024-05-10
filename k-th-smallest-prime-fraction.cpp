class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        priority_queue<tuple<float, int, int>> pq;
        for(int i = 0; i < arr.size(); i++){
            for(int j = arr.size() - 1; i != j; j--){
                float curr = (float)arr[i] / arr[j];
                if(k-- > 0)
                    pq.push({curr, arr[i], arr[j]});
                else if(curr < get<0>(pq.top()))
                    pq.pop(), pq.push({curr, arr[i], arr[j]});
                else
                    break;
            }
        }

        return {get<1>(pq.top()), get<2>(pq.top())};
    }
};