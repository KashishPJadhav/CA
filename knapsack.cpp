#include<iostream>
using namespace std;
class sack
{
int n;
int p[10];
int w[10];
int capf;
float profit1;
float profit2;
float profit3;

  public:
      void getd()
      {
      	cout<<"\nEnter Size :  ";
      	cin>>n;
         int i;
         cout<<"\nEnter profit : ";
           for(i=0;i<n;i++)
         {
           cin>>p[i];
         }
         cout<<"\nEnter weight : ";
           for(i=0;i<n;i++)
         {
           cin>>w[i];
         }
         cout<<"\nEnter Capacity : ";
         cin>>capf;
      }
      float sum(int n,int cap,int wx[10],int px[10],float xx[10])
      {
      	int i;
       int cap1;
       cap1=capf;
       for(i=0;i<n;i++)
         {
            if(wx[i]<=cap1)
                {
                    xx[i]=1;
                    cap1=cap1-wx[i];
                }
           else if(wx[i]>cap1 && cap1!=0)
                {
                   xx[i]=(float)cap1/wx[i];
                   cap1=0;
                }
          else
             {
                xx[i]=0;
             }
          }
        cout<<endl<<"solution : ";
      for(i=0;i<n;i++)
        {
          cout<<xx[i]<<" ";
         }
     float sum=0;
     for(i=0;i<n;i++)
        {
          sum=sum+(xx[i]*px[i]);
         }
         return sum;
	  }
      void decreasep()
            {
            	float x[10];
            	int w1[10];
            	int p1[10];
            	int i;
            	for(i=0;i<n;i++)
            	{
            		w1[i]=w[i];
				}
				for(i=0;i<n;i++)
            	{
            		p1[i]=p[i];
				}
                int temp=0;
                int temp1=0;
                int j,k;
                for(i=0;i<n;i++)
                 {
                    for(j=i+1;j<n;j++)
                     {
                        if(p1[i]<p1[j])
                          {
                           
                            temp=p1[i];
                            p1[i]=p1[j];
                            p1[j]=temp;
                           temp1=w1[i];
                            w1[i]=w1[j];
                            w1[j]=temp1;
                          }
                     }
                 }
               cout<<"Decrease profit : ";
                for(i=0;i<n;i++)
         {
           cout<<p1[i]<<" ";
         }
         cout<<endl<<"corresponding weight: ";
         for(i=0;i<n;i++)
         {
           cout<<w1[i]<<" ";
         }
          profit1=sum(n,capf,w1,p1,x);
          cout<<"\nProfit : "<<profit1<<endl;  
		   cout<<"_____________________________________________________________________________________________________________________";  
        }
        void decreasew()
            {
            	cout<<endl;
            	float x[10];
            	int w2[10];
            	int p2[10];
            	int i;
            	for(i=0;i<n;i++)
            	{
            		w2[i]=w[i];
            		p2[i]=p[i];
				}
                int temp=0;
                int temp1=0;
                int j,k;
                for(i=0;i<n;i++)
                 {
                    for(j=i+1;j<n;j++)
                     {
                        if(w2[i]>w2[j])
                          {
                            temp=p2[i];
                            p2[i]=p2[j];
                            p2[j]=temp;
                           temp1=w2[i];
                            w2[i]=w2[j];
                            w2[j]=temp1;
                          }
                     }
                 }
               cout<<"Decrease weight : ";
                for(i=0;i<n;i++)
         {
           cout<<w2[i]<<" ";
         }
         cout<<endl<<"corresponding profit: ";
         for(i=0;i<n;i++)
         {
           cout<<p2[i]<<" ";
         }
		 profit2=sum(n,capf,w2,p2,x);
          cout<<"\nProfit : "<<profit2<<endl;  
		  cout<<"_____________________________________________________________________________________________________________________";
        }
   void decreasepw()
   {
   	cout<<endl;
   	 float pw[10];
   	 float x[10];
   	 int w3[10];
   	 int p3[10];
   	 int i;
   	 for(i=0;i<n;i++)
   	 {
   	 	pw[i]=(float)p[i]/w[i];
   	 	w3[i]=w[i];
   	 	p3[i]=p[i];
   	 }
   	 cout<<endl;
   	 for(i=0;i<n;i++)
   	 {
   	 	cout<<pw[i]<<" ";
		}
   	 	float temp=0;
                float temp1=0;
                int j,k;
                for(i=0;i<n;i++)
                 {
                    for(j=i+1;j<n;j++)
                     {
                        if(pw[i]<pw[j])
                          {
                            temp=pw[i];
                            pw[i]=pw[j];
                            pw[j]=temp;
                           temp1=w3[i];
                            w3[i]=w3[j];
                            w3[j]=temp1;
                            temp=p3[i];
                            p3[i]=p3[j];
                            p3[j]=temp;
                          }
                     }
                 }
               cout<<"Decrease Pi/Wi : ";
                for(i=0;i<n;i++)
         {
           cout<<pw[i]<<" ";
         }
         cout<<endl<<"corresponding weight: ";
         for(i=0;i<n;i++)
         {
           cout<<w3[i]<<" ";
         }
         cout<<endl<<"corresponding profit: ";
         for(i=0;i<n;i++)
         {
           cout<<p3[i]<<" ";
         }
         profit3=sum(n,capf,w3,p3,x);
          cout<<"\nProfit : "<<profit3<<endl; 
		cout<<"_____________________________________________________________________________________________________________________";
	 }
  sack()
  {
      getd();
      decreasep();
      decreasew();
      decreasepw();
      cout<<endl;
      if(profit1>profit2 && profit1>profit3)
      {
      	cout<<"Decreasing order of profit is optimal solution : "<<profit1;
	  }
	  else if(profit2>profit1 && profit2>profit3)
	  {
	  	cout<<"Increasing order of weight is optimal solution : "<<profit2;
	  }
	  else if(profit3>profit1 && profit3>profit2)
	  {
	  	cout<<"Decreasing order of Pi/Wi is optimal solution : "<<profit3;
	  }
	  else if(profit1==profit2 && profit1>profit3)
	  {
	  	cout<<"Decreasing order of profit and Increasing order of weight is optimal solution : "<<profit1;
	  }
	  else if(profit3==profit2 && profit2>profit1)
	  {
	  	cout<<"Decreasing order of Pi/Wi and Increasing order of weight is optimal solution : "<<profit2;
	  }
	  else if(profit3==profit1 && profit1>profit2)
	  {
	  	cout<<"Decreasing order of Pi/Wi and Decreasing order of profit is optimal solution : "<<profit1;
	  }
	  else if(profit1==profit3==profit2)
	  {
	  	cout<<"All are optimal solution.";
	  }
	  else
	  {
	  	cout<<"No optimal solution.";
	  }
  }
};
int main()
{
  sack s;
}
