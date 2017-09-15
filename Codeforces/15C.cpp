//AC
#include "bits/stdc++.h"
using namespace std;
long long int xorval(long long int a)
{
	if(a%4==0)
		return a;
	if(a%4==1)
		return 1;
	if(a%4==2)
		return a+1;
	return 0;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int ans=0;
	int n;
	cin>>n;
	long long int x,m;
	for(int i=0;i<n;i++)
	{
		cin>>x>>m;
		ans^=xorval(x+m-1);
		ans^=xorval(x-1);
	}	
	if(ans)
		cout<<"tolik";
	else
		cout<<"bolik";
}