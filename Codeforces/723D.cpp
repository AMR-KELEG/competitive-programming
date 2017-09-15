//AC
#include "bits/stdc++.h"
using namespace std;
int ReqLakes;
int n,m;
char grid[53][53];
bool vis[53][53];

std::vector<pair<int,pair<int,int>> > Lakes; 

int dfs(int r,int c)
{
	//cout<<r<<" "<<c<<endl;
	if(r<1 || r>n || c<1 || c>m)
		return 0;
	if(grid[r][c]=='*' ||vis[r][c])
		return 0;
	vis[r][c]=1;
	return 1+dfs(r,c+1)+dfs(r,c-1)+dfs(r+1,c)+dfs(r-1,c);
}

void removeLake(int r,int c)
{
	// cout<<r<<" "<<c<<endl;
	if(r<1 || r>n || c<1 || c>m)
		return ;
	if(grid[r][c]=='*' ||vis[r][c])
		return ;
	vis[r][c]=1;
	grid[r][c]='*';
	removeLake(r,c+1);
	removeLake(r,c-1);
	removeLake(r+1,c);
	removeLake(r-1,c);
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n>>m>>ReqLakes;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>grid[i][j];
		}
	}
	//DFS from all borders and make them vis
	for(int c=1;c<=m;c++)
	{
		if(grid[1][c]=='.' && !vis[1][c])
		{
			//cout<<"OC\n";
			dfs(1,c);
			// cout<<dfs(1,c)<<endl;
		}
		if(grid[n][c]=='.' && !vis[n][c])
		{
			//cout<<"OC\n";
			dfs(n,c);
			// cout<<dfs(n,c)<<" "<<n<<" "<<c<<endl;
		}
	}
	for(int r=1;r<=n;r++)
	{
		if(grid[r][1]=='.' && !vis[r][1])
		{
			dfs(r,1);
		}
		if(grid[r][m]=='.' && !vis[r][m])
		{
			dfs(r,m);
		}
	}

	for(int r=1;r<=n;r++)
	{
		for(int c=1;c<=m;c++)
		{
			if(!vis[r][c] && grid[r][c]=='.')
			{
				int s=dfs(r,c);
				Lakes.push_back({s,{r,c}});
				// cout<<"Size "<<s<<" "<<r<<" "<<c<<endl;
				// StartOfLake.push_back({r,c});
				// SizeofLake.push_back(s);
			}
		}
	}
	for(int r=1;r<=n;r++)
	{
		for(int c=1;c<=m;c++)
		{
			vis[r][c]=0;
		}
	}
	// cout<<Lakes.size()<<endl;
	sort(Lakes.begin(),Lakes.end());
	// reverse(Lakes.begin(),Lakes.end());
	
	int in=0;
	int transCells=0;
	while(Lakes.size()-ReqLakes-in>0)
	{
		transCells+=Lakes[in].first;
		removeLake(Lakes[in].second.first,Lakes[in].second.second);
		in++;
		// cout<<endl;
	}

	cout<<transCells<<endl;
	for(int r=1;r<=n;r++)
	{
		for(int c=1;c<=m;c++)
			cout<<grid[r][c];
		cout<<endl;
	}
}