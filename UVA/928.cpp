// AC
#include "bits/stdc++.h"
using namespace std;
bool valid[306][306];
int vis[306][306][3];
#define state pair<pair<int,int>,pair<int,int>>

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	int t = 1;
	while(T--)	
	{
		int sr,sc,dr,dc;
		int R,C;
		cin>>R>>C;
		for (int r=0;r<3+R+3;r++)
		{
			for (int c=0;c<3+C+3;c++)
			{
				if (r<3 || c<3 || r>3+R-1 || c>3+C-1)
				{
					valid[r][c] = 0;
					// cout<<'#';
				}
				else
				{
					char ch;
					cin>>ch;
					// cout<<c;
					if (ch!='#')
						valid[r][c] =1;
					else
						valid[r][c] =0;
					if (ch=='S')
					{
						sr = r;
						sc = c;
					}
					if (ch=='E')
					{
						dr = r;
						dc = c;
					}
						
				}
			}
			// cout<<endl;
		}
		priority_queue<state>q;
		q.push({{0,2},{sr,sc}});//-moves , last_move
		int next_move [] = {1,2,0};
		int delr[]={-1,1,0,0};
		int delc[]={0,0,-1,1};
		bool done = 0;
		while(!q.empty())
		{
			int cur_r = q.top().second.first;
			int cur_c = q.top().second.second;
			int steps = -q.top().first.first;
			int last_move = q.top().first.second;
			q.pop();
			if (cur_r == dr && cur_c == dc)
			{
				done = 1;
				printf("%d\n", steps);
				break;
			}
			int cur_move = next_move[last_move];
			for (int i=0;i<4;i++)
			{
				// 1) Check validity
				bool ok = 1;
				for (int m=1;m<=cur_move+1;m++)
				{
					if (!valid[cur_r+m*delr[i]][cur_c+m*delc[i]])
					{
						ok = 0;
						break;
					}
				}
				if (!ok)
					continue;
				// 2) Go there
				if (vis[cur_r+delr[i]*(cur_move+1)][cur_c+delc[i]*(cur_move+1)][cur_move] ==t)
				{
					continue;
				}
				vis[cur_r+delr[i]*(cur_move+1)][cur_c+delc[i]*(cur_move+1)][cur_move] =t;
				q.push({{-(steps+1),cur_move},{cur_r+delr[i]*(cur_move+1),cur_c+delc[i]*(cur_move+1)}});
			}
		}
		if (!done)
		{
			printf("NO\n");
		}
		t++;

	}
}