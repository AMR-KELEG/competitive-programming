#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int n,m;
	char col;
	bool iscol=0;
	cin>>n>>m;
	for(int r=0;r<n;r++)
	{
		for(int c=0;c<m;c++)
		{
			cin>>col;
			if(col =='C' || col=='M' || col=='Y')
			{
				iscol=1;
				r=n;
				break;
			}
		}
	}

	if(iscol)cout<<"#Color";
	else cout<<"#Black&White";
}