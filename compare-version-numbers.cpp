class Solution {
private:
    int helper(int &i, string &v){
        int val = 0;
        for(; i < v.size() && v[i] != '.'; i++)
            val = val * 10 + (v[i] - '0');

        return val;
    }

public:
    int compareVersion(string version1, string version2) {
        int i1 = 0, i2 = 0;
        for(; i1 < version1.size() && i2 < version2.size(); i1++, i2++){
            int int1 = helper(i1, version1), int2 = helper(i2, version2);

            if(int1 > int2)
                return 1;
            else if(int1 < int2)
                return -1;
        }

        for(; i1 < version1.size(); i1++)
            if(helper(i1, version1))
                return 1;

        for(; i2 < version2.size(); i2++)
            if(helper(i2, version2))
                return -1;

        return 0;
    }
};