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
/*
post order left right node
*/
    TreeNode* helper(TreeNode* node){
        if(node==nullptr)return node;
        TreeNode* invertLeft=helper(node->left);
        TreeNode* invertRight=helper(node->right);
        node->right=invertLeft;
        node->left=invertRight;
        return node;
    }

    TreeNode* invertTree(TreeNode* root) {
        TreeNode * invert=helper(root);
        return invert;
    }
};
