class Solution {
public:
    bool isPalindrome(string s) {
      string temp;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
          temp.push_back(s[i] - 'A' + 'a');
        }
        else if (s[i] >= 'a' && s[i] <= 'z') {
          temp.push_back(s[i]);
        }
        else if (s[i] >= '0' && s[i] <= '9') {
          temp.push_back(s[i]);
        }
      }
      int i = 0, j = temp.size() - 1;
      bool bl = true;
      while (i < j) {
        if (temp[i] != temp[j]) bl = false;
        i++, j--;
      }
      return bl;
    }
};