#include "bits/stdc++.h"
using namespace std;
#define Point complex<long double>
std::vector<Point> pts;

#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel

bool cmp(Point p1,Point p2)
{
	return p1.X<p2.X || (p1.X==p2.X && p1.Y<p2.Y);
}

vector<Point> ConvexHull() {
	int n= pts.size(),k=0;
	std::vector<Point> H(2*n);
	sort(pts.begin(), pts.end(),cmp);

	for (int i=0;i<n;i++)
	{
		while(k>=2 && cp(H[k-1]-H[k-2],pts[i]-H[k-2])<=0)k--;
		H[k++] = pts[i];
	}
	for (int i=n-2, t=k+1;i>=0;i--)
	{
		while(k>=t && cp(H[k-1]-H[k-2],pts[i]-H[k-2])<=0)k--;
		H[k++] = pts[i];
	}
	H.resize(k-1);
	return H;
}

long double find_dis(Point p, Point p1, Point p2)
{
	// ternary_search on t
	long double l = 0,r=1;
	for (int it=0;it<1000;it++)
	{
		long double th1 = l + (r-l)/3;
		long double th2 = l + 2*(r-l)/3;
		long double d1 = abs((p1 + th1*(p2-p1))-p);
		long double d2 = abs((p1 + th2*(p2-p1))-p);
		if (d1<d2)
		{
			r = th2;
		}
		else
		{
			l = th1;
		}
	}
	return abs((p1 + l*(p2-p1))-p);
}

long double solve()
{
	std::vector<Point> hull = ConvexHull();
	for (auto pb:hull)
		cout<<pb.X<<" "<<pb.Y<<endl;
	long double ans = 1e12;
	for (int i=0;i<hull.size();i++)
	{
		long double cur_max = 0;
		for (int j=0;j<hull.size();j++)
		{
			cur_max = max(cur_max, find_dis(pts[j],pts[i],pts[(i+1)%hull.size()]));
		}
		cout<<cur_max<<endl;
		ans = min(ans, cur_max);
	}
	return ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	pts = std::vector<Point> (n);
	int x,y;
	for (int i=0;i<n;i++){
		cin>>x>>y;
		pts[i] = Point(x,y);
	}
	cout<<fixed<<setprecision(9)<<solve();
}