//referenced from gfg

#define ll long long

ll ans;

ll maxSum(Node *root)
{
    if(root == NULL)
    return INT_MIN;
    
    ll l1 = maxSum(root->left);
    
    ll l2 = maxSum(root->right);
    
    if(!(root->left == NULL || root->right == NULL))
    ans = max(ans,l1 + l2 + (root->data));
    
    if(l1 == INT_MIN && l2 == INT_MIN)
    return (root->data);
    else
    return (max(l1,l2) + (root->data));
}

int maxPathSum(Node* root)
{
    ans = INT_MIN;
    // code here  
    ll v = maxSum(root);
    
    return ans;
    
}
