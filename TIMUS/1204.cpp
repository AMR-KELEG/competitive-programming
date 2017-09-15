//AC
#include "bits/stdc++.h"
#define LIMIT 100000
using namespace std;

int modPow(int val,int p,int mod)
{
	if(p==0)
		return 1;
	if(p==1)
		return val;
	long long int ans = modPow(val,p>>1,mod);
	ans = (ans*ans) % mod;
	if (p%2)
		ans *= val;
	return ans % mod;
}

int inv(int val,int mod)
{
	return modPow(val,mod-2,mod);
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	std::vector<bool> isprime(LIMIT,1);
	isprime[0]=isprime[1]=0;
	std::vector<int> primes;
	for (int i=2;i<LIMIT;i++)
	{
		if (isprime[i])
		{
			primes.push_back(i);
			for (int mul = 2;mul*i<LIMIT;mul++)
				isprime[mul*i]=0;
		}
	}

	int t;

	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int p,q;
		for (auto pr:primes)
		{
			if(n%pr == 0)
			{
				p=n/pr;
				q=pr;
				break;
			}
		}
		// cout<<"Div: "<<p<<" "<<q<<endl;
		// for (long long int i=0;i<n;i++)
		// {
		// 	if ((i*(i-1))%n == 0)
		// 	{
		// 		cout<<i<<" ";
		// 	}
		// }
		// cout<<endl;
		std::vector<int> ans;
		ans.push_back(0);
		ans.push_back(1);
		ans.push_back(inv(p%q, q)*p);
		ans.push_back(inv(q%p, p)*q);
		sort(ans.begin(), ans.end());
		for(int i=0;i<ans.size();i++)
		{
			if(i)
				cout<<" ";
			cout<<ans[i];
		}
		cout<<endl;
		// cout<<endl;
	}	
}