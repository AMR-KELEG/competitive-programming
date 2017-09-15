#include "bits/stdc++.h"
using namespace std;
int n;
std::vector<int> a;
std::vector<int> dp;
std::vector<std::vector<int> > divisors;
map<int,std::vector<int> > indexmp;
void find_div(int i,int v)
{
	int val=v;
	if(v==1)
		return;
	if(v%2==0)
	{
		v/=2;
		divisors[i].push_back(2);
		indexmp[2].push_back(i);
	}
	while(v%2==0)
	{
		v/=2;
	}
	for(int it=3;it*it<=v;it+=2)
	{
		if(v%it==0)
		{
			v/=it;
			divisors[i].push_back(it);
			indexmp[it].push_back(i);
		}
		while(v%it==0)
			v/=it;
	}
	if(v>1)
	{
		divisors[i].push_back(v);
		indexmp[v].push_back(i);
	}
}
int solve(int i)
{
	if(i==n-1)
	{		
		return 1;
	}
	if(dp[i]!=-1)
		return dp[i];
	int ans=1;
	// find index of next element for each divisor
	for(int it=0;it<divisors[i].size();it++)
	{
		vector<int>::iterator nextind=upper_bound(indexmp[divisors[i][it]].begin(),indexmp[divisors[i][it]].end(),i); 
		//vector to search in - if end -> continue 
		if(nextind-indexmp[divisors[i][it]].end()==0)
		{
			continue;
		}
		int nex=nextind-indexmp[divisors[i][it]].begin();
		ans=max(ans,1+solve(indexmp[divisors[i][it]][nex]));
	}
	return dp[i]=ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n;
	a=std::vector<int> (n);
	dp=std::vector<int> (n,-1);
	divisors=std::vector<vector<int> > (n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		find_div(i,a[i]);
	}
	int ans=1;
	for(int i=0;i<n;i++)
		ans=max(ans,solve(i));
	cout<<ans;
}