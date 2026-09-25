class Solution {
public:
    vector<int> getRow(int rowIndex) {
      vector<vector<int>> v(rowIndex + 1);
      v[0].push_back(1);
      for (int i = 1; i <= rowIndex; i++) {
        v[i].push_back(1);
        for (int j = 0; j < v[i - 1].size() - 1; j++) {
          v[i].push_back(v[i - 1][j] + v[i - 1][j + 1]);
        }
        v[i].push_back(1);
      }
      vector<int> temp;
      for (int i = 0; i < v[rowIndex].size(); i++) {
        temp.push_back(v[rowIndex][i]);
      }
      return temp;
    }
};