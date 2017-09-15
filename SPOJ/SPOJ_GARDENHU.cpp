//AC
#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> point;
int n;
int cross(point & o,point & a,point & b)
{
	return	(a.first-o.first)*(b.second-o.second)-(a.second-o.second)*(b.first-o.first); 
}
std::vector<point> convex_hull(std::vector<point> P)
{
	int k=0;
	sort(P.begin(), P.end());
	std::vector<point> hull(2*n);
	for(int i=0;i<n;i++)
	{
		while(k>=2 && cross(hull[k-2],hull[k-1],P[i])<=0)k--;
		hull[k++]=P[i];
	} 

	for(int i=n-2,t=k+1;i>=0;i--)
	{
		while(k>=t && cross(hull[k-2],hull[k-1],P[i])<=0)k--;
		hull[k++]=P[i];
	}
	hull.resize(k-1);
	return hull;
}

long double dis(point & a,point &b)
{
	long double dx=a.first-b.first;
	long double dy=a.second-b.second;
	dx*=dx;
	dy*=dy;
	return sqrt(dx+dy);
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n;
	std::vector<pair<int,int> > p(n);
	for(int i=0;i<n;i++)cin>>p[i].first>>p[i].second;

	std::vector<point> h=convex_hull(p);
	long double ans=0;
	for (int i = 0; i < h.size()-1; ++i)
	{
		ans+=dis(h[i],h[i+1]);
		// cout<<ans<<endl;
	}
	ans+=dis(h[h.size()-1],h[0]);
	cout<<floor(ans)<<endl;
}