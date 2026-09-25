class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        map<char, string> mp;
        map<string, char> rev;
        int i = 0;
        while (ss >> word) {
            if (mp.find(pattern[i]) == mp.end()) {
                if (rev.find(word) == rev.end()) {
                    mp[pattern[i]] = word;
                    rev[word] = pattern[i];
                }
                else {
                    cout << "1" << '\n';
                    return false;
                }
            }
            else {
                if (mp[pattern[i]] != word) {
                    cout << "2" << '\n';
                    return false;
                }
            }
            i++;
       }
        return true && (i == pattern.size());
    }
};