class WordDictionary {
private:
    unordered_map<string, int> dic;
    vector<string> dotsDic;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        dic[word]++;
        dotsDic.push_back(word);
    }
    
    bool search(string word) {
        if(word.find('.') == string::npos)
            return dic[word] > 0;
        
        for(const string &s : dotsDic){
            if(s.size() == word.size()){
                int i;
                for(i = 0; i < word.size(); i++){
                    if(word[i] != '.' && word[i] != s[i])
                        break;
                }

                if(i == word.size())
                    return true;
            }
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */