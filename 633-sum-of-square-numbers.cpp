class Solution {
public:
    bool judgeSquareSum(int c) {
        bool bl = false;
        long long p = c;
        for (long long i = 0; i < 1e5; i++) {
            long long x = i;
            long long temp = p - (x * x);
            if (temp < 0) continue;
            long long int y = sqrtl(temp);
            if (y * y + x * x == c) bl = true;
        }
        return bl;
    }
};