class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> ans, electronics, grocery, pharmacy, restaurant;

        for(int i = 0; i < code.size(); i++){
            if(!isActive[i])
                continue;

            string &s = code[i];
            if(s == "")
                continue;

            if(!hasGoodChars(s))
                continue;

            string &line = businessLine[i];
            if(line == "electronics")
                electronics.push_back(s);
            if(line == "grocery")
                grocery.push_back(s);
            if(line == "pharmacy")
                pharmacy.push_back(s);
            if(line == "restaurant")
                restaurant.push_back(s);
        }

        sort(electronics.begin(), electronics.end());
        sort(grocery.begin(), grocery.end());
        sort(pharmacy.begin(), pharmacy.end());
        sort(restaurant.begin(), restaurant.end());

        ans.insert(ans.end(), electronics.begin(), electronics.end());
        ans.insert(ans.end(), grocery.begin(), grocery.end());
        ans.insert(ans.end(), pharmacy.begin(), pharmacy.end());
        ans.insert(ans.end(), restaurant.begin(), restaurant.end());

        return ans;
    }

    bool hasGoodChars(string &s){
        for(char c : s)
            if(!(c >= 'a' && c <= 'z') &&
                !(c >= 'A' && c <= 'Z') &&
                !(c >= '0' && c <= '9') &&
                !(c == '_'))
                return false;

        return true;
    }
};