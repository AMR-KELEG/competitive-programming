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
	std::vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	unordered_map<int,int>mp;
	int val;
	for(int f=0;f<n;f++)
	{
		for(int s=0;s<n;s++)
		{
			val=v[f]+v[s];
			for(int t=0;t<n;t++)
			{
				if(v[t]==0)
					continue;
				mp[(val)*v[t]]++;
			}
		}
	}	
	long long int ans=0;
	for(int f=0;f<n;f++)
	{
		for(int s=0;s<n;s++)
		{
			val=v[f]*v[s];
			for(int t=0;t<n;t++)
			{
				ans+=mp[(val)+v[t]];
			}
		}
	}
	cout<<ans;
}

// You are given a set S of integers between -30000 and 30000 (inclusive).

// Find the total number of sextuples  that satisfy: 



 

// Input

// The first line contains integer N (1 ≤ N ≤ 100), the size of a set S.

// Elements of S are given in the next N lines, one integer per line. Given numbers will be distinct.

// Output
// Output the total number of plausible sextuples.
// (6*10^4)*(3*10^4)=1.8*10^9