//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<std::vector<bool> > adjmat;
std::vector<int> p;
std::vector<int> vis,indexes,values;
int n;
void dfs(int i)
{
	vis[i]=1;
	indexes.push_back(i);
	values.push_back(p[i]);
	for(int j=1;j<=n;j++)
	{
		if(adjmat[i][j] && !vis[j])
		{
			dfs(j);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n;
	adjmat=std::vector<std::vector<bool> > (n+5,std::vector<bool> (n+5,0));
	p=std::vector<int> (n+5);
	vis=std::vector<int> (n+5,0);
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}	
	char t;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>t;
			adjmat[i][j]= t-'0';
			//cout<<adjmat[i][j]<<" ";
		}
		//cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i);
			sort(indexes.begin(), indexes.end());
			sort(values.begin(), values.end());
			for(int in=0;in<indexes.size();in++)
			{
				p[indexes[in]]=values[in];
			}
			indexes.clear();
			values.clear();
		}
	}
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";
}