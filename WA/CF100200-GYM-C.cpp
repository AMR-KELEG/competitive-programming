#include "bits/stdc++.h"
using namespace std;
#define Point complex<long double>
#define dis(a,b) abs(a-b)
#define EPS 1e-10
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	#ifdef ONLINE_JUDGE
		freopen("circles.in","r",stdin);
		freopen("circles.out","w",stdout);
	#endif	
	int n;
	cin>>n;
	std::vector<Point> centers(n);
	std::vector<int> r(n);
	int inter_pts = 0;
	for (int i=0;i<n;i++)
	{
		long double x,y;
		cin>>x>>y>>r[i];
		centers[i] = Point(x,y);
		bool has_inter = 0;
		for (int j=0;j<i;j++)
		{
			long double cur_dis = dis(centers[i], centers[j]);
			int min_dis = max(r[i], r[j]) - min(r[i], r[j]);
			int max_dis = r[i] + r[j];
			if (cur_dis < min_dis || abs(cur_dis-min_dis)<EPS)
				continue;
			if (cur_dis > max_dis || abs(cur_dis-max_dis)<EPS)
				continue;
			inter_pts += 2;
			has_inter = 1;
		}
		if (!has_inter)
			inter_pts++;
	}

	cout<<1 + inter_pts;
}