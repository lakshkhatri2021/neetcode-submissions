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
    int heightCheck(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int leftSide = heightCheck(root->left);
        int rightSide = heightCheck(root->right);

        if (rightSide == -1 || leftSide == -1) {
            return -1;
        }

        if (abs(rightSide - leftSide) > 1) {
            return -1;
        }

        return 1 + max(leftSide, rightSide);
    }

    bool isBalanced(TreeNode* root) { return heightCheck(root) != -1; }
};
