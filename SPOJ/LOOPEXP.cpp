/* AC
- The position of the maximum number is important.
- Linearity of expectation.
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	long double dp[100001];
	dp[0] = 0;
	long double ans = 0;
	for (int n=1;n<=100000;n++)
	{
		dp [n] = (ans/n) + 1;
		ans += dp[n];
	}

	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<fixed<<setprecision(9)<<dp[n]<<"\n";
	}
}
