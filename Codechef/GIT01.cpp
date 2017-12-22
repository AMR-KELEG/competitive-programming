// AC
#include "bits/stdc++.h"
using namespace std;

int cmp(const string & g, const string & p)
{
	int ans = 0;
	for (int i=0;i<g.size();i++)
	{
		if (g[i]==p[i])
			continue;
		if (g[i]=='R')
			ans+=5;
		else
			ans+=3;
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
		int R,C;
		scanf("%d %d",&R, &C);
		std::vector<string> grid(R);
		for (int r=0;r<R;r++)
		{
			cin>>grid[r];
		}
		string s1(C,'R');
		string s2(C,'G');
		for (int i=1;i<C;i+=2)
		{
			s1[i] = 'G';
			s2[i] = 'R';
		}
		int ans1= 0, ans2=0;
		bool first = 1;
		for (int i=0;i<R;i++)
		{
			if (first)
			{
				ans1+= cmp(grid[i], s1);
				ans2+= cmp(grid[i], s2);
			}
			else
			{
				ans2+= cmp(grid[i], s1);
				ans1+= cmp(grid[i], s2);
			}
			first = !first;
		}

		printf("%d\n", min(ans1, ans2));
	}

}