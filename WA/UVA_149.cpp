#include "bits/stdc++.h"
using namespace std;
const long double PI = (2*acos(0));
#define Point complex<long double>
#define Range pair<long double,long double>
std::vector<Range> reserved_ranges;
#define EPS 1e-6
const long double thr = 0.01*2*PI/360;
bool angle_in_range(long double angle, const Range & r)
{
	long double ang1 = angle - r.first;
	long double ang2 = r.second - angle;
	while(ang1<0)
	{
		ang1 += 2*PI;
	}
	while(ang1> 2*PI)
	{
		ang1 -= 2*PI;
	}
	while(ang2<0)
	{
		ang2 += 2*PI;
	}
	while(ang2> 2*PI)
	{
		ang2 -= 2*PI;
	}
	return ang1<ang2 && abs(ang1)>EPS && abs(ang2)>EPS;
}

bool inter(const Range & cur_range, const Range & r)
{
	return angle_in_range(cur_range.first, r) ||angle_in_range(cur_range.second, r);
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long double x,y,D;
	scanf("%LF %LF %LF", &x, &y, &D);
	while(x!=0 || y!=0 || D!=0)
	{
		reserved_ranges.clear();
		Point p(x,y);
		priority_queue<pair<long double, pair<int,int>>> qu;
		for (int i=-100;i<=100;i++)	
		{
			for (int j=-100;j<=100;j++)
			{
				Point q(i,j);
				qu.push({-abs(p-q),{i,j}});
			}
		}
		int ins= 0;
		while(!qu.empty())
		{
			Point q(qu.top().second.first, qu.top().second.second)	;
			long double Dis = -qu.top().first;
			qu.pop();
			long double th = abs(asin(0.5*D/Dis));
			if (abs(2*th)<thr)
				continue;
			// check intersection
			bool has_inter = 0;
			long double mid_th = arg(q-p);
			Range cur_range(mid_th-th, mid_th+th);
			if (cur_range.first<0)
			{
				cur_range.first += 2*PI;
				cur_range.second += 2*PI;
			}
			ins++;
			// if (ins>10)
			// 	break;
			// cout<<cur_range.first<<" "<<cur_range.second<<endl;
			for (auto r:reserved_ranges)
			{
				if (inter(cur_range, r))
				{
					has_inter= 1;
					break;
				}
			}
			if (!has_inter)
			{
				reserved_ranges.push_back(cur_range);
			}
		}
		printf("%d\n", (int)reserved_ranges.size());
		scanf("%LF %LF %LF", &x, &y, &D);
	}	
}