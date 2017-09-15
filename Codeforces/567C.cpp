#include "bits/stdc++.h"
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  long long int n,k;
  cin>>n>>k;
  std::vector<long long int> v(n);
  map<long long int,long long int>mp;
  for(int i=0;i<n;i++)
  {
    cin>>v[i];
    mp[v[i]]++;
  } 
  long long int ans=0;
  int count;
  if(k==1)
  {
    for(int i=0;i<v.size();i++)
    {
      count=mp[v[i]];
      if(count>=3)
      {
        ans+=((count)*(count-1)*(count-2))/6;
      }
      mp[v[i]]=0;
    }
  }
  else
  {
    for(int i=v.size()-1;i>=0;i--)
    {
      if(v[i]%(k*k)==0)
        ans+= mp[v[i]/k] * mp[v[i]/(k*k)];
      cout<<"No "<<v[i]<<" "<<mp[v[i]]<<" "<<mp[v[i]/k]<<" "<<mp[v[i]/(k*k)]<<endl;
      cout<<"Added "<<mp[v[i]/k] * mp[v[i]/(k*k)]<<endl;
      mp[v[i]]--;
    }

  }
  cout<<ans;

  /*
  cout<<n<<endl;
  */
}