class Solution {
    string *sp;

    bool helper(int i){
        if((*sp).size() % i != 0)
            return false;
        
        for(int j = i; j < (*sp).size(); ){
            for(int k = 0; k < i; k++, j++){
                if((*sp)[k] != (*sp)[j])
                    return false;
            }
        }

        return true;
    }

public:
    bool repeatedSubstringPattern(string &s) {
        sp = &s;
        for(int i = 1; i * 2 <= s.size(); i++){
            if(helper(i))
                return true;
        }

        return false;
    }
};