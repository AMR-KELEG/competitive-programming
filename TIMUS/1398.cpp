//AC
#include "bits/stdc++.h"
using namespace std;
char wr,wc,br,bc; // Black moves r++ only
char dp[8][8][10]={};
char white_wins(int r,int c,int steps)
{
	//r and c are pos of white bishop
	if(steps+br>7)
		return 'b';
	if(dp[r][c][steps]!=0)
		return dp[r][c][steps];
	char ans = 'b';
	//generate all positions
	int dr[]={-1,-1,1,1};
	int dc[]={-1,1,1,-1};
	for(int i=0;i<4;i++)
	{
		for(int nr=r+dr[i],nc=c+dc[i]; (nr>=0 && nr<8) && (nc>=0 && nc<8);nr+=dr[i],nc+=dc[i])
		{
			// 1 Can kill
			if(nr == br+steps && nc ==bc)
				return dp[r][c][steps]='w';
			// 2 Blocks
			if(nr == br+steps+1 && nc==bc)
				ans = 'd';
			// 3 Killed 
			if(nr == br+steps+1 && abs(nc-bc)==1)
				continue;
			// 4 solve
			if(white_wins(nr,nc,steps+1)=='w')
				return dp[r][c][steps]='w';
			if(white_wins(nr,nc,steps+1)=='d')
				ans='d';
		}
	}
	return dp[r][c][steps]=ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>wc>>wr>>bc>>br;
	wr-='1';
	br-='1';
	wc-='a';
	bc-='a';
	wr=7-wr;
	br=7-br;
	if(white_wins(wr,wc,0)=='d')
	{
		cout<<"DRAW";
	}
	else if(white_wins(wr,wc,0)=='w')
	{
		cout<<"WHITE";
	}
	else
	{
		cout<<"BLACK";
	}
}