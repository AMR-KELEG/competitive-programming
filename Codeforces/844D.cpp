#include "bits/stdc++.h"
#define INF 1000000007
using namespace std;
std::vector<int> excluded;
set<int> vis; 
int n,start,x;
int get_indx()
{
	int val = rand()%n;
	val = val<<15;
	val ^= rand();
	val = (val%n)+1;
	while(vis.find(val)!= vis.end())
	{
		val = rand()%n;
		val = val<<15;
		val ^= rand();
		val = (val%n)+1;
	}
	vis.insert(val);
	return val;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	srand((unsigned)time(0));
	cin>>n>>start>>x;
	std::vector<int> next_indx(1000);
	std::vector<int> val(1000);
	std::vector<int> indx(1000);
	for(int i=0;i<min(n,1000);i++)
	{
		int ind = get_indx();
		cout<<"? "<<ind<<endl;
		fflush(stdout);	
		int v,next;
		cin>>v>>next;
		val[i]=v;
		indx[i] = ind;
		next_indx[i]=next;
	}

	int val_indx = -1;
	int value = -INF;
	int val_next = -1;
	for(int i=0;i<min(n,1000);i++)
	{
		if(val[i]<=x && val[i]>value)
		{
			value = val[i];
			val_indx = indx[i];
			val_next = next_indx[i];
		}
	}
	if(value == -INF)
	{
		value = INF;
		for(int i=0;i<min(n,1000);i++)
		{
			if(val[i]>=x && val[i]<value)
			{
				value = val[i];
			}
		}
		cout<<"! "<<value<<endl;
		fflush(stdout);
		return 0;
	}
	for(int i=0;i<999;i++)
	{
		if(value >= x)
		{
			cout<<"! "<<value<<endl;
			fflush(stdout);
			return 0;
		}
		if(value<x && val_next==-1)	
		{
			cout<<"! "<<-1<<endl;
			fflush(stdout);
			return 0;	
		}
		cout<<"? "<<val_next<<endl;
		fflush(stdout);
		cin>>value>>val_next;
	}
	if(value >= x)
	{
		cout<<"! "<<value<<endl;
		fflush(stdout);
		return 0;
	}
	cout<<"! "<<-1<<endl;
	fflush(stdout);
	return 0;
}

