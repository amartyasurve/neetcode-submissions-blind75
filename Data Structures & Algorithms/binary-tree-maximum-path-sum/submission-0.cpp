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
    int f(TreeNode* node,int& ans){
        if(!node)return -1001;
        int leftside=f(node->left,ans);
        int rightside=f(node->right,ans);
        ans=max({ans,node->val,leftside,rightside,leftside+node->val,rightside+node->val,rightside+leftside+node->val});
        return (node->val+max({leftside,rightside,0}));
    }

    int maxPathSum(TreeNode* root) {
    int ans=root->val;
    if(!root->left && !root->right)return root->val;
    int get=f(root,ans);
    return ans;


    }
};
