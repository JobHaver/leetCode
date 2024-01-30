class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(string &s : tokens){
            if(s.size() == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '/' || s[0] == '*')){
                int r = nums.top();
                nums.pop();
                int l = nums.top();
                nums.pop();
                switch(s[0]){
                    case '+':
                        l += r;
                        break;
                    case '-':
                        l -= r;
                        break;
                    case '/':
                        l /= r;
                        break;
                    case '*':
                        l *= r;
                        break;
                }

                nums.push(l);
            }
            else
                nums.push(stoi(s));
        }

        return nums.top();
    }
};