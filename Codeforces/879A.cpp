// AC
#include "bits/stdc++.h"
using namespace std;
#define EPS 1e-9
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	int s[1000];
	int d[1000];
	for (int i=0;i<n;i++)
	{
		cin>>s[i]>>d[i];
	}
	int cur_time = 0;
	for (int i=0;i<n;i++)
	{
		if (cur_time<s[i])
			cur_time = s[i];
		else if(cur_time==s[i])
		{
			cur_time = s[i]+d[i];
		}
		else if((cur_time - s[i]) % d[i] == 0)
		{
			int c = (cur_time-s[i])/d[i];
			cur_time = s[i] + (c+1) * d[i];
		}
		else
		{
			long double c = (cur_time-s[i]);
			c /= d[i];
			if (abs(round(c)-c)<EPS)
				c = round(c);
			else
				c = ceil(c);

			while(s[i] + c*d[i] <= cur_time)
				c++;
			cur_time = s[i] + ((int)c)*d[i];
		}
	}
	cout<<cur_time;
}