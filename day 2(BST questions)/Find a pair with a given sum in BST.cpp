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
    void inorder(TreeNode* head,vector<int>& vtt)
    {
        if(head==NULL)
            return ;
        inorder(head->left,vtt);
        vtt.push_back(head->val);
        inorder(head->right,vtt);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>vtt;
        if(root==NULL)
        {
            return false;
        }
        //first evaluate the inorder traversal 
        inorder(root,vtt);
        //then apply 2 pointer to find the sum
        int n=vtt.size();
        if(n==1)
            return false;
        int start=0;
        int end=n-1;
        while(start<end)
        {
            if(vtt[start]+vtt[end]==k)
            {
                return true;
            }
            else if(vtt[start]+vtt[end]>k)
            {
                end--;
            }
            else
            {
                start++;
            }
        }
        return false;
    }
};
