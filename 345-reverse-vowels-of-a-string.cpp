class Solution {
public:
    string reverseVowels(string s) {
        map<char, int> mp;
        string temp;
        mp['a']++, mp['e']++, mp['i']++, mp['o']++, mp['u']++;
        mp['A']++, mp['E']++, mp['I']++, mp['O']++, mp['U']++;
        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i]]) {
                temp.push_back(s[i]);
            }
        }
        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i]]) {
                ans.push_back(temp[temp.size() - 1]);
                temp.pop_back();
            }
            else {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};