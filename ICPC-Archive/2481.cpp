#include "bits/stdc++.h"
using namespace std;

// (1) Sort the numbers
// (2) Make the cycle Sets
// (3) Write an O(n^2) algorithm to resolve each cycle

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif


    freopen("FILE_NAME.FILE_EXTENSION","r",stdin);
    freopen("FILE_NAME.FILE_EXTENSION","w",stdout);
  int n;
  cin>>n;
  int t=0;
  while(n!=0)
  {
    t++;
    std::vector<int> v(n);
    std::vector<int> per(n);
    set<int>s;
    for(int i=0;i<n;i++)
    {
      cin>>v[i];
      s.insert(v[i]);
    }

    map<int,int> mp; //val to index
    std::map<int, int> iToVal;
    int i=0;
    for(auto val:s)
    {
      mp[val]=i++;      
      iToVal[i-1]=val;
    }

    for(i=0;i<n;i++)
    {
      per[i]=mp[v[i]];
    }
    int ans=0;
    std::vector<pair<int,int> > curSet;// i ,per[i]
    for(int tr=0;tr<n;tr++)
    {

      for(int i=0;i<n;i++)
      {
        if(per[i]!=i)
        {
          //MOVE TO ALL ITEMS IN THE SET
          curSet.push_back({i,per[i]});
          int start=i;
          int curVal=per[i];
          while(curVal!=start)
          {
            curSet.push_back({curVal,per[curVal]});
            curVal=per[curVal];
          }
          sort(curSet.begin(), curSet.end());
          int minOpVal=2000;
          int in=-1;
          int maxVal=-1;
          for(int it=0;it<curSet.size();it++)
          {
            if(per[it]>maxVal)
            {
              maxVal=per[it];
              in=it;
            }
          }
          minOpVal=v[curSet[in].first]+v[curSet[in].second];

          swap(v[ curSet[in].first ],v[ curSet[in].second ]);
          swap(per[ curSet[in].first ],per[ curSet[in].second ]);
          ans+=minOpVal;
          // for(int it=0;it<per.size();it++)
          //   cout<<per[it]<<" ";
          // cout<<endl;
          curSet.clear();
          i=n;
          break;
        }
      }
      
    }

    cout<<"Case #"<<t<<": "<<ans<<endl;
    cin>>n;
    
  } 
}