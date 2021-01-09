/******************************* leetcode 230 ****************************************************/

/***** Our task is to evaluate the kth min value in the BST... we perform inorder traversal as it gives values in ascending order of BST and find out the kth value***********/

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
    int ans;
    int count=0;
    void inorder(TreeNode *root)
    {
        if(root==NULL)
            return ;
        inorder(root->left);
        count--;
        if(count==0)
        {
            ans=root->val;
            return;
        }
        inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        count=k;
        inorder(root);
        return ans;
    }
};
