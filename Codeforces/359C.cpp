#include "bits/stdc++.h"
#define MOD (1000000007)
using namespace std;

int modPow(int x,int p)
{
	if(p==0)
		return 1;
	if(p==1)
		return x;
	long long int ans=modPow(x,p/2);
	ans=(ans*ans)%MOD;
	if(p%2)
		ans=(ans*x)%MOD;
	return ans;
}

long long inv(int n)
{
	return modPow(n,MOD-2);
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,x;
	cin>>n>>x;
	std::vector<int> a(n);
	long long int totalSum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		totalSum=(totalSum+a[i])%(MOD-1);
	}	
	cout<<(modPow(x,29)*2)%MOD<<endl;
	long long int den=modPow(x,totalSum)%MOD;

	long long int num=0;
	for(int i=0;i<n;i++)
	{
		long long int p=totalSum-a[i];
		cout<<"Power "<<p<<endl;
		while(p<0)
			p+=MOD-1;
		num=(num+modPow(x,p))%MOD;
	}
	cout<<num<<" "<<inv(den)*num<<endl;
	cout<<__gcd(inv(den),num);
}