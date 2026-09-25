class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> v;
        int pos = 0;
        for (int i = 0; i < chars.size(); i++) {
          char ch = chars[i];
          int cnt = 0;
          while (i < chars.size() && chars[i] == ch) {
            cnt++;
            i++;
          }
          i--;
          chars[pos] = ch;
          pos++;
          if (cnt != 1) {
            vector<int> temp;
            while (cnt) {
              temp.push_back(cnt % 10);
              cnt/=10;
            }
            reverse(temp.begin(), temp.end());
            for (int j = 0; j < temp.size(); j++) {
              char tempch = temp[j] + '0';
              chars[pos] = tempch;
              pos++;
            }
          }
        }
        chars.resize(pos);
        return chars.size();
    }
};