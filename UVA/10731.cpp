//AC
#include "bits/stdc++.h"
using namespace std;
vector<vector<int> > adj(26) /*The intial graph*/;
std::vector<int> curSub(5);

vector<vector<int> > SCCs /* The components itself*/;
#define comps SCCs
vector<int> compIndex /* for each node, what is the index of the
component this node inside*/
,ind, lowLink;
stack<int> st;
vector<bool> inst;
int idx = 0; //must be intialized by zero;
void tarjanSCC(int i) {
lowLink[i] = ind[i] = idx++;
st.push(i);
inst[i] = true;
for (int j = 0; j < adj[i].size(); j++) {
int k = adj[i][j];
if (ind[k] == -1) {
tarjanSCC(k);
lowLink[i] = min(lowLink[i], lowLink[k]);
} else if (inst[k]) {
lowLink[i] = min(lowLink[i], lowLink[k]);
}
}
if (lowLink[i] == ind[i]) {
vector<int> comp;
int n = -1;
while (n != i) {
n = st.top();
st.pop();
comp.push_back(n);
inst[n] = 0;
compIndex[n] = comps.size();
}
comps.push_back(comp);
}
}
void SCC() {
comps.clear();
compIndex.resize(adj.size());
ind.clear();
ind.resize(adj.size(), -1);
lowLink.resize(adj.size());
inst.resize(adj.size());
idx = 0; //must be intialized by zero;
for (int i = 0; i < adj.size(); i++)
if (ind[i] == -1)
tarjanSCC(i);
}




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
    adj=std::vector<std::vector<int> > (26);
    int pref;
    bool ref[26]={};
    while(n--)
    {
      char c;
      for(int i=0;i<5;i++)
      {
        cin>>c;
        curSub[i]=c-'A';
        ref[curSub[i]]=1;
      }
      cin>>c;
      pref=c-'A';
      for(int i=0;i<5;i++)
      {
        if(pref!=curSub[i]) adj[pref].push_back(curSub[i]);
      }
    }
    SCC();
    sort(SCCs.begin(), SCCs.end());
    for(int i=0;i<SCCs.size();i++)
    {
      sort(SCCs[i].begin(), SCCs[i].end());
    }
    std::vector<bool> done(SCCs.size(),0);
    for(int trial=0;trial<SCCs.size();trial++)
    {
      int in=-1;
      int ch='Z'+1;
      for(int j=0;j<SCCs.size();j++)
      {
        if(SCCs[j].size()==1 && !ref[SCCs[j][0]])
          continue;
        if(done[j])
          continue;
        if(SCCs[j][0]<ch)
        {
          ch=SCCs[j][0];
          in=j;
        }
      }
      if(in==-1)
        break;
      done[in]=1;
      for(int it=0;it<SCCs[in].size();it++)
      {
        if(it!=0)
          cout<<" ";
        cout<<char('A'+SCCs[in][it]);
      }      
      cout<<endl;
    }
    cin>>n;
    if(n!=0)
      cout<<endl;
  } 
}