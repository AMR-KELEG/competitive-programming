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
	std::vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	int l=-1,r=-1;

	for(int i=1;i<=n;i++)
	{
		if(a[i-1]!=i)
		{
			if(l!=-1)
			{
				l=r=0;
				break;
			}
			int val=i;
			l=i;
			r=a[i-1];
			for(int j=a[i-1];j>=val && i<=n;j--,i++)
			{
				if(a[i-1]!=j)
				{
					l=r=0;
					break;
				}
			}
		}
	}	
	if(l==0 && r==0)
	{
		cout<<"0 0";
	}
	else if(l==-1 && r==-1)
	{
		cout<<"0 0";
	}
	else
		cout<<l<<" "<<r;
}