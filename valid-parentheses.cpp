class Solution {
public:
    bool isValid(string s) {
        stack<char> left_op;
        unordered_map<char, char> char_map = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        
        for(const char &c : s){
            if(c == '(' || c == '[' || c == '{')
                left_op.push(c);
            else{
                if(left_op.empty() || c != char_map[left_op.top()]) //case "]"
                    return false;
                left_op.pop();
            }
        }
        
        return left_op.empty(); //case "["
    }
};