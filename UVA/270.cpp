// AC
// 8:19 -> DONE
#include "bits/stdc++.h"
using namespace std;
int sum_i_squ[701];
int main()
{
	// std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	for (int i=0;i<=700;i++)
	{
		sum_i_squ[i] = (i*(i-1))/2;
		// if (i<10)
		// 	cout<<sum_i_squ[i]<<endl;
	}
	int T;
	cin>>T;
	string s;
	getline(cin,s);
	getline(cin,s);
	for (int t=0;t<T;t++)
	{
		if (t)
			printf("\n");
		std::vector<pair<int,int>  > pts;
		while(getline(cin,s) && s.size()>0)
		{
			int x = atoi( s.substr(0,s.find(' ')).c_str());
			int y = atoi( s.substr(s.find(' ')).c_str());
			pts.push_back({x,y});
		}
		map<pair<pair<int,int>,long long int>,int>mp;
		for (int i=0;i<pts.size();i++)
		{
			for (int j=i+1;j<pts.size();j++)
			{
				long long int dx = pts[i].first-pts[j].first;
				long long int dy = pts[i].second-pts[j].second;
				int GCD = __gcd(dx,dy);
				dx /= GCD;
				dy /= GCD;
				if (dx *dy <0)
				{
					dx = abs(dx);
					dy = -abs(dy);
				}
				long long int c = pts[i].second * dx - pts[i].first * dy;
				mp[{{dx,dy},c}]++;
			}
		}
		int ans = 0;
		for (auto p:mp)
			ans = max(ans, p.second);
		// cout<<ans<<" ";
		ans = lower_bound(sum_i_squ,sum_i_squ+701,ans) - sum_i_squ;
		printf("%d\n", ans);
	}	
}