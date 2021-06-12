#include<iostream>
using namespace std;
class node{
	public:
		int val;
		node *right,*left;
		node(int val)
		{
			this->val=val;
			right=left=NULL;
		}
};
class tree{
	public:
		node *root;
		tree()
		{
			root=NULL;
		}
		void insert(int data)
		{
			if(root==NULL)
			{
				root=new node(data);
				
			}
			else
			{
				node *current=root;
				while(true)
				{
					if(current->val>data)
					{
						if(current->left==NULL)
						{
							current->left=new node(data);
							break;
						}
						else
						{
							current=current->left;
						}
					}
					else
					{
							if(current->right==NULL)
						{
							current->right=new node(data);
							break;
						}
						else
						{
							current=current->right;
						}
					}
				}
			}
		}
			int count_element(node *rt)
			{
				if(rt==NULL)
				{
					return 0;
				}
				return (count_element(rt->left)+count_element(rt->right)+1);
			}
			void inorder(node *rt)
		{
			if(rt==NULL)
			{
				return;
			}
			inorder(rt->left);
			cout<<rt->val<<" ";
			inorder(rt->right);	
		}
};
int main()
{
	tree A;
	A.insert(1);
	A.insert(5);
	A.insert(0);
	A.insert(3);
	A.insert(2);
	A.insert(7);
	A.insert(8);
	A.insert(6);
	A.inorder(A.root);
	cout<<endl;
	cout<<A.count_element(A.root);
}
