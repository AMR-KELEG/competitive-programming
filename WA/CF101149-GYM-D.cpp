// WA
#include "bits/stdc++.h"
using namespace std;
std::vector<std::vector<int> > row_sum;
std::vector<std::vector<int> > col_sum;

int row_cost(int r,int cs,int ce)
{
	return row_sum[r][ce] - row_sum[r][cs-1];
}

int col_cost(int c,int rs,int re)
{
	return col_sum[re][c] - col_sum[rs-1][c];
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m,R,C;
	scanf("%d %d %d %d", &n, &m, &R, &C);
	std::vector<std::vector<int> > cost(n+1, std::vector<int> (m+1));
	row_sum = std::vector<std::vector<int> > (n+1, std::vector<int> (m+1, 0));
	col_sum = std::vector<std::vector<int> > (n+1, std::vector<int> (m+1, 0));
	for (int r=1;r<=n;r++)
	{
		for (int c=1,v;c<=m;c++)
		{
			scanf("%d",&v);
			cost[r][c] = v;
			row_sum[r][c] = v + row_sum[r][c-1];
			col_sum[r][c] = v + col_sum[r-1][c];
		}
	}
	int total_cost = 1e9;
	int RS = 0;
	int CS = 0;
	int RE = 0;
	int CE = 0;
	for (int rs=1;rs<=n;rs++)
	{
		for (int re = rs+2;re<=n;re++)
		{
			for (int cs = 1;cs<=m;cs++)
			{
				for (int ce=cs+2;ce<=m;ce++)
				{
					if (R>rs && R<re && C>cs && C<ce)
					{
						// try this solution
						int cur_cost = row_cost(rs,cs+1,ce-1) +
									   row_cost(re,cs+1,ce-1) +
									   col_cost(cs,rs+1,re-1) +
									   col_cost(ce,rs+1,re-1);
						if (cur_cost<total_cost)
						{
							total_cost = cur_cost;
							RS = rs;
							RE = re;
							CS = cs;
							CE = ce;
						}
					}
				}
			}
		}
	}
	printf("%d\n", total_cost);
	for (int r=1;r<=n;r++)
	{
		for (int c=1;c<=m;c++)
		{
			if ((r==RS || r==RE) && c>CS && c<CE)
				printf("X");
			else if ((c==CS || c==CE) && r>RS && r<RE)
				printf("X");
			else
				printf(".");
		}
		printf("\n");
	}
}