class Solution {
private:
    vector<string> ans;
    string d;
    vector<vector<char>> telephone = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'},
                                      {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
                                      {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
    void helper(string curr){
        if(curr.length() == d.length()){
            ans.push_back(curr);
            return;
        }
            
        vector<char> &v = telephone[d[curr.length()] - '2'];
        for(char c : v)
            helper(curr + c);
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return ans;
            
        d = digits;
        helper("");

        return ans;
    }
};