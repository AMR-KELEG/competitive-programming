//AC not happy
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,x;
	cin>>n;
	int nodivbyi[10000005]={};
	int counter[10000005]={};
	for(int i=0;i<n;i++)
	{
		cin>>x;
		counter[x]++;
	}	
	int vis[10000005]={};
	for(int i=2;i<=10000001;i++)
	{
		nodivbyi[i]+=nodivbyi[i-1];
		if(!vis[i])
		{
			for(int j=i;j<=10000000;j+=i)
			{
				vis[j]=1;
				nodivbyi[i]+=counter[i];
			}
		}
	}
	int m;
	cin>>m;
	int l,r;
	for(int i=0;i<m;i++)
	{
		cin>>l>>r;
		if(r>10000000)
		{
			r=10000000;
		}
		if(l>10000000)
		{
			l=10000001;
		}
		cout<<nodivbyi[r]-nodivbyi[l-1]<<endl;
	}
	/*
	*/
}