//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int n;

	cin>>n;
	for(long long int a=0;a*1234567<=n;a++)
	{
		for(long long int b=0;b*123456<=n;b++)
		{
			long long int no=(a*1234567)+(b*123456);
			if(n>=no && ((n-no)%1234)==0)
			{
				// cout<<a<<" "<<b<<endl;
				cout<<"YES";
				return 0;
			}
		}
	}	
	/*
	*/
	cout<<"NO";
	return 0;	
}