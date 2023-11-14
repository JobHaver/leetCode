class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1), last(26, -1);
        for(int i = 0; i < s.size(); i++){
            int index = s[i] - 'a';
            if(first[index] == -1)
                first[index] = i;
            else
                last[index] = i;
        }

        int ans = 0;
        for(int i = 0; i < first.size(); i++){
            if(first[i] == -1 || last[i] == -1)
                continue;
            
            vector<bool> seen(26);
            for(int j = first[i] + 1, l = last[i]; j < l; j++){
                if(seen[s[j] - 'a'])
                    continue;
                
                seen[s[j] - 'a'] = true;
                ans++;
            }
        }

        return ans;
    }
};