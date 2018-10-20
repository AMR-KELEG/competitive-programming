/* AC
- Simple dfs is enough to solve the problem.
- Don't clear the visited array for each case to avoid TLE.
/*

#include <bits/stdc++.h>
using namespace std;
std::vector<std::vector<int> > adjlist;
std::vector<std::vector<int> > adjlist_rev;
std::vector<int> w;
std::vector<long long int> vis(501, 0);
long long int cur_test = 1;

int dfs(int node, const std::vector<std::vector<int> > & adjList)
{
	if (vis[node] == cur_test)
	{
		return 0;
	}

	vis[node] = cur_test;
	int ans =w[node];
	for (int i=0;i<adjList[node].size(); i++)
	{
		int child = adjList[node][i];
		ans += dfs(child, adjList);
	}
	return ans;
}

int main()
{
	int u,v;
	cin>>u>>v;
	int t=1;
	while(!(u==0 && v==0)){
		adjlist = std::vector<std::vector<int> > (u+1, std::vector<int> ());
		adjlist_rev = std::vector<std::vector<int> > (u+1, std::vector<int> ());
		w = std::vector<int> (u+1, 0);
		int sum_w = 0;
		for (int i=1;i<=u;i++)
		{
			cin>>w[i];
			sum_w += w[i];
		}

		while(v--)
		{
			int a,b;
			cin>>a>>b;
			adjlist[a].push_back(b);
			adjlist_rev[b].push_back(a);
		}
		int q;
		cin>>q;
		printf("Case #%d:\n", t);
		while(q--)
		{
			int node;
			cin>>node;
			int earliest = dfs(node, adjlist) - w[node];
			cur_test += 1;
			// cout<< dfs(node, adjlist_rev)<< endl;
			int last = sum_w - dfs(node, adjlist_rev);
			int ans = last  - earliest;
			printf("%d\n", ans);
			// cout<<earliest<< " "<< last<<endl;
			cur_test += 1;
		}
		printf("\n");
		cin>>u>>v;
		t++;
	}
	return 0;
}
