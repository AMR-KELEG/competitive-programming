//AC
#include <bits/stdc++.h>
using namespace std;

#define edge pair<int,pair<int,int> >
#define ecost first
#define esrc second.second
#define edes second.first

int n,m,k,w;
vector<vector<char> >images;
vector<vector<int> >diff;

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m>>k>>w;
	images=vector<vector<char> >(k,vector<char>(n*m));
	diff=vector<vector<int> > (k,vector<int>(k,0));
	for(int i=0;i<k;i++)
	{
		for(int r=0;r<n*m;r++)
		{
			cin>>images[i][r];
		}
	}

	for(int i=0;i<k;i++)
	{
		for(int j=i+1;j<k;j++)
		{
			int d=0;
			for(int el=0;el<n*m;el++)
			{
				if(images[i][el]!=images[j][el])
					d++;
			}
			diff[i][j]=diff[j][i]=d*w;
		}
	}
	priority_queue<edge> q;
	int ans=0;
	vector<bool>vis(k,0);
	vector<int>prev(k,-1);
	vector<int>order;
	q.push({-n*m,{0,0}});
	while(!q.empty())
	{
		int cost=-q.top().ecost;
		int src=q.top().esrc;
		int des=q.top().edes;
		q.pop();
		if(vis[des])continue;
		order.push_back(des);
		vis[des]=1;
		if(cost>=n*m)
		{
			ans+=n*m;
			prev[des]=0;
		}
		else
		{
			ans+=cost;
			prev[des]=src+1;
		}
		for(int i=0;i<k;i++)
		{
			if(!vis[i])
			{
				q.push({-diff[i][des],{i,des}});
			}
		}
	}
	cout<<ans<<endl;
	for(int i=0;i<k;i++)
	{
		cout<<order[i]+1<<" "<<prev[order[i]]<<endl;
	}
}
