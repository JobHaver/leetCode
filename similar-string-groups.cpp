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
        vector<vector<int>> groups;
        for(int i = 0; i < strs.size(); i++){
            string& s1 = strs[i];
            vector<int>* group = NULL;
            for(vector<int>& v : groups){
                for(int s2 : v){
                    if(compare(s1, strs[s2])){
                        if(group){
                            v.insert(v.end(), group->begin(), group->end());
                            group->clear();
                        }
                        else
                            v.push_back(i);
                            
                        group = &v;
                        break;
                    }
                }
            }
            
            if(!group)
                groups.push_back(vector<int>({i}));
        }

        int ans = 0;

        for(vector<int>& v : groups){
            if(!v.empty())
                ans++;
        }

        return ans;
    }
};