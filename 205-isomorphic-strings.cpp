class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mp, rev;
        for (int i = 0; i < s.size(); i++) {
            if (mp.find(s[i]) == mp.end()) {
                if (rev.find(t[i]) == rev.end()) {
                    mp[s[i]] = t[i];
                    rev[t[i]] = s[i];
                }
                else {
                    return false;
                }
            }
            else {
                if (mp[s[i]] != t[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};