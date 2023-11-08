class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x = abs(sx - fx), y = abs(sy - fy);
        return !x && !y && t == 1 ? false : t >= max(x, y);
    }
};