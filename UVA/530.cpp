#include "bits/stdc++.h"
#define INF 10000
using namespace std;
int R,C;
std::vector<string> grid;
int startR,startC,tarR,tarC;
pair<int,int> dp [22][22][22][22];
int vis[22][22][22][22]={};
int test =0;

bool free_move(int r,int c,int offR,int offC,int boxR,int boxC)
{
	int r1=r+offR;
	int c1=c+offC;
	
	if(boxR==r1 && boxC==c1)
	{
		return 0;
	}
	return grid[r1][c1]=='.';
}

bool push_move(int r,int c,int offR,int offC,int boxR,int boxC)
{
	int r1=r+offR;
	int c1=c+offC;
	int r2=r+2*offR;
	int c2=c+2*offC;
	
	if(boxR==r1 && boxC==c1)
	{
		// The next one should be free
		return grid[r2][c2]=='.';		
	}
	return 0;
}

pair<int,int> solve(int boxR,int boxC,int r,int c)
{
	// cout<<"BOX "<<boxR<<" "<<boxC<<endl;
	// cout<<"ME "<<r<<" "<<c<<endl;
	if(boxR==tarR && boxC==tarC)
	{
		return {0,0};
	}
	if(vis[boxR][boxC][r][c] == test)
		return dp[boxR][boxC][r][c];
	vis[boxR][boxC][r][c] = test;
	pair<int,int> ans ={INF,INF};
	dp[boxR][boxC][r][c] =ans;
	int dr[]={0,-1,0,1};
	int dc[]={1,0,-1,0};
	for(int i=0;i<4;i++)
	{
		if(free_move(r,c,dr[i],dc[i],boxR,boxC))
		{
			pair<int,int>curAns = solve(boxR,boxC,r+dr[i],c+dc[i]);
			curAns.second++;
			if(curAns.first<ans.first || (curAns.first==ans.first && curAns.second<ans.second) )
			{
				ans=curAns;
			}
		}
		if(push_move(r,c,dr[i],dc[i],boxR,boxC))
		{
			pair<int,int>curAns = solve(boxR+dr[i],boxC+dc[i],r+dr[i],c+dc[i]);
			curAns.first++;
			if(curAns.first<ans.first || (curAns.first==ans.first && curAns.second<ans.second) )
			{
				ans=curAns;
			}			
		}
	}
	if(ans.first>=INF || ans.second>=INF)
		ans={INF,INF};
	return dp[boxR][boxC][r][c] =ans;
}

void print_ans(int boxR,int boxC,int r,int c)
{
	if(boxR==tarR && boxC==tarC)
	{
		return ;
	}
	
	// vis[boxR][boxC][r][c] = test;
	pair<int,int> ans =solve(boxR,boxC,r,c);
	int dr[]={0,-1,0,1};
	int dc[]={1,0,-1,0};
	string low = "enws";
	string upp = "ENWS";
	for(int i=0;i<4;i++)
	{
		if(free_move(r,c,dr[i],dc[i],boxR,boxC))
		{
			pair<int,int>curAns = solve(boxR,boxC,r+dr[i],c+dc[i]);
			curAns.second++;
			if(curAns.first==ans.first && curAns.second==ans.second )
			{
				cout<<low[i];
				print_ans(boxR,boxC,r+dr[i],c+dc[i]);
				return ;
			}
		}
		if(push_move(r,c,dr[i],dc[i],boxR,boxC))
		{
			pair<int,int>curAns = solve(boxR+dr[i],boxC+dc[i],r+dr[i],c+dc[i]);
			curAns.first++;
			if(curAns.first==ans.first && curAns.second==ans.second )
			{
				cout<<upp[i];
				print_ans(boxR+dr[i],boxC+dc[i],r+dr[i],c+dc[i]);
				return ;
			}			
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>R>>C;
	while(R!=0 || C!=0)
	{
		int Br,bC;
		test++;
		grid=std::vector<string> (R+2,string(C+2,'#'));
		for(int r=1;r<=R;r++)
		{
			for(int c=1;c<=C;c++)
			{
				cin>>grid[r][c];
				if(grid[r][c]=='S')
				{
					startR=r;
					startC=c;
				}
				if(grid[r][c]=='T')
				{
					tarR=r;
					tarC=c;
				}
				if(grid[r][c]=='B')
				{
					Br=r;
					bC=c;
				}
				if(grid[r][c]!='#')
					grid[r][c]='.';
				// cout<<grid[r][c];
			}
			// cout<<endl;
		}
		cout<<"Maze #"<<test<<endl;
		// cout<<"EE\n";
		// cout<<startR<<" "<<startC<<" "<<Br<<" "<<bC<<endl;
		// print_ans(3,4,2,4);
		// cout<<endl;
		if(solve(Br,bC,startR,startC).first==INF)
		{
			cout<<"Impossible.\n\n";
		}
		else
		{
			// cout<<"Pushes "<<solve(Br,bC,startR,startC).first<<endl;	
			print_ans(Br,bC,startR,startC);
			cout<<"\n\n";
		}
		cin>>R>>C;
	}	
}