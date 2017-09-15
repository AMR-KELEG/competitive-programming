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
	std::vector<int> cs(n+1,0);
	for(int i=0,val;i<n;i++)
	{
		cin>>val;
		cs[i+1]=cs[i]+val;
	}	
	int ans=0;
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			int curAns=cs[l-1]+(r+1-l-(cs[r]-cs[l-1]))+(cs[n]-cs[r]);
			ans=max(ans,curAns);
		}
	}
	cout<<ans;
}