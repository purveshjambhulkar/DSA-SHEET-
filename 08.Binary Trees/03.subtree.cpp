class Solution {
public:
    // Helper function to check if two trees are identical.
    bool findSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) {
            return true; // Both trees are null, so they are identical.
        }
        if (!root || !subRoot || root->val != subRoot->val) {
            return false; // Trees are not identical if one is null or values don't match.
        }

        // Recursively check the left and right subtrees.
        return findSubtree(root->left, subRoot->left) && findSubtree(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false; // An empty tree cannot contain a non-empty subtree.
        }

        // Check if the current node's tree matches the subtree or if the subtree is found in the left or right subtree.
        return findSubtree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
