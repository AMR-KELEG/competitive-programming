/* AC
- Line Sweep
*/

#include "bits/stdc++.h"
using namespace std;
const long double INF=10000.00;
#define EPS 1e-5

struct Point
{
	long double x,y;
	Point(long double xx=0, long double yy=0):x(xx), y(yy){}
	bool operator <(const Point & q) const
	{
		return (this->x)<q.x || ((this->x)==q.x && (this->y)<q.y);
	}

};

long double find_dis(const Point &p, const Point & q)
{
	long double dx = p.x - q.x;
	long double dy = p.y - q.y;
	return sqrt((dx*dx) + (dy*dy));
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	scanf("%d", &n);
	while(n)
	{
		std::vector<Point> pts(n);
		std::vector<Point> rev_pts(n);
		long double x,y;
		for(int i=0;i<n;i++)
		{
			scanf("%LF %LF", &x, &y);
			pts[i] = Point(x,y);			
		}
		sort (pts.begin(), pts.end());
		for(int i=0;i<n;i++)
		{
			rev_pts[i] = Point(pts[i].y, pts[i].x);
		}

		long double dis = INF;
		for (int i=1;i<n;i++)
		{
			dis = min(dis, find_dis(pts[i], pts[i-1]));
		}

		set<Point> active_window;
		int cur_start = 0;
		int cur_indx = 0;
		while(cur_start<n)
		{
			if (active_window.find(rev_pts[cur_start]) == active_window.end())
			{
				active_window.insert(rev_pts[cur_start]);
				cur_indx = cur_start+1;
			}
			while(cur_indx<n && pts[cur_indx].x < pts[cur_start].x + dis)
			{
				active_window.insert(rev_pts[cur_indx]);
				cur_indx++;
			}

			active_window.erase(rev_pts[cur_start]);
			// iterate
			// min_y = pts[cur_start] - min_dis , x = -INF
			// max_y = pts[cur_start] + min_dis , x = -INF
			auto it1 = active_window.lower_bound(Point(pts[cur_start].y - dis - EPS, -INF - EPS));
			auto it2 = active_window.lower_bound(Point(pts[cur_start].y + dis + EPS, INF + EPS));
			do
			{
				if (it1==active_window.end())
					break;
				Point p = *it1;
				swap(p.x, p.y);
				dis = min(dis, find_dis(pts[cur_start], p));
				++it1;
			}
			while(it1!=it2);
			cur_start++;
		}

		if (dis<INF)
		{
			printf("%0.4LF\n", dis);
		}
		else
		{
			printf("INFINITY\n");
		}
		scanf("%d", &n);
	}
}