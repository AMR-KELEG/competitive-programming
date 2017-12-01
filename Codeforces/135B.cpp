/* AC
   Brute Force
*/
#include "bits/stdc++.h"
using namespace std;
#define Point complex<long double>
#define X real()
#define Y imag()
#define EPS 1e-9
std::vector<int> idx={0,1,2,3,4,5,6,7};
std::vector<Point> pts;

long double area(const std::vector<Point> & p)
{
	long double ans = 0;
	for (int i=0;i<3;i++)
	{
		ans+= 0.5*(p[i].X+p[i+1].X) * (p[i].Y-p[i+1].Y);
	}
	ans+= 0.5*(p[3].X+p[0].X) * (p[3].Y-p[0].Y);
	return abs(ans);
}
Point min_p;
bool cmp(const Point & p1, const Point & p2)
{
	return arg(p1-min_p)<arg(p2-min_p);
}

void sort_pts(std::vector<Point> & p)
{
	// Find lowest point
	min_p = p[0];
	for (int i=0;i<4;i++)
	{
		if (p[i].Y<min_p.Y || 
			(p[i].Y == min_p.Y && p[i].X<min_p.X))
			min_p = p[i];
	}
	// Sort
	sort(p.begin(), p.end(),cmp);
}

bool is_square(const std::vector<Point> & p)
{
	long double s = abs(p[3]-p[0]);
	for (int i=1;i<4;i++)
	{
		if (abs(s-abs(p[i]-p[i-1]))>EPS)
			return 0;
	}
	return abs(s*s - area(p))<EPS;
}

bool is_rectangle(const std::vector<Point> & p)
{
	long double s1 = abs(p[0]-p[1]);
	long double s2 = abs(p[1]-p[2]);
	long double s3 = abs(p[2]-p[3]);
	long double s4 = abs(p[3]-p[0]);
	long double area1 = s1*s2;
	return abs(area1 - area(p))<EPS && abs(s1-s3)<EPS && abs(s2-s4)<EPS;
}

bool check()
{
	vector<Point> sq;
	for (int i=0;i<4;i++)
	{
		sq.push_back(pts[idx[i]]);
	}
	sort_pts(sq);

	vector<Point> rec;
	for (int i=0;i<4;i++)
	{
		rec.push_back(pts[idx[4+i]]);
	}
	sort_pts(rec);
	return is_square(sq) && is_rectangle(rec);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int x,y;
	for (int i=0;i<8;i++)
	{
		scanf("%d %d", &x, &y);
		pts.push_back(Point(x, y));
	}
	do
	{
		if (check())
		{
			printf("YES\n");
			for(int i=0;i<4;i++)
			{
				printf("%d ", idx[i]+1);
			}
			printf("\n");
			for(int i=0;i<4;i++)
			{
				printf("%d ", idx[4+i]+1);
			}
			return 0;
		}
	}
	while(next_permutation(idx.begin(), idx.end()));
	printf("NO\n");
}