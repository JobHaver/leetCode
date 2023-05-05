class Solution {
public:
    int maxVowels(string s, int k) {
        int vowelChainMax = 0;
        int vowelChainCurr = 0;

        for(int i = 0; i < k; i++){
            char& c = s[i];
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                vowelChainMax = max(++vowelChainCurr, vowelChainMax);
        }

        int length = s.length();
        for(int i = k; i < length; i++){
            char& c = s[i], t = s[i-k];
            if(t=='a' || t=='e' || t=='i' || t=='o' || t=='u')    
                vowelChainCurr--;

            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                vowelChainMax = max(++vowelChainCurr, vowelChainMax);
        }

        return vowelChainMax;
    }
};