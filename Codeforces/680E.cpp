#include "bits/stdc++.h"
using namespace std;
std::vector<std::vector<char> > grid;
std::vector<std::vector<int> > countleft,countright,countup,countdown;
int n,k;
int findcount(char forb,int r,int c)
{
	int ans=0;
	if(forb=='u')
	{
		if(countdown[r][c])
		{
			ans+=countdown[r][c]+findcount('u',r+countdown[r][c],c);
		}
		if(countright[r][c])
		{
			ans+=countright[r][c]+findcount('l',r,c+countright[r][c]);
		}
		if(countleft[r][c])
		{
			ans+=countleft[r][c]+findcount('r',r,c-countleft[r][c]);
		}
		return ans;
	}
	if(forb=='d')
	{
		if(countright[r][c])
		{
			ans+=countright[r][c]+findcount('l',r,c+countright[r][c]);
		}
		if(countleft[r][c])
		{
			ans+=countleft[r][c]+findcount('r',r,c-countleft[r][c]);
		}
		if(countup[r][c])
		{
			ans+=countup[r][c]+findcount('d',r-countup[r][c],c);
		}
		return ans;
	}
	if(forb=='r')
	{
		if(countdown[r][c])
		{
			ans+=countdown[r][c]+findcount('u',r+countdown[r][c],c);
		}
		if(countleft[r][c])
		{
			ans+=countleft[r][c]+findcount('r',r,c-countleft[r][c]);
		}
		if(countup[r][c])
		{
			ans+=countup[r][c]+findcount('d',r-countup[r][c],c);
		}
		return ans;
	}
	if(forb=='l')
	{
		if(countdown[r][c])
		{
			ans+=countdown[r][c]+findcount('u',r+countdown[r][c],c);
		}
		if(countright[r][c])
		{
			ans+=countright[r][c]+findcount('l',r,c+countright[r][c]);
		}
		
		if(countup[r][c])
		{
			ans+=countup[r][c]+findcount('d',r-countup[r][c],c);
		}
		return ans;
	}
	return 0;
}
int findcount(int r,int c)
{
	if(k==1)
		return 1+countup[r][c]+countdown[r][c]+countright[r][c]+countleft[r][c];
	int ans=0;
	for(int row=r;row<r+k;row++)
	{
		// cout<<row<<endl;
		ans+=findcount('r',row,c);
		ans+=findcount('l',row,c+k-1);
		// ans+=countleft[row][c];
		// ans+=countright[row][c+k-1];

	}
	for(int col=c;col<c+k;col++)
	{
		ans+=findcount('d',r,col);
		ans+=findcount('u',r+k-1,col);
		
		// ans+=countup[r][col];
		// ans+=countdown[r+k-1][col];
	}
	/*
	*/
	return ans+(k*k);
}
int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	cin>>n>>k;
	grid=std::vector<std::vector<char> > (n+2,std::vector<char> (n+2,'X'));
	countleft=std::vector<std::vector<int> >(n+2,std::vector<int> (n+2,0));
	countright=std::vector<std::vector<int> >(n+2,std::vector<int> (n+2,0));
	countup=std::vector<std::vector<int> >(n+2,std::vector<int> (n+2,0));
	countdown=std::vector<std::vector<int> >(n+2,std::vector<int> (n+2,0));
	for(int r=1;r<=n;r++)
	{
		for(int c=1;c<=n;c++)
			cin>>grid[r][c];
	}
	for(int r=1;r<=n;r++)
	{
		for(int c=1,rc=n;c<=n;c++,rc--)
		{
			if(grid[r][c-1]=='.')
			{
				countleft[r][c]=1+countleft[r][c-1];
			}
			if(grid[r][rc+1]=='.')
			{
				countright[r][rc]=1+countright[r][rc+1];
			}
		}
	}

	for(int c=1;c<=n;c++)
	{
		for(int r=1,rr=n;r<=n;r++,rr--)
		{
			if(grid[r-1][c]=='.')
			{
				countup[r][c]=1+countup[r-1][c];
			}
			if(grid[rr+1][c]=='.')
			{
				countdown[rr][c]=1+countdown[rr+1][c];
			}
		}
	}
	cout<<findcount(1,1);




	
}
