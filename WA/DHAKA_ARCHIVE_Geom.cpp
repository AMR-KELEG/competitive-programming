#include "bits/stdc++.h"
using namespace std;
#define Range pair<long double, long double>
const long double PI = 2*acos(0);
long double a;
#define EPS 1e-9
void take_input(int m)
{
	long double aa,bb;
	while(m--)
	{
		scanf("%LF %LF",&aa, &bb);
	}
}

bool th_inside(long double th, const Range & r)
{
	if (th>= r.first && th<= r.second)
		return 1;
	th += 2*PI;
	if (th>= r.first && th<= r.second)
		return 1;
	return 0;
}

int find_n(long double r, long double th)
{
	long double val = r/a;
	val  -= th;
	val /= (2*PI);
	// cout<<val<<" ";
	if (abs(val-ceil(val))<EPS)
	{
		val = ceil(val)+EPS;
	}
	return (int)floor(val);
}

long double area(int n, const Range & r)
{
	if (n<0)
		return 0;
	long double c1 = (a*a)/6;
	long double th1 = r.first + ((2*PI*n));
	long double th2 = r.second + ((2*PI*n));
	long double ans = (th2*th2*th2) - (th1*th1*th1);
	return ans * c1;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif

	int T;
	scanf("%d", &T);
	for (int t=1;t<=T;t++)
	{
		scanf("%LF", &a);
		int n;
		scanf("%d", &n);
		if (n==0)
		{
			int m;
			scanf("%d", &m);
			if (m==0)
			{
				long double ans = 0;
				printf("Spiral %d: %0.4LF liters\n", t, ans);
				continue;
			}
			take_input(m);
			printf("Spiral %d: -1\n", t);
			continue;
		}
		std::vector<long double> th(n);
		for (int i=0;i<n;i++)
		{
			long double c;
			scanf("%LF", &c);
			th[i] = c;
		}
		sort(th.begin(), th.end());
		std::vector<pair<long double, long double> > ranges(n);
		for (int i=0;i<n-1;i++)
		{
			ranges[i] = {th[i], th[i+1]};
		}
		ranges[n-1] = {th[n-1], th[0] + 2*PI};
		std::vector<set<int> > N_in_region(n);
		int m;
		scanf("%d", &m);
		for (int i=0;i<m;i++)
		{
			long double ri,thi;
			scanf("%LF %LF", &ri, &thi);
			int N = find_n(ri, thi);
			for (int i=0;i<n;i++)
			{
				if (th_inside(thi, ranges[i]))
				{
					N_in_region[i].insert(N);
					break;
				}
			}
		}
		long double ans =0;
		for (int i=0;i<n;i++)
		{
			for (auto cur_n: N_in_region[i])
			{
				cout<<"Add "<<area(cur_n+1, ranges[i]) - area(cur_n, ranges[i])<<" "<<area(cur_n, ranges[i])<< endl;
				ans += area(cur_n+1, ranges[i]) - area(cur_n, ranges[i]);
			}
		}
		ans *=0.1;
		if ((ans < 0) || abs(ans)<EPS)
			ans = 0;
		printf("Spiral %d: %0.4LF liters\n", t,ans);
	}	
}

/*
2
1.00
2 0.43 0.78
1 11.06 0.63
1.00
0
2 17.05 0.55 17.59 0.74
*/