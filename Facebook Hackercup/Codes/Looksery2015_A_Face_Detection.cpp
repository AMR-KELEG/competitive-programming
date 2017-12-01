#include "bits/stdc++.h"
using namespace std;
bool inrange(int n,int st,int en)
{
	if(n>=st && n<=en)return true;
	return false;
}
int main()
{
	int n,m;
	cin>>n>>m;
	char b[51][51]={};
	for(int r=1;r<=n;r++)
	{
		for(int c=1;c<=m;c++)
		{
			cin>>b[r][c];
		}
	}
	if(n==1 || m==1)
	{
		cout<<0;
	}
	else
	{
		string s;
		int counter=0;
		for(int r=1;r<n;r++)
		{
			for(int c=1;c<m;c++)
			{
				s=b[r][c];
				s+=b[r+1][c];
				s+=b[r][c+1];
				s+=b[r+1][c+1];
				if(inrange(s.find("f"),0,s.size()-1) && inrange(s.find("a"),0,s.size()-1) && inrange(s.find("c"),0,s.size()-1) && inrange(s.find("e"),0,s.size()-1))
					{
						counter++;
						//cout<<s.find("f")<<" "<<s<<endl;
					}
			}
		}
		cout<<counter;
	}
	return 0;
}