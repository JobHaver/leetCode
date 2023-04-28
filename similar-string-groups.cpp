class Solution {
private: 
    bool compare(string& s1, string& s2){
        int count = 0;
        for(int i = 0; i < s1.size(); i++){
            if (s1[i] != s2[i]) {
                if(++count > 2) 
                    return false;
            }
        }
        return true;
    }

public:
    int numSimilarGroups(vector<string>& strs) {
        vector<vector<string>> groups;
        for(string& s1 : strs){
            vector<string>* group = NULL;
            for(vector<string>& v : groups){
                for(string& s2 : v){
                    if(compare(s1, s2)){
                        if(group){
                            v.insert(v.end(), group->begin(), group->end());
                            group->clear();
                        }
                        else
                            v.push_back(s1);
                            
                        group = &v;
                        break;
                    }
                }
            }
            
            if(!group)
                groups.push_back(vector<string>({s1}));
        }

        int ans = 0;

        for(vector<string>& v : groups){
            if(!v.empty())
                ans++;
        }

        return ans;
    }
};