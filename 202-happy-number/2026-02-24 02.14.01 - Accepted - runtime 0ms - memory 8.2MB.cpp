class Solution {

int cal(int n) {
    int ans = 0;
    while (n) {
        int x = n % 10;
        n /= 10;
        ans += x * x;
    }
    return ans;
}

public:
    bool isHappy(int n) {
        map<int, int> mp;
        while (mp[n] == 0) {
            mp[n] = 1;
            n = cal(n);
            if (n == 10 || n == 1 || n == 100) return true;
        }
        return false;
    }
};