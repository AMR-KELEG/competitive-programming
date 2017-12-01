// AC
// 6:31
#include "bits/stdc++.h"
using namespace std;
#define X first
#define Y second
#define R second
#define CX first.first
#define CY first.second
#define INF 1000000000000000000LL
#define Point pair<int,int>
#define Circle pair<Point,int>
std::vector<std::vector<int> > adjlist;
int L[1001][10]; // node and level
int level[1001];
#define EPS 1e-12
void dfs(int node=0,int lev=0)
{
	level[node] = lev;
	// cout<<node<<" "<<lev<<endl;
	for (auto ch:adjlist[node])
		dfs(ch,lev+1);
}

int LCA(int a,int b)
{
	if (level[a] > level[b])
		swap(a,b);
	for (int lev=9;lev>=0;lev--)
	{
		if (level[a] > level[b] - (1<<lev))
			continue;
		b = L[b][lev];
	}
	if (a==b)
		return a;
	for (int lev = 9;lev>=0;lev--)
	{
		if (L[a][lev] == L[b][lev])
			continue;
		a = L[a][lev];
		b = L[b][lev];
	}
	return L[a][0];
}

int solve(int a,int b)
{
	// a and b are nodes in the tree
	if (a==b)
		return 0;
	int ans = LCA(a,b);
	return - 2*level[ans] + level[a] + level[b];
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m,q;
	cin>>n>>m>>q;
	unordered_map<int,int> mp;
	std::vector<Point> pts(n);
	for (int i=0;i<n;i++)
		cin>>pts[i].X>>pts[i].Y;
	std::vector<Circle> circles(m);
	for (int i=0;i<m;i++)
	{
		cin>>circles[i].R>>circles[i].CX>>circles[i].CY;
	}
	for (int i=0;i<n;i++)
	{
		mp[i+1] = 0;
		Point p =pts[i];
		long double min_r = INF;
		for (int j=0;j<m;j++)
		{
			Circle c = circles[j];
			long double dx = p.X - c.CX;
			long double dy = p.Y - c.CY;
			dx *=dx;
			dy *=dy;
			long double total_dis = sqrt(dx+dy);
			if (total_dis <c.R)
			{
				// in_circle
				if (c.R < min_r)
				{
					min_r = c.R;
					mp[i+1] = j+1;
				}
			}
		}
	}
	memset(L,-1,sizeof L);
	adjlist = std::vector<std::vector<int> > (m+1);
	for (int i=0;i<m;i++)
	{
		Circle c1 = circles[i];
		long double r_in = INF;
		int cur_par = 0;
		for (int j=0;j<m;j++)
		{
			if (i==j)
				continue;
			Circle c2 = circles[j];
			if (c2.R < c1.R)
				continue;
			long double dx = c1.CX - c2.CX;
			long double dy = c1.CY - c2.CY;
			dx *=dx;
			dy *=dy;
			long double total_dis = sqrt(dx+dy);
			if (total_dis <= c2.R - c1.R)
			{
				// ok 
				if (r_in > c2.R)
				{
					r_in = c2.R;
					cur_par = j+1;
				}
			}
		}
		adjlist[cur_par].push_back(i+1);
		L[i+1][0] = cur_par;
	}
	for (int level = 1;level < 10;level++)
	{
		for (int node = 0;node<=m;node++)
		{
			if (L[node][level-1] == -1)
				continue;
			L[node][level] = L[ L[node][level-1] ][level-1];
		}
	}
	dfs();
	while (q--)
	{
		int a,b;
		cin>>a>>b;
		printf("%d\n", solve(mp[a],mp[b]));
	}
}