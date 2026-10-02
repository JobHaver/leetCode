class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for(char c : s){
            if(c == '}' || c == ']' || c == ')'){
                if(brackets.size() == 0)
                    return false;

                char top = brackets.top();
                if(top == '{' && c != '}' ||
                   top == '[' && c != ']' ||
                   top == '(' && c != ')')
                   return false;

                brackets.pop();
            }
            else
                brackets.push(c);
        }

        return brackets.size() == 0;
    }
};