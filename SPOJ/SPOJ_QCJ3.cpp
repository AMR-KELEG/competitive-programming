//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--)	
	{
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int no;cin>>no;
			if(no%2)
				ans^=i;
		}
		if(ans==0)
			cout<<"Hanks Wins\n";
		else
			cout<<"Tom Wins\n";
	}
}