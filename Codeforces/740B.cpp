//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;
	std::vector<int> cs(n+1,0);
	for(int i=1,no;i<=n;i++)
	{
		cin>>no;
		cs[i]=cs[i-1]+no;
	}
	int l,r;
	long long int ans=0;
	for(int i=0;i<m;i++)
	{
		cin>>l>>r;
		if(cs[r]-cs[l-1]>0)
		{
			ans+=cs[r]-cs[l-1];
		}
	}
	cout<<ans;
}