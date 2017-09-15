//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		int p,n;
		cin>>p>>n;
		std::vector<int> pay(n,0);
		std::vector<int> cap(n);
		int no = n;
		int sum =0;
		for(int i=0;i<n;i++)
		{
			cin>>cap[i];
			sum+=cap[i];
		}

		if(sum<p)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}

		while(p>0)
		{
			int fair = p/no;
			if(fair ==0)
			{
				// last iteration
				// sort by maximum capacity
				priority_queue<pair<int,int>>q;
				for(int i=0;i<n;i++)
				{
					if(cap[i]==0)
						continue;
					q.push({cap[i],-i});
				}
				while(p>0)
				{
					p--;
					int id = -q.top().second;
					q.pop();
					pay[id]++;
					cap[id]--;
				}
				break;
			}
			else
			{
				for(int i=0;i<n;i++)
				{
					if(cap[i]==0)
						continue;
					pay[i] += min(cap[i],fair);
					p -= min(cap[i],fair);
					if(cap[i]<=fair)
					{
						cap[i]=0;
						no--;
					}
					else
						cap[i]-=fair;
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			printf("%d", pay[i]);
			if(i!=n-1)
				printf(" ");
		}
		printf("\n");	
	}	
}