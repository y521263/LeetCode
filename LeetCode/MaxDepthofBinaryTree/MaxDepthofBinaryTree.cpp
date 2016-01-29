//https://leetcode.com/problems/maximum-depth-of-binary-tree/
#include<iostream>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int GetDepth(TreeNode* root)
{
	if (root == NULL) return 0;
	int l1 = GetDepth(root->left);
	int r1 = GetDepth(root->right);
	if (l1 > r1)
		return l1 + 1;
	else
		return r1 + 1;
}
int maxDepth(TreeNode* root) {
	return GetDepth(root);
}
int main()
{
	TreeNode* root = new TreeNode(0);
	root->left = new TreeNode(0);
	root->right = new TreeNode(0);
	int a = maxDepth(NULL);
	return 0;
}