//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int n,k;
  cin>>n>>k;
  if(k<=(n-1)*0.5)
  {
    cout<<k*n<<endl;
    for(int f=1;f<=n;f++)
    {
      int next=f+1;
      next=max(1,(next)%(n+1));
      for(int s=0;s<k;s++)
      {
        while(f==next)
          next=max(1,(next+1)%(n+1));
        printf("%d %d\n",f,next);
        next=max(1,(next+1)%(n+1));

      }
    }
  } 
  else
  {
    cout<<-1;
  }
}