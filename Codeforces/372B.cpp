//AC
#include "bits/stdc++.h"
using namespace std;
int cs[40][40];
int dp[40][40][40][40];
std::vector<std::vector<char> > grid;
int n,m,q;
void prepare()
{
	memset(dp,-1,sizeof dp);
	cs[0][0] = (grid[0][0]=='0');
	for(int c=1;c<m;c++)
	{
		cs[0][c] = cs[0][c-1]+int(grid[0][c]=='0');
	}
	for(int r=1;r<n;r++)
	{
		cs[r][0]=cs[r-1][0] +int(grid[r][0]=='0');
		for(int c=1;c<m;c++)
		{
			cs[r][c]=cs[r-1][c] + cs[r][c-1] +int(grid[r][c]=='0') - cs[r-1][c-1];
		}
	}
}

int get_zeros(int r1,int c1,int r2,int c2)
{
	int ans = cs[r2][c2];
	if(r1>0)
	{
		ans -= cs[r1-1][c2];
	}
	if(c1>0)
	{
		ans -= cs[r2][c1-1];	
	}
	if(r1>0 && c1>0)
	{
		ans += cs[r1-1][c1-1];	
	}
	return ans;
}

int solve(int r1,int c1,int r2,int c2)
{
	if(r1>r2 || c1>c2)
		return 0;
	if(r1<0 || c1<0 || r2>=n || c2>=m)
		return 0;
	if(dp[r1][c1][r2][c2]!=-1)
		return dp[r1][c1][r2][c2];
	int ans = 0;
	if((r2+1-r1)*(c2+1-c1) == get_zeros(r1,c1,r2,c2))
	{
		ans = 1;
	}
	int a[]={r1+1, r1, r1, r1};
	int b[]={c1, c1, c1, c1+1};
	int c[]={r2, r2, r2-1, r2};
	int d[]={c2, c2-1, c2, c2};
	for(int m=1; m< (1<<4);m++)
	{
		int ca=r1, cb=c1 ,cc=r2, cd=c2;
		for(int i=0;i<4;i++)
		{
			if((m>>i) & 1)
			{
				// take 3-i
				ca = max(ca,a[3-i]);
				cb = max(cb,b[3-i]);
				cc = min(cc,c[3-i]);
				cd = min(cd,d[3-i]);
			}
		}
		if (__builtin_popcount(m) %2)
		{
			ans += solve(ca,cb,cc,cd);
		}
		else
		{
			ans -= solve(ca,cb,cc,cd);	
		}
	}
	return dp[r1][c1][r2][c2]= ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n>>m>>q;
	grid = std::vector<std::vector<char> > (n,std::vector<char> (m));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>grid[i][j];
		}
	}	
	prepare();
	while(q--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		a--;
		b--;
		c--;
		d--;
		printf("%d\n",solve(a,b,c,d));
	}
}