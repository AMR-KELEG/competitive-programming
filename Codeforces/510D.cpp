#include "bits/stdc++.h"
using namespace std;
#define inf 1000000000
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	std::vector<pair<int,int> > v(n);//jump cost	
	for(int i=0;i<n;i++)
	{
		cin>>v[i].first;
	}
	for(int i=0;i<n;i++)
	{
		cin>>v[i].second;
	}
	sort(v.rbegin(), v.rend());
	std::vector<long long int> CuJumps(n+1);
	CuJumps[n]=0;
	for(int i=n-1;i>=0;i--)
	{
		CuJumps[i]=CuJumps[i+1]+v[i].first;
		// cout<<i<<" "<<CuJumps[i]<<endl;
	}
	int minCost=inf;
	queue<pair<long long int,pair<int,int> > >q;
	q.push({0,{0,0}});
	int state=0;
	while(!q.empty())
	{
		long long int cursum=q.front().first;
		int cost=q.front().second.first;
		int indx=q.front().second.second;
		q.pop();
		state++;
		// cout<<indx<<" "<<cursum<<" "<<cost<<endl;
		if(cost>minCost)
		{
			continue;
		}
		if(cursum==1 || cursum==-1)
		{
			minCost=min(minCost,cost);
			continue;
		}
		if(indx==n)
			continue;
		if(cursum>0 && cursum-CuJumps[indx]>1)
		{
			continue;
		}
		if(cursum<0 && cursum+CuJumps[indx]<1)
		{
			continue;
		}
		q.push({cursum+v[indx].first,{cost+v[indx].second,indx+1}});
		q.push({cursum-v[indx].first,{cost+v[indx].second,indx+1}});
		q.push({cursum,{cost,indx+1}});
	}
	cout<<state<<endl;
	if(minCost==inf)
		cout<<-1;
	else
		cout<<minCost;
}