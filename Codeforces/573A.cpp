//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int n;
	int a;
	cin>>n;
	bool ok=1;
	scanf("%d",&a);
	while(a%2==0)
		a/=2;
	while(a%3==0)
		a/=3;
	int no=a;
	// cout<<a<<endl;
	for(int i=1;i<n;i++)
	{
		scanf("%d",&a);
		while(a%2==0)
			a/=2;
		while(a%3==0)
			a/=3;
		// cout<<a<<endl;
		if(a!=no)
		{
			ok=0;
			break;
		}
	}
	if(ok)
		cout<<"Yes";
	else
		cout<<"No";
}