class Solution {
public:
    string largestGoodInteger(string num) {
        char prev = '0', max = '$';
        int count = 0;
        for(char c : num){
            if(c == prev){
                count++;
                continue;
            }
                
            if(prev > max && count > 2)
                max = prev;

            count = 1;
            prev = c;
        }

        if(prev > max && count > 2)
            max = prev;

        return max == '$' ? "" : string(3, max);
    }
};