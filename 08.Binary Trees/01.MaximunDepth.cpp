/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root) {
        // base case
        if (root == NULL) {
            return 0;
        }

        // left call
        int l = solve(root->left);

        // right call
        int r = solve(root->right);

        if (l > r) {
            return l + 1;
        } else {
            return r + 1;
        }
    }
    int maxDepth(TreeNode* root) { return solve(root); }
};