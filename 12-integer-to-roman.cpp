class Solution {
public:
    string intToRoman(int num) {
      map<int, char> mp;
      mp[1] = 'I';
      mp[5] = 'V';
      mp[10] = 'X';
      mp[50] = 'L';
      mp[100] = 'C';
      mp[500] = 'D';
      mp[1000] = 'M';
      vector<int> v{1, 5, 10, 50, 100, 500, 1000};
      vector<int> nums;
      int x = 1;
      while (num) {
        int multi = num % 10;
        if (multi == 1 || multi == 5) {
          nums.push_back(multi * x);
        }
        else if (multi > 1 && multi < 4) {
          for (int i = 1; i <= multi; i++)
          nums.push_back(x);
        }
        else if (multi == 4) {
          nums.push_back(multi * x + x);
          nums.push_back(x);
        }
        else if (multi > 5 && multi < 9) {
          for (int i = 6; i <= multi; i++) {
            nums.push_back(x);
          }
          nums.push_back(x * 5);
        }
        else if (multi == 9) {
          nums.push_back(x + 9 * x);
          nums.push_back(x);
        }
        x *= 10;
        num /= 10;
      }
      reverse(nums.begin(), nums.end());
      string ans;
      for (int i = 0; i < nums.size(); i++) {
        ans.push_back(mp[nums[i]]);
      }
      return ans;
    }
};