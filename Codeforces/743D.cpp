#include "bits/stdc++.h"
using namespace std;

int n;
std::vector<int> a;
std::vector<std::vector<int> > adjList;
std::vector<bool> vis;
long long int finalAns;
bool validVal=0;
long long int dfs(int node)
{
	long long int ans=a[node];
	std::vector<long long int> v;
	for(int i=0;i<adjList[node].size();i++)
	{
		if(!vis[adjList[node][i]])
		{
			vis[adjList[node][i]]=1;
			long long int child=dfs(adjList[node][i]);
			ans+=child;
			if(v.size()<2)
			{
				v.push_back(child);
			}
			else
			{
				if(v[0]<v[1])
					swap(v[0],v[1]);
				if(child>=v[0])
				{
					v[1]=v[0];
					v[0]=child;
				}
				else
				{
					v[1]=child;
				}
			}
		}
	}
	if(v.size()==0)
		return ans;
	if(v.size()<2)
		return max(ans,v[0]);
	if(v[0]<v[1])
		swap(v[0],v[1]);
	if(!validVal)
	{
		validVal=1;
		finalAns=v[0]+v[1];
	}
	else
	{
		finalAns=max(finalAns,v[0]+v[1]);
	}
	if(ans>v[0])
		return ans;
	return v[0];
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n;
	if(n==1)
	{
		cout<<"Impossible";
		return 0;
	}
	a=std::vector<int> (n+1,0);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	adjList=std::vector<std::vector<int> > (n+1);
	int u,v;
	for(int i=0;i<n-1;i++)
	{
		cin>>u>>v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	int root=1;
	vis=std::vector<bool> (n+1,0);
	if(adjList[1].size()==1)
	{
		vis[1]=1;
		root=adjList[1][0];
		vis[root]=1;
		while(adjList[root].size()<=2)
		{
			int i=0;
			for(;i<adjList[root].size();i++)
			{
				if(!vis[adjList[root][i]])
				{
					root=adjList[root][i];
					vis[root]=1;
					break;
				}
			}
			if(i==adjList[root].size())
			{
				//IMPOSSIBLE
				cout<<"Impossible";
				return 0;
			}
		}
	}
	vis[root]=1;
	std::vector<long long int> ans;
	for(int i=0;i<adjList[root].size();i++)
	{
		if(!vis[adjList[root][i]])
		{
			vis[adjList[root][i]]=1;
			long long int val=dfs(adjList[root][i]);
			// cout<<adjList[root][i]<<" "<<val<<endl;
			if(ans.size()<2)
			{
				ans.push_back(val);
			}
			else
			{
				if(ans[0]<ans[1])
					swap(ans[0],ans[1]);
				if(v>=ans[0])
				{
					ans[1]=ans[0];
					ans[0]=val;
				}
				else if(v>ans[1])
					ans[1]=val;
			}
		}
	}
	if(validVal)
	{
		finalAns=max(finalAns,ans[0]+ans[1]);
	}
	else
	{
		finalAns=ans[0]+ans[1];
	}
	cout<<finalAns;
}
