class Solution {
public:
    double myPow(double x, int n) {
        double val = 1;
        long long N = n;
        if(N<0){
            x = 1/x;
            N = -N;
        }
        while(N){
            if(N % 2 == 1) val = val*x;
            x = x*x;
            N = N/2;
        }
        return val;
    }
};