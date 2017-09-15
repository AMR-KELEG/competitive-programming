#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> edge;
vector<edge>adjacency_list [1000];//edge >> weight >> destination
unsigned long long dij(int s,int d)
{
	vector<int> dis(1000,1<<29);
	priority_queue<edge,vector<edge>,greater<edge> >pq;
	pq.push(edge(0,s));
	edge current_node;
	int wei,cn;
	while(!pq.empty())
	{
		current_node=pq.top();
		pq.pop();
		wei=current_node.first;
		cn=current_node.second;
		if(dis[cn]<=wei)continue;
		dis[cn]=wei;
		for(int i=0;i<adjacency_list[cn].size();i++)
		{
			if(adjacency_list[cn][i].first+wei<dis[adjacency_list[cn][i].second])
				pq.push(edge(adjacency_list[cn][i].first+wei,adjacency_list[cn][i].second));
		}
	}
	return dis[d];

}
int main()
{
	freopen("in.txt","r",stdin);
/*
	freopen("out.txt","w",stdout);
	cout<<"10 0 150"<<endl;
	for(int i=0;i<10;i++)
	{
		cout<<"150 ";
		for(int j=0;j<150;j++)
			cout<<j<<" ";
		cout<<endl;
	}
	cout<<"0 0 0";
	return 0;
	*/	
	int  n,s,d;
	int m,first_floor,second_floor,a,b;
	while(cin>>n>>s>>d)
	{
		for(int i=0;i<160;i++)
		{
			adjacency_list[i].clear();
		}
		if(n==0 && s==0 && d==0)break;
		for(int ele=0;ele<n;ele++)
		{
			cin>>m;
			if(m<2)continue;
			cin>>a>>b;
			adjacency_list[a].push_back(edge(abs(a-b),b));
			adjacency_list[b].push_back(edge(abs(a-b),a));	
			a=b;
			m-=2;
			while(m--)
			{
				cin>>b;
				adjacency_list[a].push_back(edge(abs(a-b),b));
				adjacency_list[b].push_back(edge(abs(a-b),a));	
				a=b;
			}
		}
		cout<<dij(s,d)<<endl;
	}

	return 0;
}