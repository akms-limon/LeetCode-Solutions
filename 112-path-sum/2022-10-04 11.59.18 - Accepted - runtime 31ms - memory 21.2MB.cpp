class Solution {
public:
	bool hasPathSum(TreeNode* root, int targetSum) {
		bool temp = false;
		if(!root){
			return false;
		}
		if(root->left) temp |= hasPathSum(root->left,targetSum - root->val);
		if(root->right) temp |= hasPathSum(root->right,targetSum - root->val);
		if(!root->left && !root->right){
			if(root->val == targetSum) return true;
			return false;
		}
		return temp;
	}
};
