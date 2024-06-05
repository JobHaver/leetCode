class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int size = 26;
        vector<int> ans(size, INT_MAX), curr(size);

        for(string &s : words){
            for(char c : s)
                curr[c - 'a']++;
            
            for(int i = 0; i < size; curr[i++] = 0)
                ans[i] = min(ans[i], curr[i]);
        }

        vector<string> output;
        for(int i = 0; i < size; i++)
            while(ans[i]--)
                output.push_back(string(1, char('a' + i)));

        return output;
    }
};