//https://leetcode.com/problems/invert-binary-tree/
#include<iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) return root;
    TreeNode* p = root->left;
    root->left = root->right;
    root->right = p;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
int main()
{
    TreeNode* root = new TreeNode(1);
    invertTree(root);
    return 0;
}