class Solution {
public:
    // int fib(int n){ //turns out this exceeds runtime
    //     if (n <= 1)
    //         return n;
    //     return fib(n-1) + fib(n-2);
    // }
    int fib(int n){ // got from stack overflow
        int a = 0, b = 1, t;

        while(n-- > 1){
            t = a;
            a = b;
            b += t;
        }

        return b;
    }

    int climbStairs(int n) {
        return fib(n+1); //did some pen and paper and realized it was fibonacci
    }
};