//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	long long int ans=n;
	ans*=(n-1)*(n-2);
	ans/=6;
	std::vector<pair<int,int> > points(n);
	cin>>points[0].first>>points[0].second;
	map<pair<pair<int,int>,long long int>,set<int> >mp;//dy dx c
	for(int i=1;i<n;i++)
	{
		cin>>points[i].first>>points[i].second;
		for(int j=0;j<i;j++)
		{
			int deltax=points[i].first-points[j].first;
			int deltay=points[i].second-points[j].second;
			int GCD=__gcd(deltax,deltay);
			deltax/=GCD;
			deltay/=GCD;
			if(deltax==0)
			{
				//Vertical line 
				//defined by its x
				mp[{{1,0},points[i].first}].insert(i);
				mp[{{1,0},points[i].first}].insert(j);
			}
			else
			{
				// long long int deltaMULx=deltax*points[i].second;
				// deltaMULx
				long long int c=(deltax*points[i].second)-(deltay*points[i].first);
				mp[{{deltay,deltax},c}].insert(i);
				mp[{{deltay,deltax},c}].insert(j);
			}
		}
	}	
	for(auto p:mp)
	{
		// cout<<"P "<<p.second<<endl;
		long long int counter=p.second.size();
		if(counter>=3)
		{
			ans-=(counter*(counter-1)*(counter-2))/6;
		}
	}
	cout<<ans;
}