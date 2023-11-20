class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int m = 0, p = 0, g = 0, ans = 0;
        for(int i = 0; true; i++){
            for(char c : garbage[i]){
                if(c == 'M')
                    ans += 1 + m, m = 0;
                else if(c == 'P')
                    ans += 1 + p, p = 0;
                else if(c == 'G')
                    ans += 1 + g, g = 0;
            }

            if(i + 1 == garbage.size())
                break;

            m += travel[i];
            p += travel[i];
            g += travel[i];
        }

        return ans;
    }
};