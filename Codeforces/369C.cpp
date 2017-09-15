//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<std::vector<pair<int,int> > > adjlist;
std::vector<int> nodes;
bool solve(int node,int p)
{
	int cn,ct;
	bool ans=0;
	for(int i=0;i<adjlist[node].size();i++)
	{
		cn=adjlist[node][i].first;
		ct=adjlist[node][i].second;
		// cout<<node<<" "<<cn<<endl;
		if(cn==p)
			continue;
		bool a=solve(cn,node);
		ans=ans	|| a;
		if(ct==2)
		{
			// ans=1;
			if(a==0)
			{
				ans=1;
				nodes.push_back(cn);
			}
		}
	}
	// cout<<"Parent "<<p<<" "<<"Node "<<node<<" "<<ans<<endl;
	return ans;
}
int main()
{
	freopen("in.txt","r",stdin);
	int n;
	cin>>n;
	adjlist=std::vector<std::vector<pair<int,int> > > (n+2);
	// edge node - type
	int u,v,t;
	for(int i=0;i<n-1;i++)
	{
		cin>>u>>v>>t;
		adjlist[u].push_back(pair<int,int>(v,t));
		adjlist[v].push_back(pair<int,int>(u,t));
	}
	solve(1,-1);

	cout<<nodes.size()<<endl;
	for(int i=0;i<nodes.size();i++)
		cout<<nodes[i]<<" ";


}