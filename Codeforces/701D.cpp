//AC
#include "bits/stdc++.h"
#define EPS 0.0000001
using namespace std;
long long int n;
long long int D;
long long int v1,v2;
long long int k;
long long int g;

// long double f(long double t_bus)
// {
// 	int rem_groups = g;
// 	long double group_pos = 0;
// 	long double bus_pos = 0;
// 	long double total_t = 0;
// 	while(rem_groups)
// 	{
// 		long double req_t = min(t_bus, (l-group_pos)/v2);
// 		total_t += req_t;
// 		rem_groups--;
// 		if(rem_groups == 0)
// 			break;
// 		// move all the groups there
// 		bus_pos += req_t*v2;
// 		group_pos += req_t*v1;
// 		// Make the bus meet with the groups
// 		req_t = (bus_pos - group_pos)/(v1+v2);
// 		total_t +=req_t;
// 		group_pos += req_t*v1;
// 		bus_pos = group_pos;
// 	}
// 	if(abs(group_pos-l)>EPS)
// 		total_t += (l-group_pos)*v1;
// 	return total_t;
// }

// long double ternary_search(long double l, long double r)
// {
// 	cout<<fixed<<l<<" : "<<f(l)<<" , "<<r<<" : "<<f(r)<<endl;
// 	if(r-l<EPS)
// 	{
// 		return f((r+l)*0.5);
// 	}
// 	long double mid1 = l + (r-l)/3;
// 	long double mid2 = r - (r-l)/3;
// 	cout<<"Mid: "<<fixed<<mid1<<" : "<<f(mid1)<<" , "<<mid2<<" : "<<f(mid2)<<endl<<endl;
// 	if(f(mid1)>=f(mid2))
// 	{
// 		return ternary_search(mid1,r);
// 	}
// 	return ternary_search(l,mid2);
// }

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n>>D>>v1>>v2>>k;
	g = ceil((n*1.0)/k);
	long double T = D;
	T /= (v2 + (g-1)*v1*( 1 + ((1.0*(v2-v1))/(v2+v1))) );
	long double total_t = T + (D-T*v2*1.0)/v1;
	cout<<fixed<<setprecision(9)<<total_t; 	
}