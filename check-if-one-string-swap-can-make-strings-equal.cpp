class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int currLoc = -1;

        if(s1.size() != s2.size())
            return false;
        
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                if(currLoc < 0)
                    currLoc = i;
                else if(currLoc < s1.size() && s1[currLoc] == s2[i] && s2[currLoc] == s1[i])
                    currLoc = s1.size();
                else
                    return false;
            }
        }

        return currLoc == -1 || currLoc == s1.size();
    }
};