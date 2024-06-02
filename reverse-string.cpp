class Solution {
public:
    void reverseString(vector<char>& s) {
        //reverse(s.begin(), s.end()); // <- cowards way out
        for(int i = 0, size = s.size() - 1, mid = s.size() / 2; i < mid; i++)
            swap(s[i], s[size - i]);
    }
};