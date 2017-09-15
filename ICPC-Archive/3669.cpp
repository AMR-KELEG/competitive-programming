//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    std::vector<int> cuts(n);
    for(int i=0;i<n;i++)
    {
      cin>>cuts[i];
    }
    string s;
    cin>>s;
    std::vector<std::vector<int> > cs(s.size()+1,std::vector<int> (26,0));
    for(int i=1;i<=s.size();i++)
    {
      for(int j=0;j<26;j++)
      {
        cs[i][j]=cs[i-1][j];
      }
      cs[i][s[i-1]-'a']++;
    }

    set<int>curCuts;
    curCuts.insert(0);
    curCuts.insert(s.size());
    long long int ans=0;
    for(int i=0;i<cuts.size();i++)
    {
      set<int>::iterator it=curCuts.lower_bound(cuts[i]);
      int endin=*it;
      it--;
      int startin=*it;
      for(int j=0;j<26;j++)
      {
        int l=cs[cuts[i]][j]-cs[startin][j];
        int r=cs[endin][j]-cs[cuts[i]][j];
        if((l==0 && r>0) || (r==0 && l>0))
          ans++;
      }
      curCuts.insert(cuts[i]);
    }
    
    
    cout<<ans<<endl;
  } 
}