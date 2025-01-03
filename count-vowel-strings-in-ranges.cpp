class Solution {
private:
    bool isVowel(char c){
        return (c == 'a' || c == 'e' ||c == 'i' ||c == 'o' ||c == 'u');
    }

public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> simplified(words.size() + 1);
        vector<int> ans(queries.size());

        int currCount = 0, i = 1;
        for(string &s : words){
            if(isVowel(s[0]) && isVowel(s[s.size()-1]))
                currCount++;
            
            simplified[i++] = currCount;
        }

        for(int i = 0; i < queries.size(); i++)
            ans[i] = simplified[queries[i][1] + 1] - simplified[queries[i][0]];

        return ans;
    }
};