#include "bits/stdc++.h"
using namespace std;
int visited[1001][1001]={};
int r,c;
int max_distance(int row,int col)
{

	if(row>r || col>c || row<1 || col<1)
	{
		return -1;
	}
	if(visited[row][col]==0)
	{
		visited[row][col]=1;
		return 1+max(max(max_distance(row+1,col),max_distance(row,col+1)),max(max_distance(row-1,col),max_distance(row,col-1)));
	}
	return -1;
}
int main()
{	
	int T;
	char sq;
	
	cin>>T;
	while(T--)
	{
		int len=0;
		memset(visited,0,sizeof visited);
		cin>>c>>r;
		for(int  i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
				cin>>sq;
				if(sq=='#')
				{
					visited[i][c]=1;
				}
			}
		}
		for(int  i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
					len=max(len,max_distance(i,j));
			}
		}
		cout<<"Maximum rope length is "<<len<<"."<<endl;
	}
	return 0;
}