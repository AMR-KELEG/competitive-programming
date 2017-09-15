//AC
#include "bits/stdc++.h"
#define point complex<long double>
#define INF 1000000000000000000
#define EPS 0.00000000001
#define x real()
#define y imag()
#define dot(a,b) (conj(a)*(b)).x
#define cross(a,b) (conj(a)*(b)).y
#define dis(a,b) norm(a-b)
#define len(a) abs(a)
using namespace std;

int main()
{
	// std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	point p1,p2;
	point m;
	long double xm,ym;
	bool fir =1;
	while(cin>>xm>>ym)
	{
		m = point(xm,ym);
		long double xp,yp;
		int n;
		cin>>n;
		cin>>xp>>yp;
		p2 = point(xp,yp);
		point minP(p2);
		long double minDis=dis(minP,m);
		while(n--)
		{
			cin>>xp>>yp;
			p1 = p2;
			p2 = point(xp,yp);
			// Update here
			if(dis(p2,m)<minDis)
			{
				minDis = dis(p2,m);
				minP = p2;
			}
			long double sign = 1;
			sign *= dot(p2-p1,p2-m);
			sign *= dot(p2-p1,p1-m);
			if(sign <0 || abs(sign)<EPS)
			{
				// Intersection
				long double t = dot((m-p1),(p2-p1));
				t /= len(p2-p1);
				t /= len(p2-p1);
				point newP = p1 + t*(p2-p1);
				if(dis(newP,m)<minDis)
				{
					minDis = dis(newP,m);
					minP = newP;
				}
			}
		}
		if(abs(minP.x)<EPS)
			minP.real(0);
		if(abs(minP.y)<EPS)
			minP.imag(0);
		cout<<fixed<<setprecision(4)<<minP.x<<endl<<minP.y<<endl;
	}
}