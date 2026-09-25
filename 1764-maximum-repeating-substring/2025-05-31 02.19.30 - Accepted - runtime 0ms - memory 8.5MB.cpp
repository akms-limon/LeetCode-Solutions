class Solution {
public:
    int maxRepeating(string sequence, string word) {
      int ans = 0;
      for (int k = 0; k < sequence.size(); k++) {
        int cnt = 0;
        for (int i = k; i < sequence.size(); i++) {
          int j = 0, temp = i;
          if (word[j] == sequence[i]) {
            while (j < word.size() && i < sequence.size() && word[j] == sequence[i]) {
              j++, i++;
            }
            i--;
          }
          if (j == word.size()) cnt++;
          else {
            ans = max(ans, cnt);
            cnt = 0;
            break;
          }
        }
        ans = max(ans, cnt);
      }
      return ans;
    }
};