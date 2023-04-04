class Solution {
public:
    int partitionString(string s) {
        vector<int> alphabet(26, -1); //use char as key
        int ans = 1, start = 0;

        for(int i = 0; i < s.length(); i++){
            int& curr = alphabet[s[i] - 'a'];
            //cout << curr << " " << start << endl;
            if(curr >= start)
                start = i, ans++;

            curr = i;
        }

        return ans;
    }
};