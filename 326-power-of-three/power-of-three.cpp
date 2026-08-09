class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        double log_val = log10(n) / log10(3);
        double x = round(log_val);
        return pow(3,x)==n;
    }
};