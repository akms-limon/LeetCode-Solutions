class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> index;
        map<char, int> mp;
        int n = s.size();
        int l = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            if (mp[s[i]]) {
                mx = max(mx, i - l);
                for (int j = l; j <= index[s[i]]; j++) {
                    mp[s[j]] = 0;
                }
                l = index[s[i]] + 1;
            }
            index[s[i]] = i;
            mp[s[i]]++;
        }
        mx = max(mx, n - l);
        return mx;
    }
};