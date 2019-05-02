#include<iostream>
using namespace std;
class heaps
{
	private:
		int highest;
		
		public:
	
			
			
			 void maxheapify(int arr[],int n, int i)
			{
				 int left = (2*i+1);
				 int right = (2*i+2);
				if(left<n && arr[left]>arr[i] )
				highest =left;
				else
				highest = i;
				if(right<n && arr[right]>arr[highest])
				highest = right;
				if(highest!=i)
				{
					
				int temp;
				temp = arr[i];
				arr[i]=arr[highest];
				arr[highest]=temp;
				maxheapify(arr,n,highest);
				
				}
			}
			
			void buildheap(int no,int a[])
			{
				for(int j = (no/2-1);j>=0;j--)
				{
					maxheapify(a,no,j);
				}
				cout<<"Marks after heapify are"<<endl;
				for(int j=0;j<no;j++)
				{
					cout<<a[j]<<"\t";
				}
			}
		
			
};
int main()
{
	int marks[50],m;
	heaps h;
	cout<<"Start entering marks of Second year students";
	for(int i=0;i<=10;i++)
{
	cin>>m;
	marks[i]=m;
    h.buildheap((i+1), marks);
}
cout<<"Maximum marks are"<<marks[0]<<endl;


return 0;
}





