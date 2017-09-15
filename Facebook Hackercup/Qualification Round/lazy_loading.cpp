#include "bits/stdc++.h"
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("lazy_loading.txt","r",stdin);
    freopen("lazy_loading_out.txt","w",stdout);
  #endif
  int T;
  cin>>T;
  for(int t=1;t<=T;t++)
  {
    int n;
    cin>>n;
    priority_queue<short>w;
    int curW;
    for(int i=0;i<n;i++)
    {
      cin>>curW;
      w.push(curW);
    }
    curW=0;
    int ans=0;
    deque<short>q;
    while(!w.empty())
    {
      q.push_front(w.top());
      w.pop();
    }

    while(!q.empty())
    {
      curW=q.back();
      q.pop_back();
      if(curW>=50)
      {
        curW=0;
        ans++;
      }
      else
      {
        int inc=curW;
        while(curW<50 && !q.empty())
        {
          curW+=inc;
          q.pop_front();
        }
        if(curW>=50)
        {
          ans++;
        }
        curW=0;
      }
    }
    cout<<"Case #"<<t<<": "<<ans<<endl;
  }
} 