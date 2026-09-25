class Solution {
public:
    int strStr(string haystack, string needle) {
      int n = needle.size();
      int j, index = -1, i, k;
      for (i = 0; i < haystack.size(); i++) {
        j = 0, k = i;
        while (j < n && k < haystack.size() && needle[j] == haystack[k]) {
          j++, k++;
        }
        if (j == n && index == -1) index = k - n;
      }
      return index;
    }
};