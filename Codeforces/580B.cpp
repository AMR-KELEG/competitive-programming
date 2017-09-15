#include "bits/stdc++.h"
using namespace std;
int main()
{
  std::ios::sync_with_stdio(false); 
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  std::map<long long int,long long int>fr;// money - weight
  int n,d;
  cin>>n>>d;
  long long int m,s;//money friendship
  for(int i=0;i<n;i++)
  {
    cin>>m>>s;
    fr[m]+=s;
  }
  long long int maxsum=0,cursum=0;
  map<long long int,long long int>::iterator en=fr.begin();
  for(map<long long int,long long int>::iterator start=fr.begin();start!=fr.end();++start)
  {
    for(;en!=fr.end();++en)
    {
      // 
      if((*en).first<d+(*start).first)
      {
        cursum+=(*en).second;
        //cout<<cursum<<endl;
      }
      else
      {
        break;
      }
    }  
    maxsum=max(maxsum,cursum);
    cursum-=(*start).second;
  }

  cout<<maxsum;
}