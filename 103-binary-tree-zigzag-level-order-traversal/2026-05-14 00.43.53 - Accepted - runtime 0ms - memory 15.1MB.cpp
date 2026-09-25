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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> v;
    if (root == NULL) return v;
    queue<TreeNode*> q;
    q.push(root);
    bool bl = false;
    while (!q.empty()) {
      TreeNode* p;
      int size = q.size();
      vector<int> temp;
      for (int i = 0; i < size; i++) {
        p = q.front();
        temp.push_back(p->val);
        q.pop();
        if (p->left != NULL) q.push(p->left);
        if (p->right != NULL) q.push(p->right);
      }
      if (bl) {
        reverse(temp.begin(), temp.end());
        bl = false;
      }
      else bl = true;
      v.push_back(temp);
    }
    return v;
  }
};