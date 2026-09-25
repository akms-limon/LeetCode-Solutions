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
  int mxSum(TreeNode* root, int &mx) {
    if (root == NULL) {
      return 0;
    }
    int ls = max(mxSum(root->left, mx), 0);
    int rs = max(mxSum(root->right, mx), 0);
    mx = max(mx, ls + rs + root->val);
    return max(ls, rs) + root->val;
  }

  int maxPathSum(TreeNode* root) {
    int mx = INT_MIN;
    mxSum(root, mx);
    return mx;
  }
};