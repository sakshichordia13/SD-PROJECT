#include<iostream>
using namespace std;
class tbstnode
{
	
	bool lbit,rbit;
	tbstnode *right;
	tbstnode *left;
	int data;
 tbstnode *parent=NULL;
	
	public:
	tbstnode *insert( tbstnode *head , int key)
	{
		tbstnode *t;
		t=head;
		while(t!=NULL)
		{
			
			if(key==t->data)
			{
			cout<<"Duplicate key";
			return head;
	        }  
		
      	 parent = t;
	    
		  if(key < t->data )
		 {
			if(t->lbit == false)
			t = t->left;
			else
			break;
		 }
		 else
		 {
			if(t->rbit == false)
			t = t->right;
			else
			break;
		}
	}
	tbstnode *p = new tbstnode;
	p->data = key;
	p->left=NULL;
	p->right=NULL;
	p->lbit=true;
	p->rbit=true;
	
	if( parent = NULL)
	{
	      parent = head =p;
		return head;
		}
	
	
		if(key < parent->data )
		{
		
				p->left = parent->left;
				parent->left=p;
				parent->lbit = false;
				p->right=parent;
			
		}
		else
			{
		     	p->right = parent->right;
			 	parent->right=p;
				parent->rbit = false;
				p->left=parent;
			
			}
	
	return head;
   	}
   
   tbstnode  *inordersuccessor(tbstnode *temp )
   {
   	if(temp->rbit==true)
	return (temp->right);
	else
		{
			temp = temp->right;
			while(temp->lbit == false)
		  	temp=temp->left;
			return temp;
		}
	}
   void inorder(tbstnode *head)
   {
	if(head == NULL)
   		{
			cout<<"Tree is empty";
	   }
		tbstnode *temp1 = head;
	   	while(temp1->lbit==false)
	   	temp1 = temp1->left;
	   	while(temp1!=NULL)
	   	{
			cout<<temp1->data<<"\t";
	   		temp1 = inordersuccessor(temp1);
		}
	}
};
int main()
{

int size,value,i;
tbstnode t;
tbstnode *root =NULL;
cout<<"Enter the total number of nodes in the tree"<<endl;
cin>>size;
cout<<"start entering data of the nodes"<<endl;
for(i=0;i<size;i++)
{
	cin>>value;
 root = t.insert(root,value);	
}
cout<<"\n"<<"Inorder traversal is";
t.inorder(root);
return 0;
}
