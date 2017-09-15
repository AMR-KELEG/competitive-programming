//1:18
//0:56
//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<pair<int,int>> fCars;
std::vector<int> stations;
int t;
bool isValid(int Carin)
{
	long long int rt=0;
	int cap=fCars[Carin].second;
	for(int i=0;i<stations.size()-1;i++)
	{
		long long int d=stations[i+1]-stations[i];
		if(cap>=2*d)
		{
			rt+=d;
		}
		else if(cap<d)
			return 0;
		else
			rt+=(3*d)-cap;
	}
	if(rt>t)
		return 0;
	return 1;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,k,s;
	scanf("%d%d%d%d",&n,&k,&s,&t);
	std::vector<pair<int,int>> Cars(n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&Cars[i].first,&Cars[i].second);
	}
	stations=std::vector<int>(k+2);
	stations[0]=0;
	stations[k+1]=s;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&stations[i]);
	}
	sort(stations.begin(), stations.end());
	int maxDis=0;
	for(int i=1;i<stations.size();i++)
	{
		if(stations[i]-stations[i-1]>maxDis)
			maxDis=stations[i]-stations[i-1];
	}
	sort(Cars.begin(), Cars.end());
	int minCap=0;
	for(int i=0;i<Cars.size();i++)
	{
		if(Cars[i].second>minCap && Cars[i].second>=maxDis)
		{
			//Check that i am the best of my price
			if(i+1<Cars.size())
			{
				while(i+1<Cars.size() &&(Cars[i+1].first==Cars[i].first))
				{
					i++;
				}
			}
			fCars.push_back(Cars[i]);
			// cout<<Cars[i].first<<" "<<Cars[i].second<<endl;
			minCap=Cars[i].second;
		}
	}
	int l=0,r=fCars.size()-1;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(isValid(mid))
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	if(l==r)
	{
		if(isValid(l))
			cout<<fCars[l].first;
		else
			cout<<-1;
	}
	else
	{
		cout<<-1;
	}
}