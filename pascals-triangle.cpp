class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans = {{1}};
        for(int count = 2; count <= numRows; count++){
            vector<int> row(count), &temp = ans.back();
            for(int i = 1, size = temp.size(); i < size; i++)
                row[i] = temp[i] + temp[i - 1];
            
            row[0] = 1, row[row.size()-1] = 1;
            ans.push_back(row);
        }

        return ans;
    }
};