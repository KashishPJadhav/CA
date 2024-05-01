#include<iostream>
using namespace std;
class merge
{
    public : 
    int a[20];
    int z[10];
    int s;
    int sum;
    void getd();
    void disp();
    merge();
    void ascen(int,int[20]);
};
void merge:: getd()
   {
     cout<<"\nEnter Size : ";
     cin>>s;
     int i=0;
     cout<<"\nEnter data : ";
     for(i=0;i<s;i++)
        {
            cin>>a[i];
        }
   }
   void merge :: disp()
    {
          int i;
     cout<<"\nData : ";
       for(i=0;i<s;i++)
        {
            cout<<a[i]<<" ";
        }
     cout<<endl;
    }
    void merge :: ascen(int s,int a[])
   {
       int i,j,t;
      
      for(i=0;i<s;i++)
      {
        for(j=i+1;j<s;j++)
           { 
                if(a[j]<a[i])
                 {
                      t=a[j];
                      a[j]=a[i];
                      a[i]=t;
                  }
           }
      }

   }
   merge::merge()
   {
      getd();
      disp();
      ascen(s,a);
      disp();
       int i=0;
     int j=0;
     int c=0;
      while(s!=1)
       {
          z[j]=a[0]+a[1];
           for(i=2;i<s;i++)
           {
                 a[i-1]=a[i];
           }
           cout<<"z"<<j+1<<" = "<<z[j]<<endl;
         s=s-1;
        int t=z[j];
          a[0]=t;
           z[j]=t;
          cout<<endl; 
         for(i=0;i<s;i++)
          {
             cout<<a[i]<<"  ";
          }
          j++;
          c++;
         ascen(s,a);
         cout<<endl;
          for(i=0;i<s;i++)
          {
             cout<<a[i]<<"  ";
          }
cout<<"\n-------------------------------------------------------------------------\n";
        }

  sum=0;
     cout<<"Z values : ";
  for(j=0;j<c;j++)
      {
           cout<<z[j]<<" ";
       sum=sum+z[j];
      } 
    cout<<"\nSum of Z : "<<sum;    
}

int main()
{
merge m;
}
