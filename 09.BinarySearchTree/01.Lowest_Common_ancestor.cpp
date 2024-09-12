/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      int curr = root->val;
      if(curr > p->val && curr > q->val){
        return lowestCommonAncestor(root->left , p ,q);
      }
      if(curr < p->val && curr < q->val){
        return lowestCommonAncestor(root->right , p , q );
      }
      return root;
    }
    
};

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         int large = max(p->val , q->val);
//         int small = min(p->val , q->val);

//         while(root!=nullptr){
//             if(root->val > large){
//                 root = root->left;
//             }else if(root->val < small){
//                 root = root->right;
//             }else{
//                 return root;
//             }
//         }

//         return nullptr;
//     }
// };