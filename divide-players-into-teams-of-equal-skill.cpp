class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());

        int total = skill[0] + skill[skill.size()-1];
        long long chemestry = skill[0] * skill[skill.size()-1];
        for(int l = 1, r = skill.size()-2; l < r; chemestry += skill[l++] * skill[r--])
            if(skill[l] + skill[r] != total)
                return -1;
        
        return chemestry;
    }
};