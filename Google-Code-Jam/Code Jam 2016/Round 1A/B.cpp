#include "bits/stdc++.h"
using namespace std;
string grid[53];
std::vector<string> cols;
int rows;
int n;
void insert(string s)
{
	if(rows==n)
	{
		cols.push_back(s);
		return;
	}
	int r;
	for(r=1;r<=50;r++)
	{
		int i=0;
		for(;i<s.size();i++)
		{
			if(s[i]==' ')
				continue;
			if(s[i]>=grid[r][i])
			{
				cols.push_back(s);
				r=100;
				break;
			}
		}
		if(i==s.size())
		{
			for(int row=49;row!=r;row--)
			{
				grid[row+1]=grid[row];
			}
			grid[r]=s;
			rows++;
			r=100;
			break;
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);

	#endif
	int te;
	cin>>te;
	string s;
	for(int t=1;t<=te;t++)
	{
		cin>>n;
		rows=0;
		cols.clear();
		for(int i=1;i<=50;i++)
		{
			grid[i]="2501 2501 2501 2501 2501 2501 2501 2501 2501 " 
		"2501 2501 2501 2501 2501 2501 2501 2501 2501 2501 "
		"2501 2501 2501 2501 2501 2501 2501 2501 2501 2501 2501 " 
		"2501 2501 2501 2501 2501 2501 2501 2501 2501 2501 2501 " 
		"2501 2501 2501 2501 2501 2501 2501 2501 2501 ";
			
		}
		getline(cin,s);
		insert(s);
		cout<<"Case #"<<t<<": "<<cols.size()<<endl;
	}	
}