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
	std::vector<int> count(n+6,0);
	int a,b,count1=0,count2=0;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		if(count[a]==0)
		{
			count1++;
		}
		else if(count[a]==1)
		{
			count1--;
			count2++;
		} 
		else if(count[a]==2)
		{
			count2--;
		}
		if(count[b]==0)
		{
			count1++;
		}
		else if(count[b]==1)
		{
			count1--;
			count2++;
		} 
		else if(count[b]==2)
		{
			count2--;
		}
		count[a]++;
		count[b]++;
	}
	if(count2==n-2 && count1==2)
	{
		cout<<"bus topology";
	}
	else if(count2==n)
	{
		cout<<"ring topology";
	}
	else if(count1==n-1)
	{
		cout<<"star topology";
	}
	else
	{
		cout<<"unknown topology";
	}

}