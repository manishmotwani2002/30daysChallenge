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
    int solve(TreeNode* root,int &ans)
    {
        if(root==NULL)
            return 0;
        int l=solve(root->left,ans);
        int r=solve(root->right,ans);
        //if not included
        int temp=max(l,r)+1;
        //if included
        ans=max({ans,l+r+1,temp});
        return temp;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans=0;
        solve(root,ans);
        return ans-1;
    }
};
