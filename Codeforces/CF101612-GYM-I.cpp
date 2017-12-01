// AC
#include "bits/stdc++.h"
using namespace std;
typedef complex<long double> Point;
#define X real()
#define Y imag()
#define EPS 1e-9
#define vec(a,b) ((b)-(a))
#define cross(a,b) (conj(a)*b).Y

struct cmp
{
	Point about;
	cmp(Point c)
	{
		about = c;
	}
	bool operator()(const Point &p, const Point & q) const
	{
		double c = cross(vec(about,p), vec(about,q));
		if (abs(c) < EPS)
			return pair<int,int>(p.Y, p.X) < pair<int,int>(q.Y, q.X);
		return c>0;
	}
};

void sortAnti(std::vector<Point> & pnts)
{
	Point about = pnts[0];
	for (int i=0;i<pnts.size();i++)
	{
		if (pair<int,int>(pnts[i].Y, pnts[i].X) < 
			pair<int,int>(about.Y, about.X))
			about = pnts[i];
	}
	sort(pnts.begin(), pnts.end(), cmp(about));
}

void convexHull(std::vector<Point> pnts, std::vector<Point> & convex)
{
	sortAnti(pnts);
	convex.push_back(pnts[0]);
	if (pnts.size()==1)
		return ;
	convex.push_back(pnts[1]);
	pnts.push_back(pnts[0]);
	for (int i=2;i<pnts.size();i++)
	{
		Point c = pnts[i];
		while(convex.size()>1)
		{
			Point b = convex.back();
			Point a = convex[convex.size()-2];
			if (cross(vec(b,a), vec(b,c)) < -EPS)
				break;
			convex.pop_back();
		}
		if (i!=pnts.size()-1)
			convex.push_back(pnts[i]);
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	#ifdef ONLINE_JUDGE
		freopen("intel.in","r",stdin);
		freopen("intel.out","w",stdout);
	#endif
	int n;
	scanf("%d", &n);
	long long int total_per = 0;
	int x,y;
	std::vector<Point> pol(n);
	scanf("%d %d",&x, &y);
	pol[0] = Point(x,y);
	for (int i=1;i<n;i++)
	{
		scanf("%d %d",&x, &y);
		pol[i] = Point(x,y);
		total_per += abs(x-pol[i-1].X);
		total_per += abs(y-pol[i-1].Y);
	}	
	total_per += abs(x-pol[0].X);
	total_per += abs(y-pol[0].Y);
	std::vector<Point> convex;
	convexHull(pol, convex);
	for (int i=1;i<convex.size();i++)
	{
		total_per -= abs(convex[i].X - convex[i-1].X);
		total_per -= abs(convex[i].Y - convex[i-1].Y);
	}
	total_per -= abs(convex[0].X - convex[convex.size()-1].X);
	total_per -= abs(convex[0].Y - convex[convex.size()-1].Y);
	printf("%I64d\n", total_per);
}