// AC
#include "bits/stdc++.h"
using namespace std;
#define Point complex<long double>
#define X real()
#define Y imag()
#define PI (2*acos(0))
#define EPS 1e-12
#define dot(a,b) (conj(a)*b).X
#define cross(a,b) (conj(a)*(b)).Y

Point pts[3];
int min_x,max_x,min_y,max_y;
bool is_zero(Point p)
{
	return abs(p.X)<EPS && abs(p.Y)<EPS;
}

bool get_input()
{
	min_x = 99;
	max_x = 0;
	min_y = 99;
	max_y = 0;
	long double x,y;
	for (int i=0;i<3;i++)
	{
		cin>>x>>y;
		min_x = min(min_x,(int) ceil(x));
		max_x = max(max_x,(int) floor(x));
		min_y = min(min_y,(int) ceil(y));
		max_y = max(max_y,(int) floor(y));
		pts[i] = Point(x,y);		
	}
	max_x = min(99,max_x);
	max_y = min(99,max_y);
	min_x = max(1,min_x);
	min_y = max(1,min_y);
	return ! (is_zero(pts[0]) && is_zero(pts[1]) && is_zero(pts[2]));
}

bool point_in_triangle(Point p)
{
	for (int i=0;i<3;i++)
	{
		if (is_zero((p-pts[i])))
			return 1;
	}
	long double tri_area = abs(0.5 * cross((pts[1]-pts[0]),(pts[2]-pts[0])));
	long double sum_area = 0;
	for (int i=0;i<3;i++)
	{
		sum_area += abs(0.5*cross((pts[i]-p),(pts[(i+1)%3]-p)));
	}	
	return abs(tri_area - sum_area) < EPS;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	while(get_input())
	{
		int ans = 0;
		for (int x=min_x;x<=max_x;x++)
		{
			for (int y=min_y;y<=max_y;y++)
			{
				Point p(x,y);
				ans += point_in_triangle(p);
			}
		}
		printf("%4d\n",ans );
	}
}