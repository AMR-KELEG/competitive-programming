//AC
#include "bits/stdc++.h"
#define LIMIT 4000001
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	std::vector<bool> is_prime (LIMIT, 1);
	is_prime [0]=is_prime[1]=0;
	std::vector<int> PHI(LIMIT,-1);
	std::vector<long long int> PHI_SUM(LIMIT,0);
	std::vector<int> largest_div(LIMIT,-1);
	PHI[0]= PHI[1]=0;
	for (int i=2;i<LIMIT;i++)
	{
		if (is_prime[i])
		{
			PHI[i] = i-1;
			for (int m = 2;m*i<LIMIT;m++)
			{
				is_prime[i*m] = 0;
				largest_div[i*m] = i;
			}
		}
	}
	for(int i=2;i<LIMIT;i++)
	{
		if (PHI[i] ==-1)
		{
			// do factoriztion
			PHI[i] = 1;
			int val = i;
			int cur_val = 1;
			int di = largest_div[i];
			if (val%di == 0)
			{
				while(val%di == 0)
				{
					val /=di;
					cur_val *=di;
				}
				PHI[i] = cur_val - (cur_val/di);
			}
			if (val>1)
			{
				PHI[i] *= PHI[val];		
			}
		}
		PHI_SUM [i]=PHI_SUM [i-1]+PHI[i];
	}
	int n;
	cin>>n;
	while(n)
	{
		long long int ans =0;
		for (int g=1;g<=n;g++)
		{
			int lim = n/g;
			ans+= g*(PHI_SUM[lim]);
			// cout<<g<<" "<<lim<<" "<<PHI_SUM[lim]<<endl;
		}
		cout<<ans<<endl;
		cin>>n;
	}	
}