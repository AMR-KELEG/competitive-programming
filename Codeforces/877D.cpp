// AC
#include "bits/stdc++.h"
using namespace std;
#define INF 1000000
char grid[1002][1002];
int reach_time[1002][1002];
short q_r[1000000]={};
short q_c[1000000]={};
int cur_q=0;
int last_q=0;
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	short n,m,k;
	cin>>n>>m>>k;	
	for (short r=1;r<=n;r++)
	{
		for (short c=1;c<=m;c++)
		{
			cin>>grid[r][c];
			reach_time[r][c] = INF;
		}
	}
	short sr,sc,dr,dc;
	cin>>sr>>sc>>dr>>dc;
	q_r[last_q]=sr;
	q_c[last_q++]=sc;	
	reach_time[sr][sc]=0;
	while(cur_q<last_q)
	{
		short cur_r = q_r[cur_q];
		short cur_c = q_c[cur_q];
		cur_q++;
		if (cur_r == dr && cur_c==dc)
		{
			cout<<reach_time[cur_r][cur_c];
			return 0;
		}
		for (short rn=cur_r-1,d=1;rn>0 && d<=k;d++,rn--)
		{
			if (grid[rn][cur_c]=='#')
				break;
			if (reach_time[rn][cur_c] <= reach_time[cur_r][cur_c])
				break;
			if (reach_time[rn][cur_c] == reach_time[cur_r][cur_c]+1)
				continue;
			reach_time[rn][cur_c] = reach_time[cur_r][cur_c]+1;
			q_r[last_q]=rn;
			q_c[last_q++]=cur_c;
		}
		for (short rn=cur_r+1,d=1;rn<=n && d<=k;d++,rn++)
		{
			if (grid[rn][cur_c]=='#')
				break;
			if (reach_time[rn][cur_c] <= reach_time[cur_r][cur_c])
				break;
			if (reach_time[rn][cur_c] == reach_time[cur_r][cur_c]+1)
				continue;
			reach_time[rn][cur_c] = reach_time[cur_r][cur_c]+1;
			q_r[last_q]=rn;
			q_c[last_q++]=cur_c;
		}
		for (short cn = cur_c-1,d=1;cn>0 && d<=k;d++,cn--)
		{
			if (grid[cur_r][cn]=='#')
				break;
			if (reach_time[cur_r][cn] <= reach_time[cur_r][cur_c])
				break;
			if (reach_time[cur_r][cn] == reach_time[cur_r][cur_c]+1)
				continue;
			reach_time[cur_r][cn] = reach_time[cur_r][cur_c]+1;
			q_r[last_q]=cur_r;
			q_c[last_q++]=cn;
		}
		for (short cn = cur_c+1,d=1;cn<=m && d<=k;d++,cn++)
		{
			if (grid[cur_r][cn]=='#')
				break;
			if (reach_time[cur_r][cn] <= reach_time[cur_r][cur_c])
				break;
			if (reach_time[cur_r][cn] == reach_time[cur_r][cur_c]+1)
				continue;
			reach_time[cur_r][cn] = reach_time[cur_r][cur_c]+1;
			q_r[last_q]=cur_r;
			q_c[last_q++]=cn;
		}
	}
	cout<<-1;
}