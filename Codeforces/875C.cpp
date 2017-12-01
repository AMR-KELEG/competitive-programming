// AC
#include "bits/stdc++.h"
using namespace std;
#define OFF 10000000
std::vector<int> mp;
std::vector<std::vector<int> > adjList;
std::vector<bool> cycle_vis;
std::vector<bool> done;
std::vector<bool> vis;
set<int> s;
bool cycle(int node)
{
	if (done[node])
		return 0;
	if (cycle_vis[node])
	{
		return 1;
	}
	cycle_vis[node] =1;
	bool ans = 0;
	for (auto ch:adjList[node])
	{
		if (cycle(ch))
		{
			ans = 1;
		}
	}
	done [node] = 1;
	return ans;
}

bool dfs(int node,bool is_changed = 0)
{
	if (vis[node] && !is_changed)
		return 1;
	vis[node] = 1;
	for (auto ch:adjList[node])
	{
		if (mp[node] > mp[ch])
		{
			if (!dfs(ch,0))
				return 0;
		}
		// change ch
		else if (mp[ch] > OFF)
		{
			mp[ch] -=  OFF;
			if (mp[node] > mp[ch])
			{
				// ok
				s.insert(ch);
				if (!dfs(ch,1))
					return 0;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;
	mp = std::vector<int> (m+1);
	adjList = std::vector<std::vector<int> > (m+1);
	vis = std::vector<bool> (m+1,0);
	cycle_vis = std::vector<bool> (m+1,0);
	done = std::vector<bool> (m+1,0);
	for (int i=1;i<=m;i++)
	{
		mp[i] = i+ OFF;
	}	
	int l;
	cin>>l;
	std::vector<int> last(l);
	for (int i=0;i<l;i++)
	{
		cin>>last[i];
	}
	std::vector<pair<int,int> > conditions;
	for (int i=1;i<n;i++)
	{
		cin>>l;
		std::vector<int> cur(l);
		bool is_same = 1;
		int j=0;
		for (;j<l && j<last.size();j++)
		{
			cin>>cur[j];
			if (mp[cur[j]]<mp[last[j]])
			{
				is_same = 0;
				if (mp[last[j]]<OFF)
				{
					cout<<"No";
					return 0;
				}
				mp[last[j]] -=OFF;					
				if (mp[cur[j]]<mp[last[j]])
				{
					cout<<"No";
					return 0;	
				}
				s.insert(last[j]);
				// cout<<i<<" "<<last[j]<<endl<<endl;
				int a = last[j],b = cur[j];
				// at the end this condition must be satisfied
				conditions.push_back({a,b}); // b > a
				j++;
				break;
			}
			if (mp[cur[j]]>mp[last[j]])
			{
				is_same = 0;
				int a = last[j],b = cur[j];
				// at the end this condition must be satisfied
				conditions.push_back({a,b}); // b > a
				j++;
				break;
			}
		}
		if (is_same)
		{
			// check the lengths only
			if (l < last.size())
			{
				cout<<"No";
				return 0;
			}

		}
		for (;j<l;j++)
		{
			cin>>cur[j];
			// cout<<cur[j]<<" ";
		}
		last = cur;
		// cout<<endl<<endl;
		// cin in cur
	}
	// check the conditions
	std::vector<int> degree(m+1,0);
	for (auto p:conditions)
	{
		int a = p.first;
		int b = p.second;
		degree[a] ++;
		adjList[b].push_back(a);
	}
	for (int i=1;i<=m;i++)
	{
		if (cycle_vis[i])
		{
			continue;
		}
		if (cycle(i))
		{
			cout<<"No";
			return 0;	
		}
	}
	for (int i=1;i<=m;i++)
	{
		if (degree[i] == 0 && dfs(i) ==0)
		{
			cout<<"No";
			return 0;
		}
	}
	printf("Yes\n%d\n", (int)s.size());
	for (auto no:s)
		printf("%d ", no);
}