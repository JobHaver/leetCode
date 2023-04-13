class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> ans;
        int i = 0;

        for(const int &p : pushed){
            if(p == popped[i]){
                while(++i < popped.size() && !ans.empty() && ans.top() == popped[i])
                    ans.pop();
            } 
            else
                ans.push(p);
        }

        return ans.empty();
    }
};