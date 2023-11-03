class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;

        for(int i = 0, val = 0; i < target.size();){
            ans.push_back("Push");
            
            if(++val == target[i]) 
                i++; 
            else 
                ans.push_back("Pop");
        }

        return ans;
    }
};