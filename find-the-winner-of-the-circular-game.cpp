class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> players(n);
        for(int i = 0; i < n; i++)
            players[i] = i + 1;

        for(int curr = --k % players.size(); players.size() > 1; curr = (k + curr) % players.size())
            players.erase(players.begin() + curr);

        return players[0];
    }
};