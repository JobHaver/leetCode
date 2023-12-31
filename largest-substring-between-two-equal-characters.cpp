class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int max = -1;
        vector<int> alph(26, -1);

        for(int i = 0; i < s.size(); i++){
            int &curr = alph[s[i] - 'a'];

            if(curr == -1)
                curr = i;
            else
                max = std::max(max, i - curr - 1);
        }

        return max;
    }
};