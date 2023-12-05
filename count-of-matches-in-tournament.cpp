class Solution {
public:
    int numberOfMatches(int n) {
        int matches = 0;
        bool odd;
        while(n != 1){
            odd = n % 2;
            matches += n /= 2;

            if(odd)
                n++;
        }

        return matches;
    }
};