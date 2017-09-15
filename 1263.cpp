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
	std::vector<int> votes(n+1,0);
	int v;
	for(int i=0;i<m;i++)
	{
		cin>>v;
		votes[v]++;
	}	
	for(int i=1;i<=n;i++)
	{
		cout<<fixed<<setprecision(2)<<(votes[i]*100.0)/m<<"%\n";
	}
}