//AC
#include "bits/stdc++.h"
using namespace std;
long long int q,no;
map<long long int,char> pos;
char solve(long long int n)
{
	if(pos.find(n)!=pos.end())
		return pos[n];
	if(n==2)
	{
		if(n==q)
			no=0;
		return pos[n]='n';
	}
	bool prime=1;
	
	for(long long int d=2;d*d<=n;d++)
	{
		if(n%d==0)
		{
			prime=0;
			if(solve(d)=='p')
			{
				if(n==q)
					no=d;
				return pos[n]='n';
			}
			if(solve(n/d)=='p')
			{
				if(n==q)
					no=n/d;
				return pos[n]='n';
			}
		}
	}
	if(prime)
	{
		if(n==q)
			no=0;
		return pos[n]='n';
	}
	else
		return pos[n]='p';
}
int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	cin>>q;
	if(solve(q)=='n')
	{
		cout<<"1\n"<<no;
	}
	else
		cout<<2;
}