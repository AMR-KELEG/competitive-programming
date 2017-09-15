//AC
#include "bits/stdc++.h"
using namespace std;
bool canbereached[55][55]={};
int n,m;
char grid[55][55];
int counter;
void dfs(int r,int c,int rot,int up,int right)
{
	if(r>n || r<1)
		return;
	if(c>m || c<1)
		return;
	if(rot>1)
		return;
	if(canbereached[r][c])
		counter--;
	if(grid[r][c]=='W')
		return;

	canbereached[r][c]=1;
	counter++;
	int curup=0,curright=1;
	if(curup!=up || curright!=right)
	{
		dfs(r+curright,c+curup,rot+1,curup,curright);
	}
	else
	{
		dfs(r+curright,c+curup,rot,curup,curright);
	}
	curup=1,curright=0;
	if(curup!=up || curright!=right)
	{
		dfs(r+curright,c+curup,rot+1,curup,curright);
	}	
	else
	{
		dfs(r+curright,c+curup,rot,curup,curright);
	}

	curup=0,curright=-1;
	if(curup!=up || curright!=right)
	{
		dfs(r+curright,c+curup,rot+1,curup,curright);
	}
	else
	{
		dfs(r+curright,c+curup,rot,curup,curright);
	}

	curup=-1,curright=0;
	if(curup!=up || curright!=right)
	{
		dfs(r+curright,c+curup,rot+1,curup,curright);
	}
	else
	{
		dfs(r+curright,c+curup,rot,curup,curright);
	}
}


int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n>>m;
	std::vector<pair<int,int> > black;
	for(int r=1;r<=n;r++)
	{
		for(int c=1;c<=m;c++)
		{
			cin>>grid[r][c];
			if(grid[r][c]=='B')
			{
				black.push_back(pair<int,int>(r,c));
			}
		}
	}

	//Try dfs from each black node (2500 operation) recursive function 
	//carrying no of rotations and current direction
	//if all black nodes can be reached try another black node as a start
	//make a visited array an a counter
	bool can=true;
	for(int start=0;start<black.size();start++)
	{
		memset(canbereached,0,sizeof canbereached);
		counter=0;
		dfs(black[start].first,black[start].second,-1,-2,-2);
		//cout<<black[start].first<<" "<<black[start].second<<" "<<counter<<endl;
		if(counter<black.size())
		{
			can=0;
			break;
		}
	}	
	if(can)
		cout<<"YES";
	else 
		cout<<"NO";





}