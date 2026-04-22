class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        
        for(string & s : queries){
            for(string & sd : dictionary){
                int strikes = 3;
                for(int i = 0 ; i < sd.size() && strikes; i++)
                    if(sd[i] != s[i])
                        strikes--;

                if(strikes){
                    ans.push_back(s);
                    break;
                }
            }
        }

        return ans;
    }
};