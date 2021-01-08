                    /************leetcode 98 ******************/

    /*************** Validate a BST(to validate it we must traverse the tree recursively and check each node for the BST property) **********/


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
    bool valid(TreeNode* root,long min,long max)
    {
        if(root==NULL)
        {
            return true;
        }
        else if(root->val > min && root->val < max)
        {
            return valid(root->left,min,root->val) && valid(root->right,root->val,max);
        }
        else 
            return false;
    }
    bool isValidBST(TreeNode* root) {
        long min=LONG_MIN,max=LONG_MAX;
        return valid(root,min,max);
    }
};
