//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<int> an;
std::vector<bool> hasparent;
queue<int>out;
std::vector<std::vector<int> > adjlist;
std::vector<bool> added;
bool check(int node)
{
	for(int i=0;i<adjlist[node].size();i++)
	{
		if(an[adjlist[node][i]]==adjlist[node][i])
			continue;
		if(an[adjlist[node][i]]==an[node])
			continue;
		return 0;	
	}
	for(int i=0;i<adjlist[node].size();i++)
	{
		if(!check(adjlist[node][i]))
			return 0;
	}
	return 1;
}

void prepareout(int node)
{
	// cout<<node<<" "<<an[node]<<endl;
	for(int i=0;i<adjlist[node].size();i++)
	{
		prepareout(adjlist[node][i]);
	}
	// cout<<"OK";
	if(node==an[node])
	{
		out.push(an[node]);
		added[an[node]]=1;
	}
}
int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;
	an=std::vector<int> (n+1);
	hasparent=std::vector<bool>(n+1,0);
	added=std::vector<bool>(n+1,0);
	adjlist=std::vector<std::vector<int> >(n+1);
	int p,q;
	while(m--)
	{
		cin>>p>>q;
		hasparent[q]=1;
		adjlist[p].push_back(q);
	}
	for(int i=1;i<=n;i++)
		cin>>an[i];
	bool noans=0;
	for(int i=1;i<=n;i++)
	{
		if(!hasparent[i])
		{
			if(check(i))
			{
				prepareout(i);
				// break;
				// ;
			}
			else
			{
				noans=1;
				break;
			}
		}
	}
	if(noans)
	{
		cout<<-1;
	}
	else
	{
		printf("%d\n", (int)out.size());
		while(!out.empty())
		{
			printf("%d\n", out.front());
			out.pop();
		}
	}
}