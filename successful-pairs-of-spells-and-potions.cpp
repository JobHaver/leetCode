class Solution {
private:
    int search(vector<int>& potions, long long success, long long spell) {
        int left = 0, right = potions.size(), middle;

        while(left < right){
            middle = (left + right) / 2;

            potions[middle] * spell < success ? left = middle + 1 : right = middle;
        }

        return left;
    }

public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        for(int &spell : spells)
            spell = potions.size() - search(potions, success, spell);

        return spells;
    }
};