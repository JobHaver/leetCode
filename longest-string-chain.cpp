class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int chainLength[words.size()];
        sort(words.begin(), words.end(), [](const string& lhs, const string& rhs){return lhs.size() > rhs.size();});

        for(int i = 0; i < words.size(); i++){
            int lenMax = 1;
            for(int j = i - 1; j >= 0 && words[j].size() <= words[i].size() + 1; j--){
                if(words[j].size() == words[i].size() || lenMax > chainLength[j])
                    continue;
                
                int k = 0, b = 0;
                for(char c : words[j]){
                    if(c == words[i][k])
                        k++;
                    else if(b++)
                        break;
                }

                if(b == 1)
                    lenMax = chainLength[j] + 1;
            }

            chainLength[i] = lenMax;
        }

        return *max_element(chainLength, chainLength + words.size());
    }
};