//AC
#include "bits/stdc++.h"
using namespace std;
#define State pair<pair<int,int>,pair<short,short> >
#define Row second.first
#define Col second.second
#define Chan first.first
#define Len first.second
#define INF 0x3f7f
char grid[502][502];
int changes[502][502];
int leng[502][502];
bool vis[502][502];
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	short R,C;
	cin>>R>>C;
	short st_r, st_c;
	short des_r, des_c;
	cin>>st_r>>st_c>>des_r>>des_c;
	memset(leng,INF,sizeof leng);
	memset(changes,INF,sizeof changes);
	for (short r=1;r<=R;r++)
	{
		for (short c=1;c<=C;c++)
		{
			char ch;
			cin>>ch;
			grid[r][c] = ch - '0';
		}
	}
	bool done = 0;
	priority_queue<State>q;
	q.push({{0,-1},{st_r,st_c}});
	leng[st_r][st_c] = 1;
	changes[st_r][st_c]= 0;
	int dr[]={-1,-1,-1,0,0,1,1,1};
	int dc[]={-1,0,1,-1,1,-1,0,1};
	while(!q.empty())
	{
		State cur_st = q.top();
		q.pop();
		short cur_r = cur_st.Row;
		short cur_c = cur_st.Col;
		int cur_chan = -cur_st.Chan;
		int cur_len = -cur_st.Len;
		if(cur_r == des_r && cur_c == des_c)
		{
			done = 1;
			break;
		}
		if (cur_chan > changes[cur_r][cur_c] || 
			(cur_chan == changes[cur_r][cur_c] && cur_len > leng[cur_r][cur_c]))
		{
			continue;
		}
		if (vis[cur_r][cur_c])
			continue;
		vis[cur_r][cur_c] = 1;
		for (short i=0;i<8;i++)
		{
			short r = cur_r+dr[i];
			short c = cur_c+dc[i];
			if (grid[r][c] == 0)
				continue;
			if (cur_chan+(grid[r][c] !=grid[cur_r][cur_c]) > changes[r][c] || 
			(cur_chan+(grid[r][c] !=grid[cur_r][cur_c]) == changes[r][c] && cur_len+1 >= leng[r][c]))
			{
				continue;
			}
			changes[r][c] = cur_chan+(grid[r][c] !=grid[cur_r][cur_c]);
			leng[r][c] = 1+cur_len;
			q.push(
				{
				{-(cur_chan + (grid[r][c] !=grid[cur_r][cur_c]) ), -(1+cur_len)},
					{r,c}
				});
		}
	}
	if (done)
	{
		cout<<leng[des_r][des_c]<<" "<<changes[des_r][des_c];
	}
	else
	{
		cout<<"0 0";
	}

}