// AC
#include "bits/stdc++.h"
using namespace std;
#define Point complex<long double>
#define X real()
#define Y imag()
#define EPS 0.0000000000001
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long double x,y;
	while(cin>>x>>y)
	{
		Point a(x,y);
		cin>>x>>y;
		Point b(x,y);
		cin>>x>>y;
		Point c(x,y);

		Point p0 = (long double)0.5 * (a+b);
		Point p1 = (long double)0.5 * (c+b);

		long double dx1 = b.X - a.X;
		long double dy1 = b.Y - a.Y;
		long double dx2 = c.X - b.X;
		long double dy2 = c.Y - b.Y;

		long double det = dx1 * dy2 - dx2 * dy1;
		long double c1 = p0.X - p1.X;
		long double c2 = p0.Y - p1.Y;
		long double t = (1/det) * (c1 * dx1 + c2 * dy1);

		Point center = p1 + t * Point (dy2, -dx2);
		// OK -- RIGHT
		long double R = abs(center -a);
		// (x - 3.000)^2 + (y + 2.000)^2 = 5.000^2
		printf("(x ");
		if (abs(center.X)<EPS)
			center.real(0);
		if (center.X >0)
			printf("- %0.3LF)^2 + (y ", abs(center.X));
		else
			printf("+ %0.3LF)^2 + (y ", abs(center.X));
		if (abs(center.Y)<EPS)
			center.imag(0);
		if (center.Y >0)
			printf("- %0.3LF)^2 = %0.3LF^2", abs(center.Y), R);
		else
			printf("+ %0.3LF)^2 = %0.3LF^2", abs(center.Y), R);
		printf("\n");
		// x^2 + y^2 - 6.000x + 4.000y - 12.000 = 0
		printf("x^2 + y^2 ");
		if (center.X >0)
			printf("- %0.3LFx ", 2*abs(center.X));
		else
			printf("+ %0.3LFx ", 2*abs(center.X));
		if (center.Y >0)
			printf("- %0.3LFy ", 2*abs(center.Y));
		else
			printf("+ %0.3LFy ", 2*abs(center.Y));
		long double CONSTANT = (center.X * center.X) + (center.Y * center.Y) - (R * R);
		if (abs(CONSTANT)<EPS)
			CONSTANT = 0;
		if (CONSTANT>0)
			printf("+ %0.3LF = 0\n", CONSTANT);
		else
			printf("- %0.3LF = 0\n", abs(CONSTANT));
		printf("\n"); 
	}

}