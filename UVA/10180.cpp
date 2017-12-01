/* AC
http://www.voidcn.com/article/p-rfvkcqxc-bex.html
*/
#include "bits/stdc++.h"
using namespace std;
#define Point complex<double>
#define X real()
#define Y imag()
#define dot(a,b) (conj(a)*(b)).X
#define EPS 1e-12
#define PI (2*acos(0))
bool line_interesect_circle(Point & p1,Point & p2, double & R)
{
	double a = dot(p2-p1, p2-p1);
	double b = 2 * dot(p2-p1, p1);
	double c = dot(p1, p1) - R*R;
	if (a<0)
	{
		a*=-1;
		b*=-1;
		c*=-1;
	}
	double det = b*b - (4*a*c);
	if (abs(det)<EPS)
		det = 0;
	if (det<0)
		return 0;
	double t1 = (-b + sqrt(det))/(2*a);
	if (abs(t1)<EPS)
		t1 = 0;
	if (abs(t1-1)<EPS)
		t1 = 1;
	double t2 = (-b - sqrt(det))/(2*a);
	if (abs(t2)<EPS)
		t2 = 0;
	if (abs(t2-1)<EPS)
		t2 = 1;
	if ((t1>=0 && t1<=1) || (t2>=0 && t2<=1))
	{
		return 1;
	}
	return 0;
}

double solve(Point & p1,Point & p2, double & R)
{
	if (!line_interesect_circle(p1,p2,R))
	{
		return abs(p1-p2);
	}
	double d1 = abs(p1);
	double d2 = abs(p2);
	double ans = sqrt(d1*d1 - R*R);
	ans += sqrt(d2*d2 - R*R);
	double d = abs(p2-p1);
	double phi = acos((d1*d1 + d2*d2 - d*d) / (2*d1*d2));
	phi -= acos(R/d1);
	phi -= acos(R/d2);
	return ans + R * phi;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	scanf("%d",&T);
	while(T--)
	{
		double x1,y1,x2,y2,R;
		scanf("%lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &R);
		Point p1(x1,y1);
		Point p2(x2,y2);
		printf("%0.3lf\n",solve(p1,p2,R));		
	}
}