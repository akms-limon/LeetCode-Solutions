class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
    long long sum = 0, lo, hi, mid, ck, mx = 0, cnt=0, ans=0;
    for (int i = 0; i < weights.size(); i++){
        sum += weights[i];
        if (weights[i] > mx)
            mx = weights[i];
    }
    lo = mx, hi = sum;
    while (hi - lo >= 0) {   
        cnt = 0;
        mid = (lo + hi) / 2;
        for (int i = 0; i < weights.size(); i++){
            ck = 0;
            while (ck <= mid && i < weights.size()){
                ck += weights[i];
                i++;
            }
            if (ck <= mid)
                cnt++;
            else{
                cnt++; i--;
                ck -= weights[i];
            } i--;
        }
        if (cnt <= days)
            hi = mid-1;
        else if (cnt > days)
            lo = mid + 1;
    }
    return lo;
    }
};