class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> l, r;

        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == '(')
                l.push(i);
            else if(s[i] == ')'){
                if(l.size())
                    l.pop();
                else
                    r.push(i);
            }
        }

        string ans(s.size() - l.size() - r.size(),' ');
        for(int i = s.size() - 1, j = ans.size() - 1; j >= 0; i--){
            if(l.size() && l.top() == i)
                l.pop();
            else if(r.size() && r.top() == i)
                r.pop();
            else
                ans[j--] = s[i];
        }

        return ans;
    }
};