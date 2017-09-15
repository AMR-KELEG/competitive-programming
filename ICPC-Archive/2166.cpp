//AC
#include "bits/stdc++.h"
using namespace std;

int vis[151][151][151];
#define state pair<pair<int,int>,pair<int,int>>
#define F first.first
#define S first.second
#define T second.first
#define M second.second

void get_next(int & cur1,int & cur2,const int & cap1,const int & cap2)
{
	if (cur1+cur2<=cap2)
	{
		cur2 +=cur1;
		cur1 = 0;
	}
	else
	{
		cur1 -= (cap2-cur2);
		cur2 = cap2;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int cap[3];
	int in[3];
	int des[3];	
	int Te=1;
	cin>>cap[0];
	while(cap[0])
	{
		for (int i=1;i<3;i++)	cin>>cap[i];
		for (int i=0;i<3;i++)	cin>>in[i];
		for (int i=0;i<3;i++)	cin>>des[i];

		int total_wat = in[0]+in[1]+in[2];
		int total_des = des[0]+des[1]+des[2];
		if (total_wat !=total_des)
		{
			cout<<-1<<endl;
		}
		else
		{
			bool imp = 0;
			for (int i=0;i<3;i++)
			{
				if (des[i]>cap[i])
				{
					imp = 1;
					break;
				}
			}
			if (imp)
				cout<<-1<<endl;
			else
			{
				// solve here
				queue<state> q;
				q.push({{in[0],in[1]},{in[2],0}});
				vis[in[0]][in[1]][in[2]] = Te;
				bool done = 0;
				while (!q.empty())
				{
					state cur_state = q.front();
					q.pop();
					int f = cur_state.F;
					int s = cur_state.S;
					int t = cur_state.T;
					int m = cur_state.M;
					int cur_cap [3] = {f,s,t};
					if (f==des[0] && s==des[1] && t==des[2])
					{
						cout<<m<<endl;
						done = 1;
						break;
					}
					for (int i=0;i<3;i++)
					{
						for(int j=0;j<3;j++)
						{
							if (i==j)
								continue;
							int next_cap[3]= {f,s,t};
							get_next(next_cap[i],next_cap[j],cap[i],cap[j]);
							if (vis[next_cap[0]][next_cap[1]][next_cap[2]] == Te)
							{
								continue;
							}
							vis[next_cap[0]][next_cap[1]][next_cap[2]] = Te;
							q.push({{next_cap[0],next_cap[1]},{next_cap[2],m+1}});
						}
					}
				}
				if (!done)
					cout<<-1<<endl;
			}
		}
		Te++;
		cin>>cap[0];
	}
}