class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> dist;

        int i, curr;
        for(i = 1; i < heights.size() && ladders; i++)
            if((curr = heights[i] - heights[i - 1]) > 0)
                dist.push(curr), ladders--;

        for(; i < heights.size(); i++){
            if((curr = heights[i] - heights[i - 1]) <= 0)
                continue;

            dist.push(curr);
            if((bricks -= dist.top()) < 0)
                break;
            
            dist.pop();
        }

        return i - 1;
    }
};