class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> pos; //only need to keep track of positive asteroids cause they are going right;
        vector<int> ans;

        for(int i : asteroids){
            if(i > 0)
                pos.push(i);
            else{
                int result = -1;
                while(!pos.empty() && (result = pos.top() + i) < 0)
                    pos.pop();

                if(result == 0)
                    pos.pop();
                else if(pos.empty())
                    ans.push_back(i);
            }
        }

        int size = ans.size() + pos.size();
        ans.resize(size);
        for(size--; !pos.empty(); pos.pop(), size--)
            ans[size] = pos.top();

        return ans;
    }
};