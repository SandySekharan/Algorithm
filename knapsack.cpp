#include <iostream>
using namespace std;
int main()
{
  int W,n,flag,u,i;
  int obj[20];
  float ratio[20],weight[20],profit[20],x[20]={0};
  cout<<"\nEnter total capacity:";
  cin>>W;
  cout<<"Enter number of items:";
  cin>>n;
  cout<<"Enter weight and profit for item\n";
  for(i=0;i<n;i++)
  {
    cout<<"\nWeight :";
    cin>>weight[i];
    cout<<"Profit :";
    cin>>profit[i];
    obj[i]=i+1;
    ratio[i]=profit[i]/weight[i];
  }
  for(i=0;i<n-1;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      if(ratio[j]<ratio[j+1])
      {
        swap(ratio[j],ratio[j+1]);
        swap(weight[j],weight[j+1]);
        swap(profit[j],profit[j+1]);
        swap(obj[j],obj[j+1]);
      }
    }
  }
  cout<<"\nSorted According to P/W:"<<endl;
  cout<<"w:"<<" ";
  for(i=0;i<n;i++)
  {
    cout<<weight[i]<<" ";
  }
  cout<<"\n";
  cout<<"p:"<<" ";
  for(i=0;i<n;i++)
  {
    cout<<profit[i]<<" ";
  }
  float total=0;
  u=W;
  for(i=0;i<n;i++)
  {
    if(weight[i]>u)
      break;
    else
    {
      x[i]=1;
      total+=profit[i];
      u-=weight[i];
    }
  }
  if(i<n)
  x[i]=u/weight[i];
  total+=(x[i]*profit[i]);
  cout<<"\n\nProfit="<<total<<"\n";
  cout<<"\nThe resultant vector is\n";
  for(i=0;i<n;i++)
  {
    cout<<x[i]<<" ";
  }
  cout<<"\n\nObjects\n";
  for(i=0;x[i]!=0;i++)
  {
    cout<<obj[i]<<" ";
  }
  cout<<endl;
  return 0;
}
