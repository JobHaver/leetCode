class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int total = 0, i = 0;
        for(i = 0; k > 0 && i < chalk.size(); i++)
            k-= chalk[i], total += chalk[i];

        if(k < 0)   
            return i - 1;

        k %= total;
        k -= total;

        for(i = chalk.size() - 1; k < 0 && i >= 0; i--)
            k += chalk[i];

        return i + 1;
    }
};