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
    int height(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }

        int leftSide = height(root->left);
        int rightSide = height(root->right);

        return 1 + max(leftSide, rightSide);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }

        int leftDiam = diameterOfBinaryTree(root->left);
        int rightDiam = diameterOfBinaryTree(root->right);

        int centreDiam = height(root->left) + height(root->right);


        return max(max(leftDiam ,rightDiam), centreDiam);
    }
};
