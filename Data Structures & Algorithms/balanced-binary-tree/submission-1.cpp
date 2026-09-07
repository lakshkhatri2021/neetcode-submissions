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

    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        int leftSide = height(root->left);
        int rightSide = height(root->right);

        if (abs(leftSide - rightSide) > 1) {
            return false;
        }

        bool leftCheck = isBalanced(root->left);
        bool rightCheck = isBalanced(root->right);

        if(!leftCheck || !rightCheck){
            return false;
        }

        return true;
    }
};
