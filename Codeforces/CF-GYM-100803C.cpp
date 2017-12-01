/* AC
   
*/
#include "bits/stdc++.h"
using namespace std;
#define LEFT first
#define RIGHT second
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int N,R;
	scanf("%d %d", &N, &R);
	if (R==0)
	{
		printf("%d\n", N+1);
		return 0;
	}
	std::vector<pair<int,int> > REST(R);
	for (int i=0,l,r;i<R;i++)
	{
		scanf("%d %d", &l, &r);
		REST[i] = {l,r};
	}
	sort(REST.begin(), REST.end());
	int ans =0;
	// MERGE
	int l=REST[0].first,r=REST[0].second;
	int entrance = 0;
	for (int i=1;i<R;i++)
	{	
		if (REST[i].LEFT >= l && REST[i].LEFT <=r)
		{
			r = max(r, REST[i].RIGHT);
		}
		else
		{
			// add ans
			ans += (l - entrance) + 3*(r-l);
			entrance = r;
			l = REST[i].LEFT;
			r = REST[i].RIGHT;
		}
	}
	// ADD REM
	ans += (l - entrance) + 3*(r-l);
	ans += (N+1 - r);
	printf("%d\n", ans);
}