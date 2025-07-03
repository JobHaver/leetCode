class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;
        char prev = '$';

        for(char c : word){
            if(c == prev)
                ans++;
            else
                prev = c;
        }

        return ans;
    }
};