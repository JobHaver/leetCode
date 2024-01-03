class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int currRow = 0, newRow = 0, ans = 0;
        for(string &s : bank){
            for(int i = 0; i < s.size(); i++){
                if(s[i] == '1')
                    newRow++;
            }

            if(newRow){
                ans += newRow * currRow;
                currRow = newRow;
                newRow = 0;
            }
        }

        return ans;
    }
};