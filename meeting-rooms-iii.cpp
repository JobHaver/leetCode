#define p pair<long, int>

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> rooms(n);
        priority_queue<int, vector<int>, greater<int>> open;
        priority_queue<p, vector<p>, greater<p>> used;

        sort(meetings.begin(), meetings.end());
        for(int i = 0; i < n; i++)
            open.push(i);

        for(int i = 0; i < meetings.size(); i++){
            for(; !used.empty() && meetings[i][0] >= used.top().first; used.pop())
                open.push(used.top().second);
            
            int room;
            long time;
            if(open.empty()){
                room = used.top().second;
                time = used.top().first + (meetings[i][1] - meetings[i][0]);
                used.pop();
            }
            else{
                room = open.top();
                time = meetings[i][1];
                open.pop();
            }

            used.push({time, room});
            rooms[room]++;
        }

        int ans = 0, max = 0;
        for(int i = 0; i < n; i++)
            if(rooms[i] > max)
                max = rooms[i], ans = i;

        return ans;
    }
};