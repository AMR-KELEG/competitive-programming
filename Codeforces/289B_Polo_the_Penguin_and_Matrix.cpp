#include "bits/stdc++.h"
using namespace std;
int main()
{
	freopen("in.txt","r",stdin);
	int n,m,d;
	cin>>n>>m>>d;
	vector< vector<int> >board(n,vector<int>(m)),power(n,vector<int>(m));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>board[i][j];
		}
	}
	int rem=board[0][0]%d;
	long long int totalpower=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			power[i][j]=board[i][j]/d;
			totalpower+=power[i][j];
			if(board[i][j]%d !=rem)
			{
				rem=-1;
				i=n;
				break;
			}
		}
	}
	if(rem==-1)
	{
		cout<<-1;
	}
	else
	{
		long long int min_ope=1<<29,ope=0;
		for(int desiredpower=1;desiredpower<=10000;desiredpower++)
		{
			ope=0;
			for(int i=0;i<n;i++)
			{	
				for(int j=0;j<m;j++)
				{
					ope+=abs(power[i][j]-desiredpower);
				}
			}
			min_ope=min(min_ope,ope);
		}
				
		cout<<min_ope;
	}
	return 0;
}