// WA
#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("treasures.in","r",stdin);
	#endif
	int T;
	cin>>T;	
	long long int cur_grid[101][101]={};

	long long int next_grid[101][101]={};
	int grid_val [101][101] = {};
	for (int t=1;t<=T;t++)
	{
		int R,C,S,pi,pj;
		cin>>R>>C>>S>>pi>>pj;
		for (int r=1;r<=R;r++)
		{
			for(int c=1;c<=C;c++)
			{
				next_grid[r][c] = 0;
				cur_grid[r][r] = 0;
				cin>>grid_val[r][c];
			}
		}
		cur_grid[pi][pj] = 1;
		for (int s=S;s>1;s--)
		{
			for (int r=1;r<=R;r++)
			{
				for(int c=1;c<=C;c++)
				{
					if (cur_grid[r][c])
					{
						// propagte it
						for (int rn = max(1,r-s+1);rn<= min(R,r+s-1);rn++)
						{
							int dr = abs(rn-r);
							int rem_steps = s- dr;
							for (int cn = max(1,c-rem_steps+1);cn<=min(C, c+rem_steps-1);cn++)
							{
								next_grid[rn][cn] += cur_grid[r][c];
							}
						}
					}
				}
			}

			for (int r=1;r<=R;r++)
			{
				for(int c=1;c<=C;c++)
				{
					cur_grid[r][c] = next_grid[r][c] % MOD;
					next_grid[r][c] = 0; 
				}
			}
		}

		long long int ans = 0;
		for(int r=1;r<=R;r++)
		{
			for(int c=1;c<=C;c++)
			{
				ans = (ans + (cur_grid[r][c] * grid_val[r][c]))%MOD;
			}
		}
		cout<<"Case "<<t<<": "<<ans<<endl;

	}
}