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
	int i=1,j=n;
	int printed=0;
	while(printed<n)
	{
		cout<<i++<<" ";
		printed++;
		if(printed==n)
			break;
		cout<<j--<<" ";
		printed++;
	}
}