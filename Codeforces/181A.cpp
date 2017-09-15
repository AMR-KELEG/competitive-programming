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
	char ch;
	int ra=0,ca=0;
	for(int r=1;r<=n;r++)
	{
		for(int c=1;c<=m;c++)
		{
			cin>>ch;
			if(ch=='*')
			{
				ra^=r;
				ca^=c;
			}
		}
	}
	cout<<ra<<" "<<ca;
}