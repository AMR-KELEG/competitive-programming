#include "bits/stdc++.h"
using namespace std;
long long int gcd(long long int a,long long int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int a,b;
	cin>>a>>b;
	long long int count=0,temp,GCD;
	while(b!=0 && a!=0)
	{
		//cout<<"Before Working "<<a<<" "<<b<<endl;
		temp=a/b;
		a-=temp*b;
		count+=temp;
		//cout<<"P "<<temp<<endl;
		//cout<<a<<" "<<b<<endl;
		if(a==0)
			break;
		count+=(long long int) b/a;
		//cout<<"P "<<b/a<<endl;
		b= b-a*((long long int) b/a);
		//cout<<a<<" "<<b<<endl;
		GCD=gcd(max(a,b),min(a,b));
		//cout<<"Gcd is "<<GCD<<endl;
		a/=GCD;
		b/=GCD;
	}	
	cout<<count;
	
}