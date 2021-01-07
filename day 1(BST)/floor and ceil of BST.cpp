//floor and ceil of a BST
#include<bits/stdc++.h>
using namespace std;
class node
{
	public:
		int data;
		node *left;
		node *right;
}*root=NULL;
node* create(node *root,int val)
{
	if(root==NULL)
	{
		root = new node;
		root->data=val;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	else
	{
		if(val > root->data)
		{
			root->right=create(root->right,val);
		}
		else
		{
			root->left =  create(root->left,val);
		}
	}
}
void floorceil(node *root,int val)
{
	int flr=-1;
	int cel=-1;
	while(root!=NULL)
	{
		if(val == root->data)
		{
			flr=val;
			cel=val;
			break;
//			return val;
		}
		else
		{
			if(val < root->data)
			{
				cel=root->data;
				root=root->left;
			}
			else
			{
				flr=root->data;
				root=root->right;
			}
		}
	}
	cout<<"floor is: "<<flr<<endl;
	cout<<"ceil is: "<<cel<<endl;
	
}
int main()
{
	//creation
	int n,i,element;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>element;
		root=create(root,element);
	}
	cout<<endl;
	int val;
	cin>>val;
	floorceil(root,val);
	return 0;
}
