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
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> v;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
      TreeNode* p;
      double x = 0;
      int size = q.size();
      for (int i = 0; i < size; i++) {
        p = q.front();
        x += p->val;
        q.pop();
        if (p->left != NULL) q.push(p->left);
        if (p->right != NULL) q.push(p->right);
      }
      v.push_back(x / size);
    }
    return v;
  }
};