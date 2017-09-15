// AC
#include "bits/stdc++.h"
using namespace std;
int n;
std::vector<std::vector<int> > grid;
//each Row has a tree
std::vector<std::vector<pair<int,int> > > tree;//min - max
void build_tree(int treeRow,int l,int r,int node)
{
  if(l==r)
  {
    tree[treeRow][node].first=tree[treeRow][node].second=grid[treeRow][l];
    return;
  }

  int mid=(l+r)>>1;
  build_tree(treeRow,l,mid,node*2);
  build_tree(treeRow,mid+1,r,1+(node*2));
  tree[treeRow][node].first=min(tree[treeRow][(2*node)].first,tree[treeRow][(2*node)+1].first);
  tree[treeRow][node].second=max(tree[treeRow][(2*node)].second,tree[treeRow][(2*node)+1].second);
}

pair<int,int> query(int treeRow,int rl,int rr,int l,int r,int node)
{
  if(r<rl || l>rr)
  {
    return {INT_MAX,0};
  }
  if(l>=rl && r<=rr)
  {
    return tree[treeRow][node];
  }
  int mid=(l+r)>>1;
  pair<int,int>lans,rans;
  lans=query(treeRow,rl,rr,l,mid,2*node);
  rans=query(treeRow,rl,rr,1+mid,r,(2*node)+1);
  lans.first=min(lans.first,rans.first);
  lans.second=max(lans.second,rans.second);
  return lans;
}

void update(int treeRow,int l,int r,int in,int v,int node)
{
  if(l>in || r<in)
    return ;
  if(l==r && r==in)
  {
    tree[treeRow][node].first=tree[treeRow][node].second=v;
    return;
  }

  int mid=(l+r)>>1;
  update(treeRow,l,mid,in,v,2*node);
  update(treeRow,1+mid,r,in,v,(2*node)+1);
  tree[treeRow][node].first=min(tree[treeRow][2*node].first,tree[treeRow][1+(2*node)].first);
  tree[treeRow][node].second=max(tree[treeRow][2*node].second,tree[treeRow][1+(2*node)].second);
}
int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  cin>>n;
  grid=std::vector<std::vector<int> >(n,std::vector<int> (n));
  tree=std::vector<std::vector<pair<int,int> > >(n,std::vector<pair<int,int> > (4*n));
  for(int r=0;r<n;r++)
  {
    for(int c=0;c<n;c++)
      cin>>grid[r][c];
    build_tree(r,0,n-1,1);
  }
  int q;
  cin>>q;
  char com;
  int x,y,v;
  int x1,y1,x2,y2;
  while(q--)
  {
    cin>>com;
    if(com=='q')
    {
      cin>>x1>>y1>>x2>>y2;
      // rows from x1 -> x2
      // cols from y1 -> y2
      x1--;
      y1--;
      x2--;
      y2--; 
      pair<int,int> p,curp;
      p=query(x1,y1,y2,0,n-1,1);
      for(int r=x1+1;r<=x2;r++)
      {
        curp=query(r,y1,y2,0,n-1,1);
        p.first=min(p.first,curp.first);
        p.second=max(p.second,curp.second);
      }
      printf("%d %d\n", p.second,p.first);
    }
    else
    {
      cin>>x>>y>>v;
      x--;
      y--;
      update(x,0,n-1,y,v,1);
    }
  }
}