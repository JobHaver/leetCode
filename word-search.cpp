class Solution {
private:
    vector<vector<char>> *b;
    string *w;

    bool helper(int index, int i, int j){
        if(i < 0 || i == (*b).size() || j < 0 || j == (*b)[i].size() || (*b)[i][j] != (*w)[index])
            return false;

        if(++index == (*w).size())
            return true;

        char curr = (*b)[i][j];
        (*b)[i][j] = NULL; //remove char so no backtracking

        bool res = helper(index, i-1, j) || helper(index, i+1, j) || helper(index, i, j-1) || helper(index, i, j+1);

        (*b)[i][j] = curr; //return char

        return res;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        b = &board;
        w = &word;
        
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
                if(helper(0, i, j))
                    return true;

        return false;
    }
};