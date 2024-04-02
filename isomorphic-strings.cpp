class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mp, tmap;//can be ANY valid ascii char
        for(int i = 0; i < s.size(); i++){
            char &c = mp[s[i]];
            if(!c){
                char &temp = tmap[t[i]];
                if(temp)
                    return false;
                
                temp = s[i];
                c = t[i];
            }
            else if(c != t[i])
                return false;
        }

        return true;
    }
};