//AC
#include "bits/stdc++.h"
using namespace std;
#define X first
#define Y second

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int n;
  cin>>n;
  while(n!=0)
  {
    int H,V;
    std::vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)
    {
      cin>>v[i].X>>v[i].Y;
      if(i==n/2)
      {
        H=v[i].X;
        V=v[i].Y;
      }
    }
    int Stan=0,Ol=0;
    for(int i=0;i<n;i++)
    {
      if((v[i].X>H && v[i].Y>V)||(v[i].X<H && v[i].Y<V))
      {
        Stan++;
      }
      else if((v[i].X>H && v[i].Y<V)||(v[i].X<H && v[i].Y>V))
      {
        Ol++;
      } 
    }
    cout<<Stan<<" "<<Ol<<endl;
    cin>>n;
  }
}