// 12:10 -> 12:23  (CS)
#include "bits/stdc++.h"
using namespace std;
#define Point complex<long double>
#define X real()
#define Y imag()
#define EPS 1e-9
#define dis(a,b) abs(a-b)
#define PI (2*acos(0))
#define INF 1e9

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	// if you take both??
	std::vector<Point> pts(n);
	for (int i=0;i<n;i++)
	{
		long double x,y;
		cin>>x>>y;
		pts[i] = Point(x,y);
	}	
	std::vector<long double> min_r(n,INF);
	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			long double cur_dis = dis(pts[i],pts[j]);
			min_r[i] = min(cur_dis, min_r[i]);
			min_r[j] = min(cur_dis, min_r[j]);
		}
	}
	long double ans = 0;
	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if (min_r[i]<1 || min_r[])
			long double cur_dis = dis(pts[i], pts[j]);
			long double sum_r = min_r[i] + min_r[j];
			if (cur_dis>= sum_r || abs(cur_dis-sum_r)<EPS)
			{
				// ok take both of them
				ans = max(ans, PI * (min_r[i]*min_r[i] + min_r[j]*min_r[j]));
			}
			else
			{
				long double cur_r = cur_dis /2.0;
				if (cur_r >= min_r[i])
				{
					ans = max(ans, 2 * PI * (cur_r * cur_r));	
				}
				if (cur_r >= min_r[i])
				{
					ans = max(ans, 2 * PI * (cur_r * cur_r));	
				}
				else
				{
					ans = max(ans, 2 * PI * (cur_r * cur_r));
				}
			}
		}
	}
	printf("%0.4LF\n", ans);
}