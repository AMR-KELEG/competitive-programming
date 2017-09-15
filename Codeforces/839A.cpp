//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,k;
	cin>>n>>k;
	int cur = 0;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		cur+=a;
		k-=min(8,cur);
		cur-=min(8,cur);
		if(k<=0)
		{
			cout<<i+1;
			return 0;
		}
	}	
	cout<<-1;
}