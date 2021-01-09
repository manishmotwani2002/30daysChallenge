/*****************************leetcode 173 ***************************/

/********** we have to complete the function by forming a iterator over the inorder traversal as per the given rules&functions***********/

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
class BSTIterator {
public:
    stack<TreeNode*>stt;
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode *temp=stt.top();
        stt.pop();
        pushAll(temp->right);
        return temp->val;
        
    }
    void pushAll(TreeNode *head)
    {
        while(head!=NULL)
        {
            stt.push(head);
            head=head->left;
        }
    }
    
    bool hasNext() {
        if(!stt.empty())
            return true;
        else 
            return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
 
