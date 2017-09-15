//Dominators
#include "bits/stdc++.h"
using namespace std;
int n;
std::vector<std::vector<int> > parents;
std::vector<bool> vis;
std::vector<set<int> > dominators;
std::set<int> allnodes;
char grid[105][105];
set<int> finddom(int i)
{
	if(vis[i])
		return dominators[i];
	if(i==0)
	{
		set<int>ans;
		ans.insert(0);
		return ans;
	}
	set<int>ans=allnodes;
	set<int>parentdom;
	set<int>newans;	
	vis[i]=1;
	for(int j=0;j<parents[i].size();j++)
	{
		parentdom=finddom(parents[i][j]);
		set<int>::iterator it=parentdom.begin();
		while(it!=parentdom.end())
		{
			if(ans.find((*it))!=ans.end())
				newans.insert(*it);
			it++;
		}
		ans=newans;
		newans.clear();
	}
	ans.insert(i);
	return dominators[i]=ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	for(int i=0;i<100;i++)
		allnodes.insert(i);
	set<int>fdom;
	for(int test=1;test<=t;test++)
	{
		cin>>n;
		memset(grid,0,sizeof grid);
		parents=std::vector<std::vector<int> >(n);
		vis=std::vector<bool> (n,0);
		dominators=std::vector<set<int> > (n);
		int edge;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>edge;
				if(edge)
					parents[j].push_back(i);
			}
		}

		for (int i = 0; i < n; ++i)
		{
			fdom=finddom(i);
			//cout<<i<<" : "<<fdom.size()<<endl<<"Dom ";
			set<int>::iterator it=fdom.begin();
			while(it!=fdom.end())
			{
				//cout<<*it<<" ";
				grid[*it][i]=1;
				it++;
			}
			//cout<<endl;
		}
		cout<<"Case "<<test<<":\n";
		for(int i=0;i<n;i++)
		{
			cout<<"+"<<string((2*n)-1, '-')<<"+\n";
			for(int j=0;j<n;j++)
			{
				cout<<"|";
				if(grid[i][j])
					cout<<"Y";
				else
					cout<<"N";
			}
			cout<<"|"<<endl;
		}
		cout<<"+"<<string((2*n)-1, '-')<<"+\n";

	}
	
}

/*
short adjmat[105][105];
char dom[105][105];
bool vis[105];
int counter[105];
int n;
std::vector<map<int,int> > paths;
void dfs(int i,std::vector<int> path)
{
	for(int j=0;j<path.size();j++)
	{
		paths[i][path[j]]++;
	}
	counter[i]++;
	vis[i]=1;
	for(int in=0;in<n;in++)
	{
		if(adjmat[i][in])
		{
			std::vector<int> p=path;
			p.push_back(i);
			dfs(in,p);		
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	for(int test=1;test<=t;test++)
	{
		cin>>n;
		paths.clear();
		paths.resize(n+2);
		memset(dom,0,sizeof dom);
		memset(vis,0,sizeof vis);
		memset(counter,0,sizeof counter);
		for(int i=0;i<n;i++)
			dom[0][i]=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>adjmat[i][j];
				if(i==j)
					dom[i][j]=1;
			}
		}
		dfs(0,std::vector<int> ());




		for(int i=0;i<n;i++)
		{
			std::map<int, int>::iterator it=paths[i].begin();
			while(it!=paths[i].end())
			{
				if(counter[i]==(*it).second)
				{
					dom[(*it).first][i]=1;
				}
				it++;
			}
		}



		cout<<"Case "<<test<<":\n";
		for(int i=0;i<n;i++)
		{
			cout<<"+"<<string((2*n)-1, '-')<<"+\n";
			for(int j=0;j<n;j++)
			{
				cout<<"|";
				if(dom[i][j])
					cout<<"Y";
				else
					cout<<"N";
			}
			cout<<"|"<<endl;
		}
		cout<<"+"<<string((2*n)-1, '-')<<"+\n";
		//cout<<string(5,'+')<<endl;
		//cout<"+"<<string((2*n)-1,'-')<<"+\n";
		
	}
}
*/	