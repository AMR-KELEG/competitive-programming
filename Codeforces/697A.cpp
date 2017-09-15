//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int t,s,x;
	cin>>t>>s>>x;
	if(x>=t && ((x-t)%s)==0 )
	{
		cout<<"YES";
	}
	else if(x>=t+1 && ((x-t-1)%s)==0 && ((x-t-1)/s)!=0)
	{
		cout<<"YES";
	}
	else
		cout<<"NO";
}