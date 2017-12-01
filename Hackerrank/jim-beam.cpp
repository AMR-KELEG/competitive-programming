// AC
#include "bits/stdc++.h"
using namespace std;
#define Point complex<long double>
#define X real()
#define Y imag()
#define EPS 1e-10

bool equal(long double a,long double b)
{
	return abs(a-b)<EPS;
}

bool point_on_ray(const Point & p, const Point & p1,const Point & p2)
{
	if (abs(p-p1)<EPS || abs(p-p2)<EPS)
		return 1;
	Point v1 = p-p1;
	v1 /= abs(v1);
	Point v2 = p2-p1;
	v2 /= abs(v2);
	if (abs(v1.X-v2.X)<EPS && abs(v1.Y-v2.Y)<EPS)
		return 1;
	return 0;
}

bool point_on_seg(const Point & p, const Point & p1,const Point & p2)
{
	return point_on_ray(p,p1,p2) && point_on_ray(p,p2,p1);
}

bool inter(const Point & p1,const Point & p2,const Point & p3,const Point & p4)
{
	long double a = p4.X - p3.X;
	long double b = p1.X - p2.X;
	long double c = p4.Y - p3.Y;
	long double d = p1.Y - p2.Y;
	long double det = a*d - b*c;
	if (abs(det)<EPS)
	{
		// check if the same line ??
		if (point_on_seg(p3,p1,p2) || point_on_seg(p4,p1,p2))
			return 1;
		return 0;
	}
	long double e = p1.X - p3.X;
	long double f = p1.Y - p3.Y;
	
	long double m = (d*e - b*f)/det;
	long double t = (-c*e + a*f)/det;

	if (equal(m,1) || equal(m,0) || (m>=0 && m<=1))
	{
		if (equal(t,1) || equal(t,0) || (t>=0 && t<=1))
			return 1;
	}
	return 0;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	while(T--)
	{
		Point p0(0,0) ,p1 ,p2 ,p3;
		long double x,y;
		cin>>x>>y;
		p2 = Point(x,y);
		cin>>x>>y;
		p3 = Point(x,y);
		cin>>x>>y;
		p1 = Point(x,y);
		if (!inter(p0,p1,p2,p3))
			printf("YES\n");
		else
			printf("NO\n");
	}	
}