#include "bits/stdc++.h"
using namespace std;
short lcs[1005]={};//size of n
short countAtI[1005][1005]={};
short curcount[1005]={};//no -> Val 
int n,k;
void findlcs(int i)
{
	bool add=0;
	for(int j=0;j<=n;j++)
	{
		if(countAtI[i][j]>0 && countAtI[i][j]+curcount[j]==k)
		{
			add=1;
		}
		curcount[j]+=countAtI[i][j];
	}
	lcs[i]=lcs[i-1]+add;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n>>k;
	int no;
	for(int i=0;i<k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>no;
			countAtI[j][no]++;
		}
	}
	for(int i=1;i<=n;i++)
		findlcs(i);
	cout<<lcs[n];
}