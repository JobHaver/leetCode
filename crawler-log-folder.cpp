class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;

        for(string &s : logs){
            if(s[0] != '.')
                depth++;
            else if(depth && s[1] == '.')
                depth--;
        }

        return depth;
    }
};