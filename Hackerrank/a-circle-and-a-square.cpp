// AC
#include "bits/stdc++.h"
using namespace std;
#define Point complex<long double>
#define dis(a,b) abs(a-b)
#define EPS 1e-9
#define X real()
#define Y imag()
#define rotate_90(v) (v)*(Point(0,1))
#define Line pair<Point,Point>

Point random_point(sqrt(2)*12328971835, 221938213897*acos(0));
Point center;
std::vector<Point> square(4);
int r;
bool in_circle(int x,int y)
{
	Point cur(x,y);
	long double d = dis(cur,center);
	return d<=r || abs(d-r)<=EPS;
}

bool on_ray(Point p1, Point p2,Point p)
{
	Point v1 = p-p1;
	if (abs(v1)<EPS)
	{
		return 1;
	}
	Point v2 = p2-p1;
	v1/=abs(v1);
	v2/=abs(v2);
	if (abs(v1.X-v2.X)<=EPS && abs(v1.Y-v2.Y)<=EPS)
	{
		return 1;
	}
	return 0;
}
bool intersects(Line l1, Line l2)
{
	Point p1 = l1.first;
	Point p2 = l1.second;
	Point p3 = l2.first;
	Point p4 = l2.second;
	long double a = p1.X - p3.X;
	long double b = p1.Y - p3.Y;
	long double A = p4.X - p3.X;
	long double C = p4.Y - p3.Y;
	long double B = p1.X - p2.X;
	long double D = p1.Y - p2.Y;
	long double det = A * D - B * C;
	long double m = (D * a - B * b)/det;
	long double t = (-C * a + A * b)/det;
	return m>0 && m<1 && t>0 && t<1;
}

bool in_square(int x,int y)
{
	Point p(x,y);
	for (int i=0;i<4;i++)
	{
		if (on_ray(square[i],square[i+1],p) && 
			on_ray(square[i+1],square[i],p))
		{
			return 1;
		}
	}
	int no_inter = 0;
	for (int i=0;i<4;i++)
	{
		if (intersects({square[i], square[i+1]}, {p,random_point}))
			no_inter++;
	}
	return no_inter%2;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int R,C;
	cin>>C>>R;
	std::vector<std::vector<bool> > is_in(R,std::vector<bool> (C,0));
	int x,y;
	cin>>y>>x>>r;
	center = Point(x,y);
	
	int x1,y1,x3,y3;
	cin>>y1>>x1>>y3>>x3;
	square[0] = Point(x1,y1);
	square[2] = Point(x3,y3);
	Point mid = square[0] + square[2];
	mid *= 0.5;
	Point vec = square[2] - square[0];
	vec *= 0.5;
	vec = rotate_90(vec);
	square[3] = mid + vec;
	square[1] = mid - vec;
	square.push_back(square[0]);
	for (int r=0;r<R;r++)
	{
		for (int c=0;c<C;c++)
		{
			if (in_circle(r,c) || in_square(r,c))
				is_in[r][c] = 1;
		}
	}	
	for (int r=0;r<R;r++)
	{
		for (int c=0;c<C;c++)
		{
			if (is_in[r][c])
				printf("#");
			else
				printf(".");
		}
		printf("\n");
	}
}