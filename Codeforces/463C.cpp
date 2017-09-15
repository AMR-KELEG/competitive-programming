//AC
#include "bits/stdc++.h"
using namespace std;
int n;
vector<long long int >down,up;
std::vector<std::vector<long long int> > grid(n,std::vector<long long int> (n));
long long int findup(int r,int c)
{
	if(up[c+r]!=-1)
		return up[c+r];
	long long int sum=0;
	for(int i=0;r-i>=0 && i+c<n;i++)
	{
		//cout<<grid[r-i][c+i]<<endl;
		sum+=grid[r-i][c+i];
	}
	for(int i=1;r+i<n && c-i>=0;i++)
	{
		//cout<<grid[r+i][c-i]<<endl;
		sum+=grid[r+i][c-i];
	}
	
	return up[c+r]=sum;
}
long long int finddown(int r,int c)
{
	if(down[n-1+c-r]!=-1)
		return down[n-1+c-r];
	long long int sum=0;
	for(int i=0;i+r<n && c+i<n;i++)
	{
		sum+=grid[r+i][c+i];
	}
	for(int i=1;r-i>=0 && c-i>=0;i++)
	{
		sum+=grid[r-i][c-i];
	}
	return down[n-1+c-r]=sum;
}
int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	cin>>n;
	grid=vector<std::vector<long long int> > (n,std::vector<long long int> (n));
	down=std::vector<long long int> ((2*n)-1,-1);
	up=std::vector<long long int> ((2*n)-1,-1);
	for(int i=0;i<n;i++)
	{
		for(int c=0;c<n;c++)
		{
			cin>>grid[i][c];
		}	
	}
	long long int maxoc=0,maxor=1,maxov=0;
	long long int maxec=0,maxer=0,maxev=0;
	for(int r=0;r<n;r++)
	{
		for(int c=0;c<n;c++)
		{
			//cout<<r<<" "<<c<<" "<<findup(r,c)<<" "<<finddown(r,c)<<endl;
			if((r+c)%2==0)
			{
				if(finddown(r,c)+findup(r,c)-grid[r][c]>maxev)
				{
					maxev=finddown(r,c)+findup(r,c)-grid[r][c];
					maxer=r;
					maxec=c;
					//cout<<"e "<<maxev<<" "<<maxer<<" "<<maxec<<endl;
				}
			}
			else
			{
				if(finddown(r,c)+findup(r,c)-grid[r][c]>maxov)
				{
					maxov=finddown(r,c)+findup(r,c)-grid[r][c];
					maxor=r;
					maxoc=c;
					//cout<<"o "<<maxov<<" "<<maxor<<" "<<maxoc<<endl;
				}
			}
		}
	}
	/*
	cout<<findup(1,1)<<endl<<endl;
	cout<<finddown(1,1)<<endl<<endl;
	cout<<findup(1,1)+finddown(1,1)-grid[1][1];

	*/
	cout<<maxev+maxov<<endl;

	cout<<maxer+1<<" "<<maxec+1<<" ";
	cout<<maxor+1<<" "<<maxoc+1;
	/*
	*/
}