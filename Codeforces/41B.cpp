//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,initial,current,maxm;
	cin>>n>>initial;
	maxm=initial;
	std::vector<int> p(n);
	for(int i=0;i<n;i++)
		cin>>p[i];
	for(int b=0;b<n;b++)
	{
		current=initial/p[b];
		for(int s=b+1;s<n;s++)
			maxm=max(maxm,(current*p[s])+(initial%p[b]));
	}
	cout<<maxm;
}