class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> letters(26);

        for(char c : text)
            letters[c-'a']++;
        
        int numberOfBallons = INT_MAX;
        numberOfBallons = min(numberOfBallons, letters[1]);
        numberOfBallons = min(numberOfBallons, letters[0]);
        numberOfBallons = min(numberOfBallons, letters[11]/2);
        numberOfBallons = min(numberOfBallons, letters[14]/2);
        numberOfBallons = min(numberOfBallons, letters[13]);
        return numberOfBallons;
    }
};