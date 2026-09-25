class Solution {
public:
    int romanToInt(string s) {
      map<char, int> mp;
      mp['I'] = 1;
      mp['V'] = 5;
      mp['X'] = 10;
      mp['L'] = 50;
      mp['C'] = 100;
      mp['D'] = 500;
      mp['M'] = 1000;
      vector<int> v;
      for (int i = 0; i < s.size(); i++) {
        v.push_back(mp[s[i]]);
      }
      int ans = 0;
      for (int i = 0; i < v.size(); i++) {
        if (i == v.size() - 1) {
          ans += v[i];
        }
        else {
          if (v[i] >= v[i + 1]) {
            ans += v[i];
          }
          else {
            ans += (v[i + 1] - v[i]);
            i++;
          }
        }
      }
      return ans;
    }
};