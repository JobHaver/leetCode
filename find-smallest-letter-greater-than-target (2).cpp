class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(char c : letters)
            if(c-target >= 1)
                return c;

        return letters[0];
    }
};