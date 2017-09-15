//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<bool> isPrime(1000001,1);
vector<int>primes;
long double dp[1000001]={};
bool vis[1000001]={};
void prepare()
{
	for(int no=2;no<1000001;no++)
	{
		if(isPrime[no])
		{
			primes.push_back(no);
			for(int mul=2;mul*no<1000001;mul++)
				isPrime[mul*no]=0;
		}
	}
}

long double solve(int n)
{
	if(n==1)
		return 0;
	if(vis[n])
		return dp[n];
	// cout<<n<<endl;
	vis[n]=1;
	int Pt=lower_bound(primes.begin(), primes.end(),n+1)-primes.begin(),Pd=0;
	long double s=0;
	for(int no=2;no*no<=n;no++)
	{
		//Search for prime divisors here
		if(n%no==0)
		{
			if(isPrime[no])
			{
				Pd++;
				s+=(1+solve(n/no));
			}
			if(no*no<n && isPrime[n/no])
			{
				Pd++;
				s+=(1+solve(no));
			}
		}
		
	}
	if(isPrime[n])
	{
		Pd++;
		s++;
	}
	return dp[n]=(s+Pt-Pd)/Pd;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	prepare();
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n;
		cin>>n;
		cout<<fixed<<setprecision(10)<<"Case "<<t<<": "<<solve(n)<<"\n";
	}	
}