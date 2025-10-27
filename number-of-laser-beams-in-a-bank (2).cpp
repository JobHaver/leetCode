class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prev = 0, curr = 0;

        for(string &s : bank){
            for(char c : s)
                if(c == '1')
                    curr++;
                    
            if(curr){
                ans += curr * prev;
                prev = curr;
                curr = 0;
            }
        }

        return ans;
    }
};