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
  bool check(TreeNode* x, TreeNode* y) {
    if (x == NULL && y == NULL) return true;
    if (x == NULL || y == NULL) return false;
    if (x->val != y->val) return false;
    return check(x->left, y->right)&&check(x->right, y->left);
  }

  bool isSymmetric(TreeNode* root) {
    return check(root->left, root->right);
  }
};


/*
          2
        2   2
      n  3 n  3
*/