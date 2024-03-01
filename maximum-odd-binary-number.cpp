class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = -1;
        for(char &c : s){
            if(c == '1'){
                ones++;
                c = '0';
            }
        }

        s[s.size() - 1] = '1';
        for(int i = 0; ones--; i++)
            s[i] = '1';

        return s;
    }
};