//AC
#include "bits/stdc++.h"
using namespace std;
/*
	
	AAAA_QPPPP
	!
*/
#define INF 1000000000
int adj_mat[38][38]={};
int par[38];
int bfs()
{
	// cout<<node<<" "<<f<<endl;
	queue<pair<int,int> > q;
	bool vis[38]={};
	q.push({0, INF});
	par[0] = -1;
	vis[0] = 1;
	int cur_node = 0;
	int cur_flow = 0;
	while(!q.empty())
	{
		cur_node = q.front().first;
		cur_flow = q.front().second;
		q.pop();
		if(cur_node == 37)
			break;
		for(int ch =0;ch<38;ch++)
		{
			if(ch == cur_node || ch == par[cur_node] || vis[ch])
			{
				continue;
			}
			if(adj_mat[cur_node][ch])
			{
				vis[ch] = 1;
				par [ch] = cur_node;
				q.push({ch,min(cur_flow, adj_mat[cur_node][ch])});
			}
		}
	}
	return (cur_node == 37)?cur_flow:0;
}

int max_flow()
{
	int total_f = 0, f ;
	memset(par,-1,sizeof par);
	while ((f=bfs()) !=0)
	{
		// cout<<"Flow is "<<f<<endl;
		total_f +=f;
		// remove the edges
		int cur_node = 37;
		// cout<<par[cur_node]<<endl;
		while(par[cur_node]!=-1)
		{
			// cout<<cur_node<<"	"<<par[cur_node]<<endl;
			adj_mat[par[cur_node]][cur_node] -=f;
			adj_mat[cur_node][par[cur_node]] +=f;
			cur_node = par[cur_node];
		}
		// cout<<endl<<endl;
		memset(par,-1,sizeof par);
	}
	return total_f;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	string s;
	int req = 0;
	while(getline(cin,s))
	{
		if(s.size()==0)
		{
			// solve
			for(int node = 27;node<37;node++)
				adj_mat[node][37] = 1;

			if(max_flow() == req)
			{
				for(int node = 27 ; node<37;node++)
				{
					char out = '_';
					for(int p = 1;p<27;p++)
					{
						if(adj_mat[node][p])
						{
							out = p-1+'A';
							break;
						}
					}
					printf("%c", out);
				}
				printf("\n");
			}
			else
			{
				printf("!\n");
			}
			memset(adj_mat,0,sizeof adj_mat);
			req = 0;
			continue;	
		}

		int app = s[0]-'A' + 1;
		int users = s[1]-'0';
		// cout<<s[0]<<endl;
		req += users;
		adj_mat[0][app] = users;
		for(int i=3;i<s.size()-1;i++)
		{
			int comp = s[i]-'0' + 27;
			adj_mat[app][comp] = 1;
		}
	}

	for(int node = 27;node<37;node++)
		adj_mat[node][37] = 1;

	if(max_flow() == req)
	{
		for(int node = 27 ; node<37;node++)
		{
			char out = '_';
			for(int p = 1;p<27;p++)
			{
				if(adj_mat[node][p])
				{
					out = p-1+'A';
					break;
				}
			}
			printf("%c", out);
		}
		printf("\n");
	}
	else
	{
		printf("!\n");
	}


}