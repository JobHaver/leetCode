class Solution {
public:
    int passThePillow(int n, int time) {
        int loc = time % ((n - 1) * 2);

        return loc > n - 1 ? n - (loc - n + 1) : loc + 1;
    }
};