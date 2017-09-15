//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	if(n%10==0)
	{
		cout<<2;
	}	
	else
	{
		cout<<1<<endl<<(n%10);
	}
}