/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>> mp;
    queue<pair<TreeNode*, int>> q;
    int level = 0, v_level = 0;
    q.push({root, v_level});
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        pair<TreeNode*, int> x = q.front();
        q.pop();
        mp[x.second][level].insert(x.first->val);
        if (x.first->left != NULL) q.push({x.first->left, x.second - 1});
        if (x.first->right != NULL) q.push({x.first->right, x.second + 1});
      }
      level++;
    }
    vector<vector<int>> ans;
    for (auto it : mp) {
      vector<int> temp;
      for (auto p : it.second) {
        for (auto x : p.second) {
          temp.push_back(x);
        }
      }
      ans.push_back(temp);
    }
    return ans;
  }
};