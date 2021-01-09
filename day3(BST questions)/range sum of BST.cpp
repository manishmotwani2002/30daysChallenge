/*************** leetcode 938 ***************************/

/************* we have to find the sum of all the values of BST who lies in the range [low,high]***********/



/***************************Approach 1- do level order traversal and traverse only that node which is in the range by using BST property*********/

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        if(root==NULL)
        {
            return 0;
        }
        queue<TreeNode*>q1;
        q1.push(root);
        while(!q1.empty())
        {
            TreeNode *curr=q1.front();
            
            if(curr->val >=low && curr->val <=high)
            {
                sum+=curr->val;
            }
            if(curr->left!=NULL && curr->val >= low)
            {
                q1.push(curr->left);
            }
            if(curr->right!=NULL && curr->val <= high)
            {
                q1.push(curr->right);
            }
            q1.pop();
        }
        return sum;
    }
};


/**********************Approach 2- apply inorder traversal and check the condition on every node**********************/
