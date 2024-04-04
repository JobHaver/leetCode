class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0, max = 0;

        for(char c : s){
            if(c == '(')
                max = std::max(max, ++cnt);
            else if(c == ')')
                cnt--;
        }

        return max;
    }
};