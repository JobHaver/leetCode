class Solution {
public:
    string reverseWords(string s) {
        string ans;
        stack<char> letters;

        for(char c : s){
            if(c == ' '){
                for(; !letters.empty(); letters.pop())
                    ans.push_back(letters.top());
                
                ans.push_back(' ');
            }   
            else
                letters.push(c);
        }

        for(; !letters.empty(); letters.pop())
            ans.push_back(letters.top());

        return ans;
    }
};