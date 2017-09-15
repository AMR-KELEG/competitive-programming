//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
  // std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int n,q;
  cin>>n>>q;
  std::vector<int> count(n+1,0);
  std::vector<bool> isdir(n+1,0);
  std::vector<int> notifications;
  std::vector<bool> isread;
  std::vector<int> start(n+1,-1);
  int unseen=0;
  int t,var;
  int lastread=-1;
  for(int i=0;q>0;q--)
  {
    cin>>t>>var;
    if(t==1)
    {
      unseen++;
      if(isdir[var])
      {
        // iterate from start to end of notification making 
        // cout<<"Iterate from "<<start[var]<<" to "<<notifications.size()-1<<" : ";
        for(int in=start[var];in<=notifications.size();in++)
        {
          if(notifications[in]==var)
            isread[in]=1;
        }
        isdir[var]=0;
        start[var]=notifications.size();
      }
      if(count[var]==0)
        start[var]=notifications.size();
      count[var]++;
      notifications.push_back(var);
      isread.push_back(0);
    }
    else if(t==2)
    {
      //read all of type x
      if(count[var])
        isdir[var]=1;
      unseen-=count[var];
      count[var]=0;
    }
    else
    {
      // read all up to var
      if(var>lastread)
      {
        // start reading from lastread+1 to var-1
        // cout<<"Search from "<<lastread+1<<" to "<<var-1<<" : ";
        for(int in=lastread+1;in<var;in++)
        {
          if(!isread[in] && count[notifications[in]])
          {
            // cout<<"Read "<<in<<" ";
            unseen--;
            count[notifications[in]]--;
          }
        }
        lastread=var-1;
      }
    }
    printf("%d\n", unseen);
  } 
}