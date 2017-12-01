//AC
#include "bits/stdc++.h"
using namespace std;

int len(long long int val)
{
	if(val==0)
		return 1;
	int ans=0;
	while(val)
	{
		ans++;
		val/=10;
	}
	return ans;
}
class No
{
private:
	long long val;
	long long num;
	long long den;
public:
	No()
	{
		val=0;num=0;den=1;
	}
	No(long long nu,long long de)
	{
		val=nu/de;
		num=nu%de;
		den=de;
	}
	void add(long long int nu,long long int de)
	{
		val+=(nu/de);
		nu%=de;
		long long int nn=(num*de)+(den*nu);
		long long int nd=de*den;
		val+=(nn/nd);
		nn%=nd;
		int GCD=__gcd(nn,nd);
		num=nn/GCD;
		den=nd/GCD;
	}
	void print()
	{
		if(num==0)
			printf("%d\n", val);
		else
		{
			int length=len(val);
			cout<<string(length+1,' ')<<num<<"\n";
			cout<<val<<" "<<string(len(den),'-')<<"\n";
			cout<<string(length+1,' ')<<den<<"\n";
		}
	}
};

No dp[34][34]={};
bool vis[34][34]={};
No solve(int n,int rem)
{
	if(rem==0)
		return No();
	if(vis[n][rem])
		return dp[n][rem];
	vis[n][rem]=1;
	//Solve and memorize
	No ans=solve(n,rem-1);
	ans.add(n,rem);
	return dp[n][rem]=ans;
}

int main()
{
	int n;
	while(cin>>n)
	{
		solve(n,n);
		dp[n][n].print();
	}
}