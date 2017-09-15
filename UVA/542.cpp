//AC
#include "bits/stdc++.h"
using namespace std;
double win[16][16];
bool solved[16][5]={};
double p[16][5]={};
int compe[16][16];
double solve(int i,int r)
{
	if(solved[i][r])
		return p[i][r];

	long double tem=0;
	for(int j=0;j<16;j++)
	{
		if(compe[i][j]==r)
		{
			tem+=(solve(j,r-1)*win[i][j]);
		}
	}
	solved[i][r]=1;
	return p[i][r]=tem*solve(i,r-1);

}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	std::vector<string> teams(16);
	for(int i=0;i<16;i++)
		cin>>teams[i];
	for(int i=0;i<16;i++)
	{
		for(int j=0;j<16;j++)
		{
			cin>>win[i][j];
			win[i][j]/=100;
		}
	}

	for(int i=0;i<16;i++)
	{
		p[i][0]=1;
		compe[i][i]=0;
		solved[i][0]=1;
	}
	
	int a[16][5]={
		{0,1,2,3,4},
		{1,0,2,3,4},
		
		{2,0,1,3,4},
		{2,1,0,3,4},
		
		{3,0,1,2,4},
		{3,1,0,2,4},
		
		{3,2,0,1,4},
		{3,2,1,0,4},
		
		{4,0,1,2,3},
		{4,1,0,2,3},
		
		{4,2,0,1,3},
		{4,2,1,0,3},
		
		{4,3,0,1,2},
		{4,3,1,0,2},
		
		{4,3,2,0,1},
		{4,3,2,1,0}
	};
	// each no is repeated 2^(i-1) times

	for(int i=0;i<16;i++)
	{
		int j=0;
		for(int it=0;it<5;it++)
		{
			int c=1<<(a[i][it]-1);
			if(a[i][it]==0)
				c=1;
			for(int co=0;co<c;co++)
			{
				compe[i][j++]=a[i][it];
				// cout<<compe[i][j-1]<<" ";
			}
		}
		// cout<<endl;
	}
	for(int i=0;i<16;i++)
	{
		solve(i,4);
	}
	for(int i=0;i<16;i++)
	{
		cout<<teams[i]<<string(11-teams[i].size(),' ')<<"p=";
		cout<<std::fixed<<setprecision(2)<<p[i][4]*100<<"%"<<endl;
	}

}