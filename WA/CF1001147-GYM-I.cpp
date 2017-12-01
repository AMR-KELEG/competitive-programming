// WA
#include "bits/stdc++.h"
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	freopen("walk.in","r",stdin);
	int T;
	cin>>T;
	while(T--)
	{
		long long int n,R;
		cin>>n>>R;
		priority_queue<pair<long double, pair<bool,int>> >q; // -x and is_start
		while(n--)
		{
			int x,y,rs;
			cin>>x>>y>>rs;
			long long int val = (R -rs)*(R -rs) - (((long long int) y)*y);
			if (val<0)
				continue;
			long double l = 0, r = 1000000000;
			for (int i=0;i<100;i++)
			{
				long double mid = (l+r)/2;
				if (mid * mid <val)
					l = mid;
				else
					r = mid;
			}
			long double dx = (l+r)/2;
			
			q.push({-(x-dx),{1,rs}});
			q.push({-(x+dx),{0,rs}});
		}
		long long int ans = 0;
		long long int cur_in = 0;
		while(!q.empty())
		{
			bool is_start = q.top().second.first;
			int r = q.top().second.second;
			q.pop();
			if (is_start)
				cur_in+=r;
			else
				cur_in-=r;
			ans = max(ans, cur_in);
		}
		cout<<ans<<"\n";
	}
}