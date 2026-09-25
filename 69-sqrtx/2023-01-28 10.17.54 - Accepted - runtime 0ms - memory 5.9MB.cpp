class Solution {
public:
    int mySqrt(int x) {
        long long lo=0, hi=x, mid;
        while(lo<hi){
            mid = (lo+hi+1)/2;
            if(mid*mid<=x){
                lo=mid;
            }
            else {
                hi=mid-1;
            }
        }
        return lo;
    }
};