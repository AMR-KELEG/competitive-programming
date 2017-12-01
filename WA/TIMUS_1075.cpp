// WA??
#include "bits/stdc++.h"
using namespace std;
struct Point
{
	long double x,y,z;
	Point(long double xx=0,long double yy=0,long double zz=0):x(xx),y(yy),z(zz){}
	long double len()
	{
		long double ans = x*x + y*y + z*z;
		return sqrt(ans);
	}
	
	long double dot(Point p2)
	{
		return x * p2.x + y * p2.y + z * p2.z;
	}

	Point operator - (Point p2)
	{
		Point ans;
		ans.x = x-p2.x;
		ans.y = y-p2.y;
		ans.z = z-p2.z;
		return ans;
	}
	
	Point operator + (Point p2)
	{
		Point ans;
		ans.x = x+p2.x;
		ans.y = y+p2.y;
		ans.z = z+p2.z;
		return ans;
	}
	
	Point operator * (long double c)
	{
		return Point (x*c, y*c, z*c);
	}
};
#define EPS 0.0000000000000001

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	Point a,b,c;
	long double x,y,z;
	cin>>x>>y>>z;
	a = Point(x,y,z);
	cin>>x>>y>>z;
	b = Point(x,y,z);
	cin>>x>>y>>z;
	c = Point(x,y,z);		
	long double R;
	cin>>R;
	Point v1 = a - c;
	Point v2 = b - a;
	long double A = v2.dot(v2);
	long double B = 2 * v1.dot(v2) ;
	long double C = v1.dot(v1) - (R*R);
	long double det = (B*B) - (4*A*C);
	if (abs(det)<=EPS || det<0)
	{
		printf("%0.2LF", (a-b).len());
		return 0;
	}
	long double t1 = (-B - sqrt(det)) / (2*A);
	long double t2 = (-B + sqrt(det)) / (2*A);
	if (t1>t2)
		swap(t1,t2);
	// a -> t1 || t1 -> t2 || t2 -> b
	Point pa = ((b-a) * t1) +a;
	Point pb = ((b-a) * t2) +a;
	long double ans = (a-pa).len()+ (b-pb).len() ;
	long double ang = (pa-c).dot (pb-c);
	ang /= (pa-c).len();
	ang /= (pb-c).len();
	ang = acos(ang);
	ans += R * ang;
	printf("%0.2LF", ans);
}