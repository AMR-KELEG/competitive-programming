//AC
#include "bits/stdc++.h"
using namespace std;
#define Point complex<long double>
#define X real()
#define Y imag()
#define EPS 1e-12
#define Segment pair<Point,Point>

Point inter(Segment s1,Segment s2)
{
	Point p1 = s1.first;
	Point p2 = s1.second;
	Point p3 = s2.first;
	Point p4 = s2.second;
	long double A = p1.X - p3.X;
	long double B = p1.Y - p3.Y;
	long double a = p4.X - p3.X;
	long double b = - (p2.X - p1.X);
	long double c = p4.Y - p3.Y;
	long double d = - (p2.Y - p1.Y);
	long double M = A * (d) - B * (b);
	long double det = a*d - b*c;
	M /= det;
	return p3 + M * (p4-p3);
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	while(n--)
	{
		Point A,B,C;
		long double x,y;
		cin>>x>>y;
		A =Point(x,y);
		cin>>x>>y;
		B =Point(x,y);
		cin>>x>>y;
		C =Point(x,y);
		long double onethird = 1;
		onethird/=3;
		Point D = B + (C-B)*onethird;
		Point E = C + (A-C)*onethird;
		Point F = A + (B-A)*onethird;
		std::vector<Point> pts;
		std::vector<Segment> seg(3);
		seg[0] = {A,D};
		seg[1] = {B,E};
		seg[2] = {C,F};
		for (int i=0;i<3;i++)
		{
			for (int j=i+1;j<3;j++)
				pts.push_back(inter(seg[i],seg[j]));
		}
		long double area = 0;
		pts.push_back(pts[0]);
		for (int i=0;i<pts.size()-1;i++)
		{
			area+= (pts[i+1].X - pts[i].X)*(pts[i+1].Y + pts[i].Y);
		}
		area *=0.5;
		area = abs(area);
		cout<<fixed<<setprecision(0)<<round(area+EPS)<<"\n";
	}
}