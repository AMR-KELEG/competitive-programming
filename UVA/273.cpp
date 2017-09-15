//AC
#include "bits/stdc++.h"
#define Point complex<long double>
#define X real()
#define Y imag()
#define Line pair<Point,Point>
#define cross(a,b) (conj(a)*(b)).imag()
#define EPS 0.0000000001
using namespace std;
std::vector<int> par;

int find(int a)
{
	if (a==par[a])
		return a;
	return par[a] = find(par[a]);
}

void merge(int a,int b)
{
	int pa = find(a);
	int pb = find(b);
	par[pa] = pb;
}

bool less_or_eq(long double val, long double lim)
{
	return val<=lim || abs(val-lim)<EPS; 
}

bool more_or_eq(long double val, long double lim)
{
	return val>=lim || abs(val-lim)<EPS; 
}

bool point_on_seg (Point p , Line l1)
{
	long double x = p.X;
	long double y = p.Y;
	Point & p1 =l1.first;
	Point & p2 =l1.second;
	return more_or_eq (x,min(p1.X, p2.X)) && less_or_eq (x,max(p1.X, p2.X)) &&
			more_or_eq (y,min(p1.Y, p2.Y)) && less_or_eq (y,max(p1.Y, p2.Y));
}

bool segment_intersect (Line l1, Line l2)
{
	Point & p1 = l1.first;
	Point & p2 = l1.second;
	Point & p3 = l2.first;
	Point & p4 = l2.second;
	long double dx1 = p1.X - p2.X;
	long double dy1 = p1.Y - p2.Y;
	long double dx2 = p3.X - p4.X;
	long double dy2 = p3.Y - p4.Y;
	long double det = (-dx1 * dy2) - (dx2 * -dy1);
	if (abs(det)<EPS)
	{
		// parallel or same segment
		if (abs(cross (p2-p1,p3-p1)) <EPS)
		{
			// same line
			return point_on_seg(p1,l2) || point_on_seg(p2,l2) || 
					point_on_seg(p3,l1) || point_on_seg(p4,l1);
		}
		return 0;
	}
	long double a = p3.X - p1.X;
	long double b = p3.Y - p1.Y;
	long double t = ((dy2 * a) + (-dx2 * b))/det;
	long double c = ((dy1 * a) + (-dx1 * b))/det;
	if ( more_or_eq(t,0) && less_or_eq(t,1) && more_or_eq(c,0) && less_or_eq(c,1) )
		return 1;
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
		int n;
		cin>>n;
		std::vector<Line> lines (n);
		par = std::vector<int> (n);
		for (int i=0;i<n;i++)
		{
			par[i] = i;
			long double x,y;
			cin>>x>>y;
			lines[i].first = Point(x,y);
			cin>>x>>y;
			lines[i].second = Point(x,y);
		}
		for (int i=0;i<n;i++)
		{
			for (int j=i+1;j<n;j++)
			{
				if (segment_intersect(lines[i],lines[j]))
					merge(i,j);
			}
		}
		int a,b;
		cin>>a>>b;
		while ( ! (a==0 && b==0))
		{
			a--;
			b--;
			if (find(a)==find(b))
				cout<<"CONNECTED\n";
			else
				cout<<"NOT CONNECTED\n";
			cin>>a>>b;
		}
		if (T)
			cout<<endl;
	}	
}