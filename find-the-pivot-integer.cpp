class Solution {
public:
    int pivotInteger(int n) {
        for(int l = 1, r = n, suml = 0, sumr = 0; l <= r;){
            if(l == r && suml == sumr)
                return l;
            
            if(suml < sumr)
                suml += l++;
            else
                sumr += r--;
        }

        return -1;
    }
};