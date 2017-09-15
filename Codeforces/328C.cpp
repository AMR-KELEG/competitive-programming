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
	std::vector<long long int> a(n);
	long long int maxgames=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		maxgames=max(maxgames,a[i]);
	}	
	long long int super=0;
	for(int i=0;i<n;i++)
	{
		super+=maxgames-a[i];
	}
	
	if(super>=maxgames)
		cout<<maxgames;
	else
		cout<<std::fixed<<setprecision(0)<<super+ceil(1.0*(maxgames-super)*n / (n-1));
}