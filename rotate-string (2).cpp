class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())
            return false;

        for(int currLetter = 0; currLetter < s.size(); currLetter++){
            int j, i = currLetter;
            for(j = 0; j < goal.size(); j++, i = ++i < s.size() ? i : 0)
                if(goal[j] != s[i])
                    break;
                    
            if(j == goal.size())
                return true;
        }

        return false;
    }
};