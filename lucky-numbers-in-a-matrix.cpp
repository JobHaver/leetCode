class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;

        for(int i = 0; i < matrix.size(); i++){
            int index = min_element(matrix[i].begin(), matrix[i].end()) - matrix[i].begin(), max = INT_MIN;
            for(int j = 0; j < matrix.size(); j++){
                if(max < matrix[j][index])
                    max = matrix[j][index];
            }

            if(max == matrix[i][index])
                ans.push_back(max);
        }

        return ans;
    }
};