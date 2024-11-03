class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())
            return false;

        for(int i = 0; i < s.size(); i++){
            if(goal[0] == s[i]){
                int s1 = i, s2 = 0;
                for(; s2 < goal.size() && s[s1] == goal[s2]; s2++)
                    if(++s1 >= s.size())
                        s1 = 0;

                if(s2 == goal.size())
                    return true;
            }
        }

        return false;
    }
};