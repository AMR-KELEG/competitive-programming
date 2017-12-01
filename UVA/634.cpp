//AC
#include "bits/stdc++.h"
using namespace std;
#define Point complex<long double>
#define Line pair<Point,Point>
#define PI (2*acos(0))
#define X real()
#define Y imag()
#define EPS 1e-12
Point p;
Point rand_point(315123*sqrt(2), PI * 9830);

void fix(long double & d)
{
	if (abs(d)<EPS)
		d = 0;
	if (abs(d-1)<EPS)
		d = 1;
}

bool intersects(const Line & l1, const Line & l2)
{
	const Point & p1 = l1.first;
	const Point & p2 = l1.second;
	const Point & p3 = l2.first;
	const Point & p4 = l2.second;
	long double A = p1.X - p3.X;
	long double B = p1.Y - p3.Y;
	long double a = p4.X - p3.X;
	long double b = p1.X - p2.X;
	long double c = p4.Y - p3.Y;
	long double d = p1.Y - p2.Y;
	long double det = a*d - b*c;
	if (abs(det)<EPS)
		return 0;
	long double t1 = (d*A - b*B)/det;
	long double t2 = (-c*A + a*B)/det;
	fix(t1);
	fix(t2);
	if (t1<0 || t1>1 || t2<0 || t2>1)
		return 0;
	return 1;
}

bool is_equal(Point v1,Point v2)
{
	if (abs(v1.X - v2.X)>EPS || abs(v1.Y - v2.Y)>EPS)
		return 0;
	return 1;
}

bool on_line(Point p, Line l)
{
	Point & p1 = l.first;
	Point & p2 = l.second;
	Point v1 = p-p2;
	Point v2 = p1-p2;
	v1 /= abs(v1);
	v2 /= abs(v2);
	return is_equal(v1,v2);
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	while(n !=0)
	{
		long double x,y;
		std::vector<Point> pts(n+1);
		for (int i=0;i<n;i++)
		{
			long double x,y;
			cin>>x>>y;
			pts[i] = Point(x,y);
			if (i && abs(pts[i]-pts[i-1])<EPS)
			{
				i--;
				n--;
			}
		}
		pts[n] = pts[0];
		cin>>x>>y;
		p = Point(x,y);
		Line l1 = {p,rand_point};
		int inter = 0;
		for(int i=0;i<n;i++)
		{
			// i & i+1
			Line l2 = {pts[i],pts[i+1]};
			if (on_line(p,l2))
			{
				inter = 1;
				break;
			}
			if (intersects(l1,l2))
			{
				inter++;
			}
		}
		printf("%c\n", (inter%2)?'T':'F');
		cin>>n;
	}

}