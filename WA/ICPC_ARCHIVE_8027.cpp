// AC on A2OJ
#include "bits/stdc++.h"
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n,q;
		scanf("%d %d",&n,&q);
		std::vector<pair<int,int> > ran(n);
		for (int i=0,l,r;i<n;i++)
		{
			scanf("%d %d",&l,&r);
			if (l>r)
				swap(l,r);
			ran[i] = pair<int,int>(l,r);
		}
		sort(ran.begin(), ran.end());
		while(q--)
		{
			int val;
			scanf("%d",&val);
			bool both_l = 0, both_r = 0;
			for (int i=0;i<n;i++)
			{
				if (ran[i].first>=val && ran[i].second>=val)
				{
					both_r = 1;
				}
				if (ran[i].first<=val && ran[i].second<=val)
				{
					both_l = 1;
				}
			}
			if (both_l && both_r)
				printf("YES\n");
			else
				printf("NOT SURE\n");
		}
	}	
}