#include "bits/stdc++.h"
#include "complex"
#define EPS 1e-9
#define cross(a,b) ((conj(a)*(b)).imag())
using namespace std;
typedef complex<long double> point;

bool intersect(const point &a, const point &b, const point &p,const point &q) 
{
	//handle degenerate cases
	double d1 = cross(p - a, b - a);
	double d2 = cross(q-a,b-a);
	// ret = (d1*q - d2*p)/(d1-d2);
	if(fabs(d1-d2)>EPS)
		return 1;
	return 0;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	point p1(0,0);
	point p2(0,2);
	point p3(0,0);
	point p4(0,4);
	if(intersect(p1,p2,p3,p4))
		cout<<"IN";
	// cin>>t;
	// int n,m;
	// while(t--)
	// {
	// 	cin>>n>>m;
	// }	

	// return 0;
}

/*

Input
----------------
The first line of the input contains number t – the amount of tests.
Then t test descriptions follow. 
The first line of each test contains two integers n and m - the number of stick and the number of queries. 
Next n lines contain four integers Ax, Ay, Bx, By - the coordinates of the endpoints of a stick. 
You may consider stick to be straight segment on a plane.
The next m lines contain two integers each x and y which are the queries.

Constraints
----------------
1 <= t <= 100
1 <= n, m <= 1000
-10000 <= Ax, Ay, Bx, By <= 10000
1 <= x, y <= n 

*/