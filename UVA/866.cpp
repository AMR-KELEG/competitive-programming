//AC 6:31
#include "bits/stdc++.h"
#define Point complex<long double>
#define Segment pair<Point, Point>
#define X real()
#define Y imag()
#define EPS 0.0000000001
#define cross(a,b) (conj(a)*(b)).Y
using namespace std;

bool less_or_eq (long double val, long double lim)
{
	return val<=lim || abs (val-lim)<EPS;
}

bool more_or_eq (long double val, long double lim)
{
	return val>=lim || abs (val-lim)<EPS;
}

bool point_on_seg(Point p, Segment s)
{
	Point & p1 = s.first;
	Point & p2 = s.second;
	long double x = p.X;
	long double y = p.Y;
	return more_or_eq(x,min(p1.X,p2.X)) && less_or_eq(x,max(p1.X,p2.X)) && 
			more_or_eq(y,min(p1.Y,p2.Y)) && less_or_eq(y,max(p1.Y,p2.Y));
}

bool intersect(Segment s1, Segment s2)
{
	Point & p1 = s1.first;
	Point & p2 = s1.second;
	Point & p3 = s2.first;
	Point & p4 = s2.second;
	long double dx1 =  p1.X - p2.X;
	long double dy1 =  p1.Y - p2.Y;
	long double dx2 =  p3.X - p4.X;
	long double dy2 =  p3.Y - p4.Y;
	long double det = (-dx1 * dy2) + (dx2 * dy1);
	if (abs(det)<EPS)
	{
		// parallel??
		long double c = cross(p2-p1,p3-p1);
		if (abs(c)<EPS)
		{
			// check inter
			return  point_on_seg(p1,s2) ||
					point_on_seg(p2,s2) ||
					point_on_seg(p3,s1) ||
					point_on_seg(p4,s1);
		}
		return 0;
	}
	long double a = p3.X - p1.X;
	long double b = p3.Y - p1.Y;
	long double t = ((dy2 * a)- (dx2 * b))/det;
	long double c = ((dy1 * a)- (dx1 * b))/det;
	return more_or_eq(t,0) && less_or_eq(t,1) &&more_or_eq(c,0) && less_or_eq(c,1);
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	while (T--)
	{
		int n;
		cin>>n;	
		long double x,y;
		std::vector<Segment> s(n);
		for (int i=0;i<n;i++)
		{
			cin>>x>>y;
			s[i].first = Point(x,y);
			cin>>x>>y;
			s[i].second = Point(x,y);
		}
		int ans = n;
		for (int i=0;i<n;i++)
		{
			for (int j =i+1;j<n;j++)
			{
				if (intersect(s[i],s[j]))
				{
					ans+=2;
				}
			}
		}
		cout<<ans<<endl;
		if (T)
			cout<<endl;

	}	
}