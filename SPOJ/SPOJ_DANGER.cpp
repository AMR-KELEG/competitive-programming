//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  string s;
  cin>>s;
  while(s!="00e0")
  {
    long long int no=atoi(s.substr(0,2).c_str());
    no*=pow(10,atoi(s.substr(3).c_str()));
    
    long long int rem=1;
    while(no>rem)
    {
      no-=rem;
      rem*=2;
    }
    cout<<(2*no)-1<<endl;


    cin>>s;
  } 
}