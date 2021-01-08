                    /************leetcode 235 ******************/

    /*************** lowest common ancestor of BST(it is the node which is lowest and both the given nodes P and Q are it's descendants)**********/

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
    TreeNode* lca(TreeNode *root,int min,int max)
    {
        if(root==NULL)
            return root;
        else if(root->val >= min && root->val <=max)
        {
            return root;
        }
        else if(root->val > max)
        {
           return lca(root->left,min,max);
        }
        else
           return lca(root->right,min,max);   
        // return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int minimum= min(p->val,q->val);
        int maximum= max(p->val,q->val);
        return lca(root,minimum,maximum);
    }
};
