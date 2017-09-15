#include "bits/stdc++.h"
using namespace std;
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	vector<char>costumes(n+1,'n');
	string rem="wbr";
	int dancers[3];
	for(int i=0;i<m;i++)
	{
		rem="wrb";
		cin>>dancers[0]>>dancers[1]>>dancers[2];
		for(int j=0;j<3;j++)
		{
			if(costumes[dancers[j]]!='n')
			{
				rem.erase(rem.find(costumes[dancers[j]]),1);
				break;
			}
		}
		for(int j=0;j<3;j++)
		{
			if(costumes[dancers[j]]=='n')
			{
				costumes[dancers[j]]=rem[0];
				rem.erase(0,1);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(costumes[i]=='w')
		{
			cout<<1<<" ";
		}
		else if(costumes[i]=='r')
		{
			cout<<2<<" ";
		}
		else 
		{
			cout<<3<<" ";
		}
	}
	return 0;
}