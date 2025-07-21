class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        char curr = '$';
        int count = 0;

        for(char c : s){
            if(c == curr){
                if(count++ >= 2)
                    continue;
            }
            else{
                count = 1;
                curr = c;
            }

            ans.push_back(c);
        }

        return ans;
    }
};