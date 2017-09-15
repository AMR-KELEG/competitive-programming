#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int op,rc,a;
	int n,m,k;
	cin>>n>>m>>k;
	std::vector<int> row(n+1,0),col(m+1,0);
	std::vector<int> q(k);
	for(int i=0;i<k;i++)
	{
		cin>>op>>rc;
		cin>>q[i];
		if(op==1)
		{
			row[rc]=i+1;
		}
		else
		{
			col[rc]=i+1;
		}
	}
	for(int r=1;r<=n;r++)
	{
		for(int c=1;c<=m;c++)
		{
			if(row[r]>col[c])
			{
				printf("%d ",q[row[r]-1]);
			}
			else if(row[r]<col[c])
			{
				printf("%d ",q[col[c]-1]);	
			}
			else
			{
				printf("%d ",0);	
			}
		}
		printf("\n");
	}
}