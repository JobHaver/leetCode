class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int length = s.length();
        int char_num;
        long ans = 0;
        
        bool neg = false;
        
       // map<char, int> number = {{'1', },}
        
        for(; s[i] == ' '; i++);
        
        if(s[i] == '-'){
            neg = true;
            i++;
        }
        else if(s[i] == '+')
            i++;
        
        for(;i < length; i++){
            char_num = s[i] - '0';
            if(char_num >= 0 && char_num <= 9){
                ans *= 10;
                ans += char_num;
                
                if(ans > INT_MAX)
                    break;
            }
            else
                break;
            //cout << s[i] << " num "<< s[i] - 48 << endl;
        }
        
        
        if(neg)
            ans *= -1;
        
        if(ans > INT_MAX)
            return INT_MAX;
        else if(ans < INT_MIN)
            return INT_MIN;
        
        return ans;
    }
};