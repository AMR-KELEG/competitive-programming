//AC
#include "bits/stdc++.h"
using namespace std;
#define EPS 1e-12
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	while (T--)
	{
		long double L,K,T1,T2,H;
		cin>>L>>K>>T1>>T2>>H;
		std::vector<long double> ans;
		if (H < L)
		{
			ans.push_back(H);
		}
		else if (H==L)
		{
			ans.push_back(H);
			// solve
			long double A = T1;
			long double B = - (H+K*(T1+T2));
			long double C = K*L;
			long double det = (B *B ) - (4 * A * C);
			if (abs(det) < EPS)
				det = 0;
			long double R = (-B + sqrt(det) ) / (2*A);
			ans.push_back(R * T1);
			long double R2 = (-B - sqrt(det) ) / (2*A);
			if (abs(R)>EPS)
			{
				long double T = L/R;
				if ((abs(T-T1)<EPS || T <=T1) && (R2*T1 >= H || abs(H- R2*T1) <=EPS))
				{
					// ok
					ans.push_back(R2 * T1);
				}
			}

		}
		else
		{
			// solve
			long double A = T1;
			long double B = - (H+K*(T1+T2));
			long double C = K*L;
			long double det = (B *B ) - (4 * A * C);
			if (abs(det) < EPS)
				det = 0;
			long double R = (-B + sqrt(det) ) / (2*A);
			ans.push_back(R * T1);
			long double R2 = (-B - sqrt(det) ) / (2*A);
			if (abs(R)>EPS)
			{
				long double T = L/R;
				if ((abs(T-T1)<EPS || T <=T1) && (R2*T1 >= H || abs(H- R2*T1) <=EPS))
				{
					// ok
					ans.push_back(R2 * T1);
				}
			}
		}
		if (ans.size()==1)
			ans.push_back(ans[0]);
		sort (ans.begin(), ans.end());
		printf("%0.6LF %0.6LF\n", ans[0]+EPS,ans[1]+EPS);
	}
}