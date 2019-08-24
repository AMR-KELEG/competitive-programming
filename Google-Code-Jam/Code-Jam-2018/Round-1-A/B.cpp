// Passes only the small input - TLE on large input
#include <bits/stdc++.h>
using namespace std;

int R,C,B;
std::vector<int> bits_per_cashier;
std::vector<int> M;
std::vector<int> S;
std::vector<int> P;
long long int solve(int rem, int rem_rob, int cashier_i=0)
{
	if (rem_rob<0)
		return 1e18;
	if(cashier_i==C)
	{
		if (rem!=0)
			return 1e18;
		long long int ans = 1e18;
		// check the constraints
		for (int i=0;i<C;i++)
		{
			if (bits_per_cashier[i]>M[i])
				return ans;
		}
		ans = 0;
		// find the time
		for (int i=0;i<C;i++)
		{
			if (bits_per_cashier[i])
				ans = max(ans, P[i] + bits_per_cashier[i]*((long long int)S[i]));
		}
		return ans;
	}
	bits_per_cashier[cashier_i] = 0;
	long long int ans = solve(rem, rem_rob, cashier_i+1);
	for(int i=1;i<=rem;i++)
	{
		bits_per_cashier[cashier_i] = i;
		ans= min(ans, solve(rem-i, rem_rob-1, cashier_i+1));
	}
	return ans;
}

int main()
{
	freopen("B-input", "r", stdin);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		cin>>R>>B>>C;
		bits_per_cashier = std::vector<int> (C);
		M = std::vector<int> (C);
		P = std::vector<int> (C);
		S = std::vector<int> (C);
		for(int i=0;i<C;i++)
		{
			cin>>M[i]>>S[i]>>P[i];
		}
		printf("Case #%d: %lld\n", t, solve(B, R));
	}
	return 0;
}
