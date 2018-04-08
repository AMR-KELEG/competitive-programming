#include "bits/stdc++.h"
using namespace std;
int R,C;
std::vector<std::vector<char> > grid;
std::vector<std::vector<short> > beams;
std::vector<std::vector<short> > canServe;
std::vector<std::vector<bool> > done;
bool ans;

bool valid()
{
	for(int r=0;r<R;r++)
	{
		for(int c=0;c<C;c++)
		{
			if(grid[r][c]=='.' && beams[r][c]==0 && canServe[r][c]==0)
				return 0;
		}
	}
	return 1;
}

void solve(int r=0,int c=0,bool forw=1)
{
	// for(int rr=0;rr<R;rr++)
	// {
	// 	for(int cc=0;cc<C;cc++)
	// 	{
	// 		cout<<grid[rr][cc];
	// 	}
	// 	cout<<endl;
	// }
	// cout<<endl<<endl;
	if(r==R && c==0)
	{
		//Done
		if(valid())
		{
			ans=1;
			return ;
		}
		else
		{
			solve(r-1,C-1,0);
			return ;
		}
	}
	if(c==C)
	{
		solve(r+1,0);
		return;
	}
	if(c==-1)
	{
		solve(r-1,C-1,0);
		return;
	}
	if(r==-1)
	{
		ans=0;
		return;
	}
	// cout<<r<<" "<<c<<endl;
	// cout<<grid[r][c]<<endl;
	if(grid[r][c]=='#' || grid[r][c]=='.' || done[r][c])
	{
		if(forw)
			solve(r,c+1);
		else
			solve(r,c-1,0);
		return ;
	}
	// you can make 2 choices 1 == - 2 == | 
	if(grid[r][c]=='2')
	{
		grid[r][c]='-';
		// for same col remove beam
		for(int r1=r-1;r1>=0;r1--)
		{
			if(grid[r1][c]!='.')
				break;
			beams[r1][c]--;
			canServe[r1][c]++;
		}
		for(int r1=r+1;r1<R;r1++)
		{
			if(grid[r1][c]!='.')
				break;
			beams[r1][c]--;
			canServe[r1][c]++;
		}
		// for same row
		for(int c1=c-1;c1>=0;c1--)
		{
			if(grid[r][c1]!='.')
				break;
			canServe[r][c1]++;
		}
		for(int c1=c+1;c1<C;c1++)
		{
			if(grid[r][c1]!='.')
				break;
			canServe[r][c1]++;
		}
		solve(r,c-1,0);
		return ;
	}
	if(grid[r][c]=='1')
	{
		//for same row remove beam
		for(int c1=c-1;c1>=0;c1--)
		{
			if(grid[r][c1]!='.')
				break;
			beams[r][c1]--;
		}
		for(int c1=c+1;c1<C;c1++)
		{
			if(grid[r][c1]!='.')
				break;
			beams[r][c1]--;
		}
		// for same col
		for(int r1=r-1;r1>=0;r1--)
		{
			if(grid[r1][c]!='.')
				break;
			beams[r1][c]++;
		}
		for(int r1=r+1;r1<R;r1++)
		{
			if(grid[r1][c]!='.')
				break;
			beams[r1][c]++;
		}
		grid[r][c]='2';
		if(!valid())
		{
			solve(r,c,0);
			return;
		}
		solve(r,c+1);
		return ;
	}
	grid[r][c]='1';
	// for same row
	for(int c1=c-1;c1>=0;c1--)
	{
		if(grid[r][c1]!='.')
			break;
		beams[r][c1]++;
		canServe[r][c1]--;
	}
	for(int c1=c+1;c1<C;c1++)
	{
		if(grid[r][c1]!='.')
			break;
		beams[r][c1]++;
		canServe[r][c1]--;
	}
	// for same col
	for(int r1=r-1;r1>=0;r1--)
	{
		if(grid[r1][c]!='.')
			break;
		canServe[r1][c]--;
	}
	for(int r1=r+1;r1<R;r1++)
	{
		if(grid[r1][c]!='.')
			break;
		canServe[r1][c]--;
	}
	if(!valid())
	{
		solve(r,c,0);
		return;
	}
	solve(r,c+1);
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("C-small-attempt1.in","r",stdin);
	// freopen("in.txt","r",stdin);
		freopen("C-small-attempt1.out","w",stdout);
	#endif
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		cin>>R>>C;
		grid=std::vector<std::vector<char> >(R,std::vector<char> (C));
		beams=std::vector<std::vector<short> >(R,std::vector<short> (C));
		canServe=std::vector<std::vector<short> >(R,std::vector<short> (C));
		done=std::vector<std::vector<bool> >(R,std::vector<bool> (C,0));
		ans=1;
		for(int r=0;r<R;r++)
			for(int c=0;c<C;c++)
				cin>>grid[r][c];
		for(int r=0;r<R;r++)
		{
			for(int c=0;c<C;c++)
			{
				if(grid[r][c]=='-' || grid[r][c]=='|')
				{
					//search in same r
					int sameR=-1;
					for(int c1=c+1;c1<C;c1++)
					{
						if(grid[r][c1]=='#')
							break;
						if(grid[r][c1]!='.')
						{
							sameR=c1;
							break;
						}
					}
					for(int c1=c-1;c1>=0 && sameR==-1;c1--)
					{
						if(grid[r][c1]=='#')
							break;
						if(grid[r][c1]!='.')
						{
							sameR=c1;
							break;
						}
					}
					int sameC=-1;
					for(int r1=r+1;r1<R;r1++)
					{
						if(grid[r1][c]=='#')
							break;
						if(grid[r1][c]!='.')
						{
							sameC=r1;
							break;
						}
					}
					for(int r1=r-1;r1>=0 && sameC==-1;r1--)
					{
						if(grid[r1][c]=='#')
							break;
						if(grid[r1][c]!='.')
						{
							sameC=r1;
							break;
						}
					}
					if(sameR!=-1 && sameC!=-1)
					{
						//NO ANSWER
						ans=0;
						r=R;
						break;
					}
					if(sameR!=-1)
					{
						if((done[r][c] && grid[r][c]!='|') || (done[r][sameR] && grid[r][sameR]!='|'))
						{
							ans=0;
							r=R;
							break;
						}
						grid[r][c]='|';
						grid[r][sameR]='|';
						done[r][c]=1;
						done[r][sameR]=1;
					}
					if(sameC!=-1)
					{
						if((done[r][c] && grid[r][c]!='-') || (done[sameC][c] && grid[sameC][c]!='-'))
						{
							ans=0;
							r=R;
							break;
						}
						grid[r][c]='-';
						grid[sameC][c]='-';
						done[r][c]=1;
						done[sameC][c]=1;
					}
				}
			}
		}

		if(ans)
		{
			//update canServe and beams
			for(int r=0;r<R;r++)
			{
				for(int c=0;c<C;c++)
				{
					if(done[r][c])
					{
						if(grid[r][c]=='-')
						{
							for(int c1=c+1;c1<C;c1++)
							{
								if(grid[r][c1]!='.')
									break;
								beams[r][c1]++;
							}
							for(int c1=c-1;c1>=0;c1--)
							{
								if(grid[r][c1]!='.')
									break;
								beams[r][c1]++;
							}
						}
						
						else if(grid[r][c]=='|')
						{
							for(int r1=r+1;r1<R;r1++)
							{
								if(grid[r1][c]!='.')
									break;
								beams[r1][c]++;
							}
							for(int r1=r-1;r1>=0;r1--)
							{
								if(grid[r1][c]!='.')
									break;
								beams[r1][c]++;
							}
						}	
					}
					else if(grid[r][c]!='.' && grid[r][c]!='#')
					{
						for(int c1=c+1;c1<C;c1++)
						{
							if(grid[r][c1]!='.')
								break;
							canServe[r][c1]++;
						}
						for(int c1=c-1;c1>=0;c1--)
						{
							if(grid[r][c1]!='.')
								break;
							canServe[r][c1]++;
						}
								
						for(int r1=r+1;r1<R;r1++)
						{
							if(grid[r1][c]!='.')
								break;
							canServe[r1][c]++;
						}
						for(int r1=r-1;r1>=0;r1--)
						{
							if(grid[r1][c]!='.')
								break;
							canServe[r1][c]++;
						}
					}
				}
			}
			if(!valid())
				ans=0;
			else
				solve();
		}

		if(!ans)
		{
			cout<<"Case #"<<t<<": IMPOSSIBLE\n";
		}
		else
		{
			cout<<"Case #"<<t<<": POSSIBLE\n";
			for(int r=0;r<R;r++)
			{
				for(int c=0;c<C;c++)
				{
					if(grid[r][c]=='1')
						grid[r][c]='-';
					else if(grid[r][c]=='2')
						grid[r][c]='|';
					
					cout<<grid[r][c];
				}
				cout<<endl;
			}
		}
	}
}