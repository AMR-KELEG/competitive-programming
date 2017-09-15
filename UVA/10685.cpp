//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;
	while(n!=0 || m!=0)
	{
		std::map<string, int> mp;
		string s,s1;
		for(int i=0;i<n;i++)
		{
			cin>>s;
			mp[s]=i;
		}
		std::vector<std::vector<int> > adjlist(n);
		for(int i=0;i<m;i++)
		{
			cin>>s>>s1;
			//s1 is the predator of s
			adjlist[mp[s1]].push_back(mp[s]);
			adjlist[mp[s]].push_back(mp[s1]);
		}
		std::vector<bool> vis(n,0);
		int maxSize=1;
		for(int i=0;i<n;i++)
		{
			if(!vis[i])
			{
				int curSize=0;
				queue<int>q;
				q.push(i);
				vis[i]=1;
				while(!q.empty())
				{
					curSize++;
					int u=q.front();
					q.pop();
					for(int in=0;in<adjlist[u].size();in++)
					{
						if(!vis[adjlist[u][in]])
						{
							vis[adjlist[u][in]]=1;
							q.push(adjlist[u][in]);	
						}
					}
				}
				maxSize=max(maxSize,curSize);
			}
		}
		cout<<maxSize<<endl;

		cin>>n>>m;
	}	
}