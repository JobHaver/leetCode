class Solution {
public:
    int countSeniors(vector<string>& details) {
        int oldPeople = 0;
        for(string& s : details)
            if(s[11] > '6' || (s[11] == '6' && s[12] > '0'))
                oldPeople++;

        return oldPeople;
    }
};