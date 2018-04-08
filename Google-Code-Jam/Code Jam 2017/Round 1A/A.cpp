#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("A-large.in","r",stdin);
		freopen("A-large-out.in","w",stdout);
	#endif
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		int R,C;
		cin>>R>>C;
		std::vector<std::vector<char> > cake(R+1,std::vector<char> (C+1));
		for(int r=1;r<=R;r++)
		{
			for(int c=1;c<=C;c++)
			{
				cin>>cake[r][c];
			}
		}
		for(int r=1;r<=R;r++)
		{
			for(int c=1;c<=C;c++)
			{
				if(cake[r][c]!='?')
				{
					//Go to the right and left
					for(int cn=c-1;cn>=1;cn--)
					{
						if(cake[r][cn]=='?')
							cake[r][cn]=cake[r][c];
						else
							break;
					}
					for(int cn=c+1;cn<=C;cn++)
					{
						if(cake[r][cn]=='?')
							cake[r][cn]=cake[r][c];
						else
							break;
					}
				}
			}
		}
		if(cake[1][1]=='?')
		{
			int r=2;
			for(;r<=R;r++)
			{
				if(cake[r][1]!='?')
					break;
			}
			for(int c=1;c<=C;c++)
				cake[1][c]=cake[r][c];
		}
		for(int r=1;r<=R;r++)
		{
			for(int c=1;c<=C;c++)
			{
				if(cake[r][c]=='?')
				{
					cake[r][c]=cake[r-1][c];
				}
			}
		}
		cout<<"Case #"<<t<<":\n";
		for(int r=1;r<=R;r++)
		{
			for(int c=1;c<=C;c++)
				cout<<cake[r][c];
			cout<<"\n";
		}
	}	
}