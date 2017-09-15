//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<int> tree,v;
int n,m;
void build_tree(bool isor=1,int node=1,int left=0,int right=ceil(pow(2,n))-1)
{
  if(left==right)
  {
    tree[node]=v[left];
    return ;
  }
  int mid=(left+right)/2;
  build_tree(!isor,2*node,left,mid);
  build_tree(!isor,1+(2*node),mid+1,right);
  if(isor)
    tree[node]=tree[2*node] | tree[1+(2*node)];
  else
    tree[node]=tree[2*node]^ tree[1+(2*node)]; 

 
}


int in,newval;
void update_tree(bool isor=1,int node=1,int left=0,int right=ceil(pow(2,n))-1)
{
  if(left==right && in==left)
  {
    tree[node]=newval;

    // cout<<left<<" "<<in<<endl;
    return ;
  }
  if(in<left || in>right)
  {
    return ;
  }
  int mid=(left+right)/2;
  update_tree(!isor,2*node,left,mid);
  update_tree(!isor,(2*node)+1,mid+1,right);
  if(isor)
    tree[node]=tree[2*node] | tree[1+(2*node)];
  else
    tree[node]=tree[2*node] ^ tree[1+(2*node)]; 
  // cout<<"L "<<left<<" R "<<right<<" "<<tree[node]<<endl;

}
int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  cin>>n>>m;
  v=std::vector<int> (ceil(pow(2,n)));
  tree=std::vector<int> (4*ceil(pow(2,n)),0);  
  for(int i=0;i<ceil(pow(2,n)) ;i++)
    cin>>v[i];
  // cout<<v[3];
  build_tree(n%2); 
  // cout<<tree[1]<<endl;
  while(m--)
  {
    cin>>in>>newval;
    in--;
    // cout<<"Q "<<in<<endl;
    update_tree(n%2);
    printf("%d\n", tree[1]);
  }
}