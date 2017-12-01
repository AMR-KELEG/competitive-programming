// WA
#include "bits/stdc++.h"
using namespace std;
#define EPS 10e-9
#define SPS 10e-12
#define X real()
#define Y imag()
#define Point complex<long double>
#define Line pair<Point, Point>
#define PI (2*acos(0))
// Point random_point(PI*123289682415432142LL, sqrt(2)*23789621401204143LL);
long double max_x,max_y;
std::vector<Point> pts;
int n;

void fix(long double & d)
{
	if (abs(d)<SPS)
		d = 0;
	if (abs(d-1)<SPS)
		d = 1;
}

long double interesect(Line l1,Line l2)
{
	Point & p1 = l1.first;
	Point & p2 = l1.second;
	Point & p3 = l2.first;
	Point & p4 = l2.second;
	long double A = p1.X - p3.X;
	long double B = p1.Y - p3.Y;
	long double a = p1.X - p2.X;
	long double b = p4.X - p3.X;
	long double c = p1.Y - p2.Y;
	long double d = p4.Y - p3.Y;
	long double det = a*d - b*c;
	if (abs(det)<SPS)
		return -1;
	long double t1 = (d*A - b*B)/det;
	long double t2 = (-c*A + a*B)/det; 
	int ok =0 ;
	Point in1 = p1 + t1 * (p2-p1);
	if (t1>=0 && t1<=1)
	{
		ok++;
	}
	else
	{	
		// dis between in1 and other points p1 & p2 <EPS
		if (abs(in1-p1)<=EPS || abs(in1-p2)<=EPS)
			ok++;
	}
	if (t2>=0 && t2<=1)
	{
		ok++;
	}
	else
	{	
		// dis between in1 and other points p3 & p4 <EPS
		if (abs(in1-p3)<=EPS || abs(in1-p4)<=EPS)
			ok++;
	}
	if (ok == 2)
		return t1;
	return -1;
}

bool eq(Point p1, Point p2)
{
	return abs(p1.X-p2.X)<SPS && abs(p1.Y-p2.Y)<SPS;
}

bool point_on_line(Point p, Line l)
{
	Point p1 = l.first;
	Point p2 = l.second;
	Point v1 = p2-p1;
	Point v2 = p-p1;
	if (abs(v1-v2)<EPS)
		return 1;
	if (abs(v1)>SPS)
		v1 /= abs(v1);
	if (abs(v2)>SPS)
		v2 /= abs(v2);
	return abs(v1-v2)<EPS;
}

bool point_inside_pol(Point pt)
{
	// line is 
	Line l (pt,Point(max_x*PI, max_y*sqrt(2)));
	int inter = 0;
	for (int i=0;i<n;i++)
	{
		Line l1 = {pts[i],pts[i+1]};
		if (point_on_line(pt,l1))
			return 1;
		if (interesect(l,l1) !=-1)
		{
			inter++; 
		}
	}
	return inter%2;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int m;
	while (cin>>n>>m)
	{
		if (!n)
			break;
		pts = std::vector<Point> (n);
		long double x,y;
		for (int i=0;i<n;i++)
		{
			cin>>x>>y;
			if (i>0)
			{
				max_x=max(max_x,x);
				max_y=max(max_y,y);
			}
			else
			{
				max_x = x;
				max_y = y;
			}
			pts[i] = Point(x,y);
		}
		pts.push_back(pts[0]);
		
		// line
		Line l;
		while(m--)
		{
			cin>>x>>y;
			max_x=max(max_x,x);
			max_y=max(max_y,y);
			l.first = Point(x,y);
			cin>>x>>y;
			max_x=max(max_x,x);
			max_y=max(max_y,y);
			l.second = Point(x,y);
			std::vector<long double> inter_points;
			if (point_inside_pol(l.first))
			{
				inter_points.push_back(0);
			}
			if (point_inside_pol(l.second))
			{
				inter_points.push_back(1);
			}
			// try to intersect l with pts[i],pts[i+1]
			for (int i=0;i<n;i++)
			{
				Line l1 = {pts[i],pts[i+1]};
				long double inter_param = interesect(l,l1);
				if (inter_param!=-1)
				{
					inter_points.push_back(inter_param);
				}
			}
			sort (inter_points.begin(), inter_points.end());
			// cout<<inter_points.size()<<endl;
			long double ans = SPS;
			for (int i=0;i<int(inter_points.size())-1;i++)
			{
				Point p1 = l.first + inter_points[i]*(l.second - l.first);
				Point p2 = l.first + inter_points[i+1]*(l.second - l.first);
				Point mid = p1+p2;
				mid *= 0.5;
				// cout<<p1.X<<" "<<p1.Y<<" "<<p2.X<<" "<<p2.Y<<endl;
				if (point_inside_pol(mid))
				{
					ans += abs(p2-p1);
				}
			}
			printf("%0.3f\n", double(ans+SPS));
		}
		// cin>>n>>m;
	}
}