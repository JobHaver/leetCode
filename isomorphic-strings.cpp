class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> smap(150), tmap(150);//can be ANY valid ascii char
        for(int i = 0; i < s.size(); i++){
            if(!smap[s[i]]){
                if(tmap[t[i]])
                    return false;
                
                tmap[t[i]] = s[i];
                smap[s[i]] = t[i];
            }
            else if(smap[s[i]] != t[i])
                return false;
        }

        return true;
    }
};