// AC
#include "bits/stdc++.h"
using namespace std;

bool solve(long long int n, long long int d1, 
		long long int d2, long long int k)
{
	long long int f = 2 * d1 + d2 + k;
	long long int s = -d1 + d2 + k;
	long long int t = -d1 -2 * d2 + k;
	if (f<0 || s<0 || t<0)
		return 0;
	if (f%3 || s%3 || t%3)
		return 0;
	f/=3;
	s/=3;
	t/=3;
	long long int req_g = n/3;
	return f<=req_g && s<=req_g && t<=req_g;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		long long int n,k,d1,d2;
		cin>>n>>k>>d1>>d2;
		if (n % 3 != 0)
			printf("no\n");
		else if (solve(n,-d1,-d2,k) ||
			solve(n,-d1,d2,k) ||
			solve(n,d1,-d2,k) ||
			solve(n,d1,d2,k))
			printf("yes\n");
		else
			printf("no\n");
	}
}