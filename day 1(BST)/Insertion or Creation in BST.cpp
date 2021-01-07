								/******leetcode  1008 *************/
/***************************** Creation of a BST **************************************/

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
    TreeNode* insert(TreeNode *root,int data)
    {
        if(root==NULL)
        {
            root=new TreeNode(data);
        }
        else if(data>root->val)
        {
            root->right=insert(root->right,data);
        }
        else
        {
            root->left=insert(root->left,data);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=NULL;
        for(int i=0;i<preorder.size();i++)
        {
            if(root==NULL)
            {
                root=new TreeNode(preorder[i]);
            }
            else
            {
                root=insert(root,preorder[i]);
            }
        }
        return root;
    }
    
};
