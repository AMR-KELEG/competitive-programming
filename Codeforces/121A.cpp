//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<long long int> no;
void findno(string s)
{
  if(s.size()>10)
    return ;
  no.push_back(atoll(s.c_str()));
  findno(string(1,'4')+s);
  findno(string(1,'7')+s); 
}
int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  findno("4");
  findno("7");
  sort(no.begin(), no.end());
  // cout<<no.size()<<" "<<no[0]<<" "<<no[1]<<" "<<no[2];
  // cout<<no[no.size()-1]<<endl;
  long long int l,r,n=no[0];
  cin>>l>>r;
  int i=1;
  while(l>n)
  {
    n=no[i++];
  }
  long long int ans=0;
  while(l<=r)
  {
    ans+=n*(min(n,r)-l+1);
    l=n+1;
    n=no[i++];
  }
  cout<<ans;
}