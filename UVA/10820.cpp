// AC
// 2:35
// 2:41
#include "bits/stdc++.h"
#define LIMIT 50001
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	std::vector<bool> is_prime(LIMIT,1);
	std::vector<int> largest_div(LIMIT,-1);
	std::vector<int> PHI(LIMIT,-1);
	std::vector<long long int> PHI_SUM(LIMIT,0);
	is_prime[0]=is_prime[1]=0;
	PHI[0]=PHI[1]=0;
	for (int i=2;i<LIMIT;i++)
	{
		if(is_prime[i])
		{
			PHI[i] = i-1;
			for (int m=2;m*i<LIMIT;m++)
			{
				is_prime[m*i] = 0;
				largest_div[m*i] = i;
			}
		}
	}
	for (int i=1;i<LIMIT;i++)
	{
		if (PHI[i] == -1)
		{
			int di =1;
			int val = i;
			while(val%largest_div[i] == 0)
			{
				val/= largest_div[i];
				di*= largest_div[i];
			} 
			PHI[i] = di - (di/largest_div[i]);
			if (val>1)
			{
				PHI[i] *= PHI[val];
			}
		}
		PHI_SUM[i] = PHI_SUM[i-1] +PHI[i]; 
	}

	int n;
	cin>>n;
	while(n)
	{
		long long int ans = PHI_SUM[n];
		ans = 2*ans + 1;
		cout<<ans<<endl;
 		cin>>n;
	}
}