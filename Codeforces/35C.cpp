/* AC
   BFS from multiple src points
*/
#include "bits/stdc++.h"
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	#ifdef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int N, M;
	scanf("%d %d",&N, &M);	
	queue<pair<int,int> >q;
	std::vector<std::vector<bool> > vis(1+N, std::vector<bool> (1+M,0));
	int k;
	scanf("%d", &k);
	while(k--)
	{
		int r,c;
		scanf("%d %d", &r, &c);
		vis[r][c] = 1;	
		q.push({r,c});
	}

	int r,c;
	int dr[]={0,0,-1,1};
	int dc[]={-1,1,0,0};
	while(!q.empty())
	{
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int i=0;i<4;i++)
		{
			int rn = r+dr[i];
			int cn = c+dc[i];
			if (rn<1 || cn<1 || rn>N || cn>M)
				continue;
			if (vis[rn][cn])
				continue;
			vis[rn][cn] = 1;
			q.push({rn, cn});
		}
	}
	printf("%d %d", r, c);

}