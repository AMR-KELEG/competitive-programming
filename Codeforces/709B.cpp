#include "bits/stdc++.h"
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int n,a;
  cin>>n>>a;
  int minc=1e7,maxc=-1e7;
  vector<int> x(n);
  for(int i=0;i<n;i++)
  {
    cin>>x[i];
    minc=min(minc,x[i]);
    maxc=max(maxc,x[i]);
  }
  sort(x.begin(), x.end());
  int ans=0;
  if(a<=minc)
  {
    int cur=a;
    for(int i=0;i<n-1;i++)
    {
      ans+=x[i]-cur;
      cur=x[i];
    }
  }
  else if(a>=maxc)
  {
    int cur=a;
    for(int i=n-1;i>0;i--)
    {
      ans+=cur-x[i];
      cur=x[i];
    }
  }
  else
  {
    //Go right then left
    int startindx=lower_bound(x.begin(), x.end(),a)-x.begin();
    int cur=a;
    int ans1=0;
    for(int i=startindx;i<n-1;i++)
    {
      ans1+=x[i]-cur;
      cur=x[i];
    }
    //Go left to the end
    for(int i=startindx-1;i>=0;i--)
    {
      ans1+=cur-x[i];
      cur=x[i]; 
    }
    ans=ans1;
    ans1=0;
    cur=a;
    for(int i=startindx;i<n;i++)
    {
      ans1+=x[i]-cur;
      cur=x[i];
    }
    //Go left to the end
    for(int i=startindx-1;i>0;i--)
    {
      ans1+=cur-x[i];
      cur=x[i]; 
    }
    ans=min(ans,ans1);
    ans1=0;
    cur=a;
    startindx=upper_bound(x.begin(), x.end(),a)-x.begin();
    //Go left to the end
    for(int i=startindx-1;i>0;i--)
    {
      ans1+=cur-x[i];
      cur=x[i]; 
    }
    for(int i=startindx;i<n;i++)
    {
      ans1+=x[i]-cur;
      cur=x[i];
    }
    ans=min(ans,ans1);
    ans1=0;
    cur=a;
    //Go left to the end
    for(int i=startindx-1;i>=0;i--)
    {
      ans1+=cur-x[i];
      cur=x[i]; 
    }
    for(int i=startindx;i<n-1;i++)
    {
      ans1+=x[i]-cur;
      cur=x[i];
    }
    ans=min(ans,ans1);
  }

  cout<<ans;
}