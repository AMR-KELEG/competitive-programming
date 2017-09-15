#include "bits/stdc++.h"
using namespace std;
int gcd(int a,int b)
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
	int n;
	cin>>n;
	int GCD=0;
	int a;
	int MAX=0;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		MAX=max(MAX,a);
		GCD=gcd(GCD,a);
	}	
	int no=(MAX/GCD)-n;
	if(no%2)
	{
		cout<<"Alice";
	}
	else
		cout<<"Bob";		
}