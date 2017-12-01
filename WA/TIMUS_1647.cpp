// WA??
#include "bits/stdc++.h"
using namespace std;
#define Point complex<long double>
#define X real()
#define Y imag()
#define EPS 1e-9
std::vector<Point> pts;

Point m,n;
void fix(long double & d)
{
	if (abs(d)<EPS)
		d= 0;
	if (abs(d-1)<EPS)
		d = 1;
}

bool solve()
{
	long double A = abs(pts[0]-pts[1]);
	long double B = abs(pts[0]-pts[2]);
	long double C = abs(pts[2]-pts[1]);
	long double a = B;
	long double b = -0.5*(A+B+C);
	long double c = 0.5*A;
	long double det = b*b - 4*a*c;
	if (abs(det)<EPS)
		det = 0;
	if (det<0)
		return 0;
	long double t = -b/a;
	t/=2;
	t+= sqrt(det)/(2*a);
	if (t<0 || t>1)
		fix(t);
	if (t<=0 || t>1)
		return 0;
	long double s = 1/(2*t);
	if (s<0 || s>1)
		fix(s);
	if (s<0 || s>1)
		return 0;
	m = pts[0] + (s) * (pts[1]-pts[0]);
	n = pts[0] + (t) * (pts[2]-pts[0]);
	return 1;
}

bool cmp(Point & p1,Point & p2)
{
	return p1.X<p2.X;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int x,y;
	for (int i=0;i<3;i++)
	{
		cin>>x>>y;
		pts.push_back(Point(x,y));
	}	
	sort (pts.begin(), pts.end(),cmp);
	do 
	{
		if (solve())
		{
			cout<<"YES\n";
			cout<<fixed<<setprecision(20)<<m.X<<" "<<m.Y<<"\n";
			cout<<fixed<<setprecision(20)<<n.X<<" "<<n.Y;
			return 0;
		}
	}while(next_permutation(pts.begin(), pts.end(), cmp));
	cout<<"NO";
	return 0;
}