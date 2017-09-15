//AC
#include "bits/stdc++.h"
#define EPS 0.000000000001
using namespace std;

bool eq(long double a,long double b)
{
	return abs(a-b)<=EPS;
}

bool in_range(long double v,int mi,int ma)
{
	if((v>mi || eq(v,mi)) && (v<ma || eq(v,ma)))
		return 1;
	return 0;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int R,D;
	cin>>R>>D;
	int n;
	cin>>n;
	int ans =0;
	while(n--)
	{
		int x,y,r;
		cin>>x>>y>>r;
		long double dis = sqrt((x*x)+(y*y));
		long double min_dis = dis-r;
		long double max_dis = dis+r;
		if (in_range(min_dis,R-D,R) && in_range(max_dis,R-D,R))
			ans++;
	}
	cout<<ans;
}