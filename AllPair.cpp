#include<iostream>
#include<cmath>
using namespace std;
class Pair
{
	int s;
	int a[10][10];
	public :
	void setd();
	void getter(int[10][10], int);
	Pair();
	void shortest();	
		
};
void Pair :: setd()
		{
			cout<<"Enter no of nodes : ";
			cin>>s;
			int i=0;
			int j=0;
			cout<<"Enter A0 (100 if infinity) : "<<endl;
			for(i=1;i<=s;i++)
			{
				for(j=1;j<=s;j++)
				{
					if(i==j)
					{
						a[i][j]=0;
						cout<<"["<<i<<"]"<<"["<<j<<"]"<<": "<<a[i][j]<<endl;
					}
					else
					{
						cout<<"["<<i<<"]"<<"["<<j<<"]"<<": ";
						cin>>a[i][j];
					}
				}
			}
			getter(a,s);
		}
			void Pair :: shortest()
		{
			int k=1;
			while(k!=s+1)
			{
				for(int i=1;i<=s;i++)
				{
					for(int j=1;j<=s;j++)
					{
						if(a[i][k]+a[k][j]<a[i][j])
			     	  {
					      a[i][j]=a[i][k]+a[k][j];
				      } 
					}
				}
				cout<<"A"<<k<<" : "<<endl;
				getter(a,s);
				cout<<endl;
				cout<<"_______________________________________________________________________________"<<endl;
				k++;
				
			}
		}
		void Pair :: getter(int a[10][10],int n)
		{
			cout<<endl;
            for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					cout<<a[i][j]<<"  ";
				}
				cout<<endl;
			}
						
		}
	Pair :: Pair()
		{
			setd();
			cout<<endl;
			shortest();
		}
int main()
{
	Pair p;
}
