class Solution {
private:
    unordered_map<string, bool> realDic;
    vector<bool> visited;
    string word;
    int max = 0;

    bool helper(int i){
        if(visited[i])
            return false;
            
        visited[i] = true;
        string curr = "";

        for(; i < word.size() && curr.size() < max; i++){
            if(realDic[curr += word[i]] && helper(i+1))
                return true;
        }

        return curr.empty() ? true : false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string &s: wordDict){
            max = std::max(max, (int)s.size());
            realDic[s] = true;
        }
        
        word = s;
        visited.resize(s.size() + 1, false);
        return helper(0);
    }
};