//AC
#include "bits/stdc++.h"
#define EPS 0.0000000001
const long double PI = 4*atan(1);
using namespace std;
std::vector<long double> angles;
int solve(long double ang1, long double ang2)
{
	int ans =0;
	for(int i=0;i<angles.size();i++)
	{
		if(abs(angles[i]-ang1)<EPS || abs(angles[i]-ang2)<EPS)
		{
			ans++;
		}
		else if(angles[i]>=ang1 && angles[i]<=ang2)
		{
			ans++;
		}
	}
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int cx,cy;
	long double r;
	cin>>cx>>cy>>r;
	while(r>0)
	{
		int n;
		cin>>n;
		angles = std::vector<long double> ();
		int x,y;
		for(int i=0;i<n;i++)
		{
			cin>>x>>y;
			int dx = x-cx;
			int dy = y-cy;
			int dis = (dx*dx) + (dy*dy);
			if(dis<=r*r || abs(dis-(r*r))<=EPS)
			{
				long double ang = atan2(dy,dx);
				if (ang<0)
				{
					ang += 2*PI;
				}
				// cout<<ang<<endl;
				angles.push_back(ang);
				angles.push_back(ang+2*PI);
			}
		}
		int ans =0;
		for(int i=0;i<angles.size();i++)
		{
			ans = max(ans,solve(angles[i],angles[i]+PI));
			ans = max(ans,solve(angles[i]+PI,angles[i]+2*PI));
		}
		printf("%d\n", ans);
		cin>>cx>>cy>>r;
	}	
}