class Solution {
public:
    string largestGoodInteger(string num) {
        char ans = '$', f, s, t;
        int i = 2;

        do{
            f = num[i - 2], s = num[i - 1], t = num[i];
            if(f == s && s == t && (ans == '$' || ans - '0' < f - '0'))
                ans = f;
        }
        while(++i < num.size());

        return ans == '$' ? "" : string(3, ans);
    }
};