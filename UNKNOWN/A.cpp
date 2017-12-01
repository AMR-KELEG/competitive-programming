#include <bits/stdc++.h>
using namespace std;
int R,C;
int ans=0;
#define INF 1000000007
vector<vector<char> >grid;
vector<vector<bool> >vis;
void solve(int r,int c)
{
	if(vis[r][c])
		return ;
	vis[r][c]=1;
	if(grid[r][c]=='.')
	{
		return ;	
	}
	else
	{
		//Check if your direction is ok first
		if(grid[r][c]=='<')
		{
			for(int col=c-1;col>=0;col--)
			{
				if(grid[r][col]!='.')
				{
					solve(r,col);
					return ;
				}
			}
		}		
		else if(grid[r][c]=='>')
		{
			for(int col=c+1;col<C;col++)
			{
				if(grid[r][col]!='.')
				{
					solve(r,col);
					return ;
				}
			}
		}
		else if(grid[r][c]=='^')
		{
			for(int row=r-1;row>=0;row--)
			{
				if(grid[row][c]!='.')
				{
					solve(row,c);
					return ;
				}
			}
		}
		else if(grid[r][c]=='v')
		{
			for(int row=r+1;row<R;row++)
			{
				if(grid[row][c]!='.')
				{
					solve(row,c);
					return ;
				}
			}
		}
		
		ans++;
		
			for(int col=c-1;col>=0;col--)
			{
				if(grid[r][col]!='.')
				{
					grid[r][c]='<';
					solve(r,col);
					return ;
				}
			}
		
			for(int col=c+1;col<C;col++)
			{
				if(grid[r][col]!='.')
				{
					grid[r][c]='>';
					solve(r,col);
					return ;
				}
			}
		
			for(int row=r-1;row>=0;row--)
			{
				if(grid[row][c]!='.')
				{
					grid[r][c]='^';
					solve(row,c);
					return ;
				}
			}
		
			for(int row=r+1;row<R;row++)
			{
				if(grid[row][c]!='.')
				{
					grid[r][c]='v';
					solve(row,c);
					return ;
				}
			}
		
		ans=INF;
				
		
	}
}
int main()
{
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		ans=0;
		cin>>R>>C;
		grid=vector<vector<char> >(R,vector<char>(C,'0'));
		vis=vector<vector<bool> >(R,vector<bool>(C,0));
		
		for(int r=0;r<R;r++)
		{
			for(int c=0;c<C;c++)
			{
				cin>>grid[r][c];
			}
		}
		
		for(int r=0;r<R;r++)
		{
			for(int c=0;c<C;c++)
			{
				if(!vis[r][c])
					solve(r,c);
				if(ans==INF)
				{
					r=R;
					break;
				}
			}
		}
		if(ans!=INF)		
			cout<<"Case #"<<t<<": "<<ans<<endl;
		else
			cout<<"Case #"<<t<<": IMPOSSIBLE\n";
	}
}
