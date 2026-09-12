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
    int dfs(TreeNode* node, int maxVal) {
        if (node == NULL) return 0;
        int count = (node->val >= maxVal) ? 1 : 0;
        maxVal = max(node->val, maxVal);
        count += dfs(node->left, maxVal);
        count += dfs(node->right, maxVal);
        return count;
    }
    int goodNodes(TreeNode* root) { return dfs(root, root->val); }
};
