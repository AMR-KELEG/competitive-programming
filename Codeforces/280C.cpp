/* AC
- Linearity of Expectation
- Create a variable related to a certain event
*/ 
#include "bits/stdc++.h"
using namespace std;
std::vector<std::vector<int> > adjlist;

long double solve(int node = 1,int p=-1, int an = 0)
{
	long double ans = 1.0/(1+an);
	for (auto ch:adjlist[node])
	{
		if (ch == p)
			continue;
		ans += solve(ch, node, an+1);
	}
	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	scanf("%d", &n);
	adjlist = std::vector<std::vector<int> > (n+1);
	for (int i=0, u, v; i<n-1; i++)
	{
		scanf("%d %d", &u, &v);
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	printf("%0.9LF\n", solve());
}