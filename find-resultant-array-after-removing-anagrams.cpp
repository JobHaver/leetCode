class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        string prev;
        for(string &s : words){
            string temp = s;
            sort(temp.begin(), temp.end());
            if(temp == prev)
                continue;
            
            ans.push_back(s);
            prev = temp;
        }

        return ans;
    }
};