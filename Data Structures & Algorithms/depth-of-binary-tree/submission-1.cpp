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

    int maxHeight(TreeNode* node){
        if(node==nullptr)return 0;

        int left=maxHeight(node->left); //explore left
        int right=maxHeight(node->right); //explore right

        return (1 + max(left,right)); //process the current node
        /*
        if you carefully observe we are doing a post order traversal
        where we need to get the state of our child nodes first 
        bottom-up approach
        */
    }

    int maxDepth(TreeNode* root) {
        /*
        we will use recursion to solve this problem and a bottom-up approach
        to know the height of the current state we must know the height of there children first
                   1 
             2          3
        null  null    4  null
                     
        */
        int height=maxHeight(root);
        return height;
    }
};
