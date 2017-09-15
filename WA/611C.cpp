#include "bits/stdc++.h"
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int n,m;
  cin>>n>>m;
  std::vector<std::vector<char> > grid(n+2,std::vector<char>(m+2,'%'));
  
  for(int r=1;r<=n;r++)
  {
    for(int c=1;c<=m;c++)
    {
      cin>>grid[r][c];
    }
  } 

  int cs1[505][505]={};// from 1 1 to n m
  int cs2[505][505]={};
  for(int r=1;r<=n;r++)
  {
    for(int c=1;c<=m;c++)
    {
      //horizontal
      cs1[r][c]+=cs1[r][c-1]+(grid[r][c]==grid[r][c-1] && grid[r][c]=='.');
    }
  }

  for(int r=1;r<=n;r++)
  {
    for(int c=1;c<=m;c++)
    {
      //horizontal
      cs1[r][c]+=cs1[r-1][c];
    }
  }

  for(int r=1;r<=n;r++)
  {
    for(int c=1;c<=m;c++)
    {
      //vertical
      cs2[r][c]+=cs2[r-1][c]+(grid[r][c]==grid[r-1][c] && grid[r][c]=='.');
    }
  }

  for(int r=1;r<=n;r++)
  {
    for(int c=1;c<=m;c++)
    {
      //vertical
      cs2[r][c]+=cs2[r][c-1];
    }
  }

  int q;
  int r1,c1,r2,c2;
  cin>>q;
  while(q--)
  {
    cin>>r1>>c1>>r2>>c2;
    cout<<cs1[r2][c2]+cs1[r1-1][c1-1]-cs1[r1-1][c2]-cs1[r2][c1-1]+
      cs2[r2][c2]+cs2[r1-1][c1-1]-cs2[r1-1][c2]-cs2[r2][c1-1]<<endl;
  }
}