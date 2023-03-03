class Solution {
public:
    int strStr(string haystack, string needle) {
        int i, j;
        if(needle.size() == 0)
            return -1;

        for(i = 0; i + needle.size() <= haystack.size(); i++){
            if(haystack[i] == needle[0] && haystack[i+needle.size()-1] == needle[needle.size()-1]){
                for(j = 0; j < needle.size() && haystack[i+j] == needle[j]; j++){}

                if(j == needle.size())
                    return i;
            }
        }

        return -1;
    }
};