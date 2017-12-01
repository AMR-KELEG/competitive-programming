//AC
#include "bits/stdc++.h"
using namespace std;
#define Point complex<long double>
#define Vector complex<long double>
#define Line pair<Point, Point>
#define dot(a,b) (a*b).real()
#define cross(a,b) (a*b).imag()
#define X real()
#define Y imag()
#define EPS 0.0000000001

bool eq(long double val,long double cmp)
{
	if (abs(val-cmp)<EPS)
		return 1;
	return 0;
}

bool on_segment(const Point & p, const Line & l)
{
	long double min_x = min (l.first.X,l.second.X);
	long double max_x = max (l.first.X,l.second.X);
	long double min_y = min (l.first.Y,l.second.Y);
	long double max_y = max (l.first.Y,l.second.Y);

	long double x = p.X;
	long double y = p.Y;

	if ( (eq(x,min_x) || eq(x,max_x) || (x>min_x && x<max_x) ) &&  
		 (eq(y,min_y) || eq(y,max_y) || (y>min_y && y<max_y) ))
	{
		return 1;
	}
	return 0;
}

bool same_line (const Line & l1,const Line & l2)
{
	// dot product
	Vector v1 = l2.first - l1.first;
	Vector v2 = l2.second - l1.first;
	long double cross_prod = cross(v1,v2);
	// not enough
	
	return abs(cross_prod)<EPS && 
		(on_segment(l1.first,l2) ||on_segment(l1.second,l2) ||
		on_segment(l2.first,l1) ||on_segment(l2.second,l1));
}	



bool interesects (const Line & l1,const Line & l2)
{
	// How to find the intersection of two lines??
	// a is dely b is -delx 
	long double a1 = l1.first.Y -l1.second.Y;
	long double b1 = l1.first.X -l1.second.X;
	b1 = -b1;
	long double c1 = (l1.first.X * a1) + (l1.first.Y * b1);
	long double a2 = l2.first.Y -l2.second.Y;
	long double b2 = l2.first.X -l2.second.X;
	b2 = -b2;
	long double c2 = (l2.first.X * a2) + (l2.first.Y * b2);
	// det of a1 b1
	long double det = (a1*b2) - (b1 * a2);
	if (abs(det)<EPS)
		return 0;
	// long double xin = (1./det) * ()
	// cout<<l1.first.X<<" "<<l1.first.Y<<endl;
	// cout<< a1<<" X + "<<b1<<" Y = "<<c1<<endl<<endl;
	// cout<<l2.first.X<<" "<<l2.first.Y<<endl;
	// cout<< a2<<" X + "<<b2<<" Y = "<<c2<<endl<<endl;
	// Inverse:
	// b2 -b1
	// -a2 a1
	// Multiply by:
	// c1
	// c2
	long double x_in = (b2*c1) - (b1*c2);
	long double y_in = (-a2*c1) + (a1*c2);
	x_in /= det;
	y_in /= det;
	// cout<<x_in<<" "<<y_in<<endl;
	Point inter (x_in, y_in);
	if (on_segment(inter,l1) && on_segment(inter,l2))
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
	for (int t=1;t<=T;t++)
	{
		int no_of_seg;
		cin>> no_of_seg;
		std::vector<Line> segments(no_of_seg);
		int x,y;
		for (int s=0 ; s< no_of_seg; s++)
		{
			cin>>x>>y;	
			segments[s].first = Point (x,y);
			cin>>x>>y;	
			segments[s].second = Point (x,y);
		}
		int ans = no_of_seg;
		for (int fir=0;fir<no_of_seg;fir++)
		{
			for (int sec =0; sec<no_of_seg;sec++)
			{
				if (fir == sec)
					continue;
				if (same_line(segments[fir],segments[sec]))
				{
					ans--;
					break;
				}
				if (interesects(segments[fir],segments[sec]))
				{
					ans--;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}	
}