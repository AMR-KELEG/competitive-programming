/* AC
- Linearity of expectation
- Variable Related to event
- https://s3.amazonaws.com/codechef_shared/download/editorials/ACMAMR12/FSSYNC.pdf
*/

#include "bits/stdc++.h"
using namespace std;
std::vector<std::vector<int> > adjlist;
std::vector<bool> is_dead;
long double solve(int node=1, int p=-1, int dead_anc = 0)
{
	long double ans = 1- (1.0/(1+dead_anc));
	for (auto ch:adjlist[node])
	{
		if (ch==p)
			continue;
		ans += solve(ch, node, dead_anc + (is_dead[node]));
	}
	return ans;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%d", &n);
		adjlist = std::vector<std::vector<int> > (n+1);
		for (int i=0,u,v;i<n-1;i++)
		{
			scanf("%d %d", &u, &v);
			adjlist[u].push_back(v);
			adjlist[v].push_back(u);
		}
		is_dead = std::vector<bool> (n+1);
		int m;
		scanf("%d", &m);
		for (int i=0,u;i<m;i++)
		{
			scanf("%d", &u);
			is_dead[u] = 1;
		}
		printf("%0.9LF\n", solve());
	}	
}