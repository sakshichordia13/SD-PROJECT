#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class bstnode
{
	private:
	int Roll_No;
	string name[2]; 
string dept;
string cell;
string dob;
char div;
	bstnode *l;
	bstnode *r;
	
	public:
	
		
	
		bstnode * insert( bstnode *head,string n[2],string branch,char c,int key,string date,string tel)
		{
			
			bstnode *p = new bstnode;
		
			bstnode *temp; 
			bstnode *q;
			
			p->Roll_No=key;
			
			for(int i=0;i<=1;i++)
				p->name[i] = n[i];
			
				
				p->dept = branch;
				p->dob = date;
			   p->cell = tel;
			p->div = c;
	
				p->l=NULL;
				p->r=NULL;
			
			if(head == NULL)
			{
			head=p;
			return head;
				}
				else
				{
				q=head;
			
			while(q!=NULL)
			{
				temp=q;
				if(p->Roll_No<q->Roll_No)
			    	q=q->l;
			    	else
					q=q->r;
				}
				
				
				if(p->Roll_No<temp->Roll_No)
				temp->l=p;
			    else
			    temp->r=p;
				
				return head;
			
		}
	}
	
		void search(bstnode *head,int key,char c,string branch)
		{
			bool found;
			bstnode *fitem=NULL;
			if(head==NULL)
			{
				found=false;
				cout<<"Not found";
			}
			 else if(key<head->Roll_No)
			search(head->l,key,c,branch);
			else if(key>head->Roll_No)
			search(head->r,key,c,branch);
			else if((key==head->Roll_No) && (c==head->div )&& (branch == head->dept))
			{
			
			found=true;
			cout<<"Data is found"<<endl;
			cout<<"Entry in the record is as follows"<<endl;
			cout<<"Roll number :";
			cout<<head->Roll_No <<endl;
			cout<<"Name : ";
			 for(int i=0;i<=1;i++)
			cout<<head->name[i]<<"\t";
			cout<<endl;
			cout<<"Department & Division : ";
			cout<<head->dept<<"\t";
			cout<<head->div<<endl;
		    cout<<"Date Of Birth : ";
			cout<<head->dob<<endl;
			cout<<"Telephone Number : ";
			cout<<head->cell<<endl;
			
			}
			else
		{
		cout<<"Not found";
		
		}
	}
		
	void edit(bstnode *head,int key,char c,string b )
	{
	
		string n[2];
		string branch;
		string d;
		string t;
		char cl;
		while(key!=head->Roll_No)
		{
		
	if(key<head->Roll_No)
	{
		head=head->l;
	}
	if(key>head->Roll_No)
	{
		head=head->r;
	}
		}
		
		if((key == head->Roll_No )&& ( c == head->div) && (b  == head->dept))
		{
			
			cout<<"Original Entry in the data is as follows"<<endl;
			cout<< "Roll Number : ";
			cout<<head->Roll_No<<endl;
			cout<<"Name : ";
			 for(int i=0;i<=1;i++)
			cout<<head->name[i] <<"\t";
			cout<<endl;
			 cout<<"Department & Division : ";
		    cout<<head->dept<<"\t";
		    cout<<head->div<<endl;
		    cout<<"Date of Birth : ";
		    cout<<head->dob<<endl;
		    cout<<"Telephone Number : ";
		    cout<<head->cell<<endl;
		    cout<<"Enter the new Data"<<endl;
		    
		    cout<<"Name"<<"\t";
		     for(int j=0;j<=1;j++)
		    cin>>n[j];
		    cout<<"Department"<<"\t";
		    cin>>branch;
		    cout<<"Date of Birth"<<"\t";
		    cin>>d;
		    cout<<"Student Telephone number";
		    cin>>t;
		    cout<<"Division";
		    cin>>cl;
		 for(int i=0;i<=1;i++)
		    head->name[i]= n[i];
		    head->dept = branch;
		    head->div = cl;
		    head->dob = d;
		    head->cell = t;
		}
	}
	

    

		
		void inorder(bstnode *head)
		{
			
			
		
			if(head!=NULL)
			{
				inorder(head->l);
				cout<<setw(5)<<head->Roll_No;
				cout<<setw(13)<<head->name[0];
			    cout<<setw(10)<<head->name[1];
			    cout<<setw(15)<<head->dept;
			    cout<<setw(2)<<head->div;
			    cout<<setw(15)<<head->dob;
			    cout<<setw(15)<<head->cell<<endl;
				
			
				inorder(head->r);
				
			}
			
		}
		
		
		};
	int main()
	{
	 int i, num,Rnum;
	 char choice;
string Name[2];
 string Dept;
string cell;
string dob;
char Div;
	 
	 bstnode b;
bstnode *root = NULL;

	cout<<"Enter the total number of Students who's records you want to add";	
	cin>>num;
	cout<<"Start Entering your data "<<endl;
	for(i=0;i<num;i++)
	{
		cout<<"Roll Number : ";
		cin>>Rnum;
		cout<<" Enter Name :";
		for(int j=0;j<=1;j++)
		cin>>Name[j];
	cout<<" Enter your Department :";
		
		cin>>Dept;
		cout<<"Enter your Division";
		cin>>Div;

		cout<<"Enter Date of Birth";
		cin>>dob;
		cout<<"Enter Student's Telephone number";
		cin>>cell;
		root= b.insert(root,Name,Dept,Div,Rnum,dob,cell);
		
	}
	
	
	 cout<<endl;
     cout<<"---------------------------Student Record Table---------------------------------"<<endl; 
     cout<<"Roll No"<<"\t" <<"\t";
	 cout<<"Name"<<"\t "<< "\t ";
	 cout<<" Department"<<"\t"<<"\t";
	 cout<<"DOB"<<"\t";
	 cout<<"Student Cell No"<<endl;
    b.inorder(root);
			
	
		int ch;
		do
		{
		cout<<"\n"<<"Enter your operation"<<endl;
	cout<<"1.Insert Student "<<endl;
	cout<<"2.Edit Student"<<endl;
	cout<<"3.Search Student"<<endl;
	cout<<"4.Display Students"<<endl;
	cin>>ch;

	switch(ch)
	{
	
	case 1:
		int count;
		cout<<"Enter number of students you want to add";
		cin>>count;
		for(i=0;i<count;i++)
		
		{
		
		cout<<"Enter the Roll Number";
			cin>>Rnum;
			
		cout<<" Enter Name :";
		for(int j=0;j<=1;j++)
		{
		
		   cin>>Name[j];
	}
		   	cout<<" Department :";
		
	
		   cin>>Dept;
		   cout<<"Division";
		   cin>>Div;
	
	cout<<"Enter Date of Birth"<<endl;
	cin>>dob;
	cout<<"Enter Student's Telephone Number"<<endl;
	cin>>cell;
		
		
		root= b.insert(root,Name,Dept,Div,Rnum,dob,cell);
	}
			break;
			
		case 2:
			{
			
			int rno;
			char d;
			string br;
			cout<<"Enter the Roll Number,Division and Branch of the Student to edit"<<endl;
			cout<<"Roll Number :";
			cin>>rno;
			cout<<endl;
			cout<<"Department :";
			cin>>br;
			cout<<endl;
			cout<<"Division : ";
			cin>>d;
			
			b.edit(root,rno,d,br);
			break;
		}
			
			case 3:
				{
				
				int RNO;
				char cl;
				string bran;
				cout<<"Enter Roll Number,Divison,Branch of Student you want to search"<<endl;
				cout<<"Roll Number";
				cin>>RNO;
				cout<<"Department";
				cin>>bran;
				cout<<"Division";
				cin>>cl;
				b.search(root,RNO,cl,bran);
				break;
				}
				case 4:
					{
					
					 cout<<endl;
     cout<<"---------------------------Student Record Table---------------------------------"<<endl; 
     cout<<"Roll No"<<"\t" <<"\t";
	 cout<<"Name"<<"\t "<< "\t ";
	 cout<<" Department"<<"\t"<<"\t";
	 cout<<"DOB"<<"\t";
	 cout<<"Student Cell No"<<endl;
					b.inorder(root);
					break;
				}
					default:
						cout<<"Wrong choice";
						break;
					}
						cout<<"\n"<<"Do you want to Continue?(Y/N) ";
				cin>>choice;
			
					
		}
			while(choice == 'y'||'Y');
		
			
	
	
		return 0;	
	}
	
	

