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
	string dir;cin>>dir;
	std::vector<int> cor(n);
	for(int i=0;i<n;i++)
		cin>>cor[i];

	int mind=-1;
	for(int i=0;i<n-1;i++)
	{
		if(dir[i]=='R' && dir[i+1]=='L')
		{
			int d=cor[i+1]-cor[i];
			d=d/2;
			if(mind==-1)
				mind=d;
			else
				mind=min(mind,d);
		}
	}
	cout<<mind;
}