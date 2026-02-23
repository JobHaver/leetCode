class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i = left; i <= right; i++)
            if(areSetBitsPrime(i))
                ans++;

        return ans;
    }

    bool areSetBitsPrime(int n)
    {
        unsigned int bits = 0, count = 0;
        for (; n; bits++) 
            n &= (n - 1);

        if (bits <= 1)
            return false;

        for (int i = 2; i * i <= bits; i++)
            if (bits % i == 0)
                count++;

        return !(count > 0);
    }
};