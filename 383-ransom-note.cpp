class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp, mp1;
        int n = ransomNote.size(), m = magazine.size();
        for (int i = 0; i < n; i++) {
            mp[ransomNote[i]]++;
        }
        for (int i = 0; i < m; i++) {
            mp1[magazine[i]]++;
        }
        for (auto it : mp) {
            if (mp1[it.first] < it.second) {
                return false;
            }
        }
        return true;
    }
};