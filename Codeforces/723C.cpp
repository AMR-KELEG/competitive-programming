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
	std::vector<int> a(n);
	std::vector<int> CountAtBand(m+1,0);
	int unassigned=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]<=m)
		{
			CountAtBand[a[i]]++;
		}
		else
			unassigned++;
	}
	
	priority_queue<pair<int,int> >q;//count in
	int maxPossVal=0;
	int minCount=100000;
	for(int i=1;i<=m;i++)
	{
		minCount=min(minCount,CountAtBand[i]);
		q.push({CountAtBand[i],i});
	}
	maxPossVal=minCount;
	//Loop from Bands performing 0 songs to bands performing n songs
	//count their no
	//count bands with songs>s+1
	//if you can reassign them -> ok
	int takeFromMax=0;
	for(int nSongs=0;nSongs<=n;nSongs++)
	{
		int countCurBand=0;
		int extra=0;
		for(int i=1;i<=m;i++)
		{
			if(CountAtBand[i]==nSongs)
				countCurBand++;
			else if(CountAtBand[i]>nSongs+1)
			{
				extra+=CountAtBand[i]-(nSongs+1);
			}
		}
		if(countCurBand==0)
			continue;
		// cout<<nSongs<<" "<<countCurBand<<" "<<unassigned+extra<<endl;
		if(countCurBand<=unassigned)
		{
			//
			unassigned-=countCurBand;
			for(int i=1;i<=m;i++)
			{
				if(CountAtBand[i]==nSongs)
					CountAtBand[i]++;
			}
			maxPossVal=nSongs+1;
		}
		else if(countCurBand<=unassigned+extra)
		{
			for(int i=1;i<=m;i++)
			{
				if(CountAtBand[i]==nSongs)
				{
					CountAtBand[i]++;
					if(unassigned)
					{
						unassigned--;	
						countCurBand--;
					}
				}
			}

			takeFromMax+=countCurBand;
			maxPossVal=nSongs+1;
		}
		else 
		{
			// cout<<nSongs-1<<endl;
			// maxPossVal=max(nSongs-1,0);
			break;
		}
	}

	while(takeFromMax>0)
	{
		pair<int,int>p=q.top();
		q.pop();
		p.first--;
		CountAtBand[p.second]--;
		q.push(p);
		takeFromMax--;
	}

	std::vector<bool> isAssigned(n,0);
	for(int i=0;i<n && unassigned>0;i++)
	{
		if(a[i]>m)
		{
			isAssigned[i]=1;
			unassigned--;
		}
	}

	for(int bandIn=1;bandIn<=m ;bandIn++)
	{
		for(int i=0;i<n && CountAtBand[bandIn]>0;i++)
		{
			if(a[i]==bandIn)
			{
				// cout<<"A "<<a[i]<<endl;
				CountAtBand[bandIn]--;
				isAssigned[i]=1;
			}
		}
		
	}
	int op=0;
	for(int bandIn=1;bandIn<=m ;bandIn++)
	{
		for(int i=0;i<n && CountAtBand[bandIn]>0;i++)
		{
			if(!isAssigned[i])
			{
				isAssigned[i]=1;
				CountAtBand[bandIn]--;
				a[i]=bandIn;
				op++;
			}
		}
	}

	// for(int i=1;i<=m;i++)
	// {
	// 	cout<<i<<" "<<CountAtBand[i]<<endl;
	// }
	cout<<maxPossVal<<" "<<op<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}