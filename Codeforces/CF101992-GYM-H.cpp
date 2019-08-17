/* Solved by Div 3
Accepted!
*/

#include<bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> g;
vector<bool> v;
int mx;

void bfs(int s, int rem)
{
	queue<pair<int,int> >q;
	q.push({s, rem});
	v[s] = true;
	while(!q.empty()){
		int node = q.front().first;
		int r = q.front().second;
		q.pop();
		if (r==0)
			continue;

		for (auto nbor : g[node])
		{
			mx = max(mx, nbor.second);
			if (v[nbor.first])
				continue;
			v[nbor.first] = true;
			q.push({nbor.first, r - 1});
		}
	} 

}

int main()
{
	freopen("path.in", "r", stdin);
	int T;
	cin>>T;
	while(T--)
	{
		mx = 0;
		int n, m, u, l, k;
		cin >> n >> m >> u >> l >> k;

		g = vector<vector<pair<int, int>>>(n);
		v = vector<bool>(n, false);

		for (int i = 0; i < m; i++)
		{
			int a, b, w;
			cin >> a >> b >>w;
			a--, b--;
			g[a].push_back({b, w});
			g[b].push_back({a, w});
		}

		bfs(u-1, k);
		cout << mx << '\n';
	}
}
