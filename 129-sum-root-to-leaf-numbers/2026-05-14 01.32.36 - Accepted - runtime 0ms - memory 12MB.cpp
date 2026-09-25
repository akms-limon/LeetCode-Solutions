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
    int ans = 0;
    void cnt(TreeNode* root, int curr) {
      if (root->left != NULL) cnt(root->left, curr * 10 + root->left->val);
      if (root->right != NULL) cnt(root->right, curr * 10 + root->right->val);
      if (root->left == NULL && root->right == NULL) {
        ans += curr;
        return;
      }
    }

    int sumNumbers(TreeNode* root) {
      if (root == NULL) return 0;
      cnt(root, root->val);
      return ans;
    }
};