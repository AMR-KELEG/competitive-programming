#include "bits/stdc++.h"
using namespace std;
#define Point complex<long double>
#define INF 1000000000000LL
#define EPS 1e-12
#define X real()
#define Y imag()
#define cp(v1,v2) (conj(v1) * (v2)).Y
int n;
long double dp[1000][1000];
int vis[1000][1000];
Point pts[1000];
std::vector<Point> convex_hull;
int t =1;
long double find_ans(int st,int en)
{
	if (st == convex_hull.size())
		return 0;
	if (st == convex_hull.size()-1)
		return INF;
	if (vis[st][en] == t)
		return dp[st][en];
	vis[st][en] = t;
	return dp[st][en] = abs(convex_hull[st]-convex_hull[en]) + 
						min( find_ans(en,en+1), find_ans(en+1,en+2));
}

long double solve()
{
	convex_hull.clear();
	for (int i=0;i<n;i++)
	{
		int sz = convex_hull.size();
		if (sz>1 && 
			cp(convex_hull[sz-2]-convex_hull[sz-1],
				pts[i]-convex_hull[sz-1]) < 0)
		{
			convex_hull.pop_back();
			sz--;
		}
		convex_hull.push_back(pts[i]);
	}	
	return find_ans(0,1);
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for (int i=0;i<n;i++)
		{
			long double x,y;
			cin>>x>>y;
			pts[i] = Point(x,y);
		}
		printf("%0.6LF\n", solve() + EPS);
		t++;
	}	
}