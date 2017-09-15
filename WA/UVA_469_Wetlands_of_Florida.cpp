#define _CRT_SECURE_NO_DEPRECATE
#include "bits/stdc++.h"
using namespace std;
int max_row,max_col;
char land[101][101]={};
bool visited[101][101]={};
int bfs(int row,int col)
{
	if(row>max_row || col>max_col)return 0;
	if(row<1 || col<1)return 0;
	if(visited[row][col])return 0;
	if(land[row][col]=='W')
	{
		visited[row][col]=1;
		return 1+bfs(row+1,col)+bfs(row,col+1)+bfs(row-1,col)+bfs(row,col-1)+bfs(row+1,col+1)+bfs(row+1,col-1)+bfs(row-1,col+1)+bfs(row-1,col-1);
	}
	return 0;
}

int main()
{
	
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T;
	int r,c;
	cin>>T;
	string s,temp;
	max_row=0;
	while(T--)
	{
		while(cin>>s)
		{
			if(s[0]!='W' && s[0]!='L')
			{
				break;
			}
			max_row++;
			max_col=s.size();
			for(int i=1;i<=max_col;i++)
			{
				land[max_row][i]=s[i-1];
			}
		}
		stringstream st(s);
		st>>r;
		cin>>c;
		//cout<<"row "<<r<<" col "<<c<<endl;
		memset(visited,0,sizeof visited);
		cout<<bfs(r,c);
		while(cin>>s)
		{
			//cin>>s;
			if(s[0]=='W' || s[0]=='L')
			{
				max_row=1;
				max_col=s.size();
				for(int i=1;i<=max_col;i++)
				{
					land[max_row][i]=s[i-1];
				}	
				break;
			}
			if(s[0]>='1' && s[0]<='9')
			{
				stringstream st(s);
				st>>r;
				cin>>c;
				memset(visited,0,sizeof visited);
				cout<<endl<<bfs(r,c);
			}
		}
		if(T!=0)cout<<endl<<endl;
	}
	return 0;
}