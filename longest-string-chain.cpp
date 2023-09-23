class Solution {
private:
    bool valid(string &s1, string &s2){
        int k = 0, b = 0;
        for(char c : s2){
            if(c == s1[k])
                k++;
            else if(b++)
                return false;
        }

        return true;
    }

public:
    int longestStrChain(vector<string>& words) {
        int chainLength[words.size()];
        string *pointers[words.size()];
        for(int i = 0; i < words.size(); i++)
            pointers[i] = &words[i];

        sort(pointers, pointers + words.size(), [](const string* lhs, const string* rhs){return lhs->size() > rhs->size();});

        for(int i = 0; i < words.size(); i++){
            int lenMax = 1;
            for(int j = i - 1; j >= 0 && pointers[j]->size() <= pointers[i]->size() + 1; j--){
                if(pointers[j]->size() == pointers[i]->size() || lenMax > chainLength[j])
                    continue;
                
                if(valid(*(pointers[i]), *(pointers[j])))
                    lenMax = chainLength[j] + 1;
            }

            chainLength[i] = lenMax;
        }

        return *max_element(chainLength, chainLength + words.size());
    }
};