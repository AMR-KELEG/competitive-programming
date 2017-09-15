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
	string s;
	int a,b;
	while(n--)
	{
		cin>>s>>a>>b;
		if(b>a && a>=2400)
		{
			cout<<"YES";
			return 0;
		}
	}	
	cout<<"NO";
	return 0;
}