// AC
#include "bits/stdc++.h"
using namespace std;
#define Point complex<long double>
#define X real()
#define Y imag()
#define cp(a,b) (conj(a)*(b)).Y
#define dot(a,b) (conj(a)*b).X
#define angle(a) ((dot((a),Point(1,0)))/abs(a))
std::vector<Point> convex_hull;
std::vector<Point> pts;

long double find_hull()
{
	// return perimeter
	convex_hull.clear();
	for(int i=0;i<pts.size();i++)
	{
		// cout<<i<<": "<<pts[i].X<<" "<<pts[i].Y<<endl;
		while(convex_hull.size()>1 && 
			cp(convex_hull[convex_hull.size()-2]-convex_hull[convex_hull.size()-1],pts[i]-convex_hull[convex_hull.size()-1]) <=0)
		{
			convex_hull.pop_back();
		}
		convex_hull.push_back(pts[i]);
	}
	long double ans = 0;
	for (int i=0;i<convex_hull.size()-1;i++)
		ans += abs(convex_hull[i]-convex_hull[i+1]);
	ans += abs(convex_hull[0]-convex_hull[(int)convex_hull.size()-1]);
	return ans;
}

Point p;
bool cmp(Point & p1,Point & p2)
{
	if (abs(p1-p) <1e-9)
		return 1;
	if (abs(p2-p) <1e-9)
		return 0;
	if (abs(angle(p1-p)-angle(p2-p)) <1e-9)
		return abs(p1-p)<abs(p2-p);
	return angle(p1-p) < angle(p2-p);
}

int main()
{
	// std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	int t=0;
	while(n)
	{
		if (t)
			printf("\n");
		pts = std::vector<Point> (n);
		long double x,y;
		cin>>x>>y;
		pts[0] = Point(x,y);
		p = pts[0];
		for (int i=1;i<n;i++)
		{
			cin>>x>>y;
			pts[i] = Point(x,y);
			if (y<p.Y || (y==p.Y) && x<p.X)
			{
				p = pts[i];
			}
		}
		// cout<<p.X<<" "<<p.Y<<endl;
		sort(pts.begin(), pts.end(), cmp);
		long double per = find_hull();
		printf("Region #%d:\n", ++t);
		printf("(%0.1LF,%0.1LF)", convex_hull[0].X,convex_hull[0].Y);
		for (int i=1;i<convex_hull.size();i++)
			printf("-(%0.1LF,%0.1LF)", convex_hull[i].X,convex_hull[i].Y);
		printf("-(%0.1LF,%0.1LF)", convex_hull[0].X,convex_hull[0].Y);
		printf("\nPerimeter length = %0.2LF\n",find_hull());
		cin>>n;
	}
}	