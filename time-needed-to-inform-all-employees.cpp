class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> costs(manager.size());
        stack<int> prev; 
        int minutes = 0;

        for(int i = 0; i < manager.size(); i++){
            int currMinutes = 0, curr = i;
            
            while(curr != headID && !costs[curr]){
                prev.push(curr);
                curr = manager[curr];
            }
            
            currMinutes += costs[curr];

            while(!prev.empty()){
                costs[curr] = currMinutes;
                currMinutes += informTime[curr];
                curr = prev.top();
                prev.pop();
            }

            minutes = max(currMinutes, minutes);
        }

        return minutes;
    }
};