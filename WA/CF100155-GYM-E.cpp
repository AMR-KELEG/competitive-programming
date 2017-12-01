// WA
#include "bits/stdc++.h"
using namespace std;
int adjMat[1027][1027];
std::vector<std::vector<int> > adjList;
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	string s;
	int T;
	cin>>T;
	while(T--)
	{
		cin>>s;
		adjList = std::vector<std::vector<int> > (28+s.size());// 2 + 26 + s.size()
		memset(adjMat, 0, sizeof adjMat);
		int c_char[26]={};
		for (auto c:s)
			c_char[c-'a'] ++;
		
		for (int i=0;i<26;i++)
		{
			adjMat[0][i+1] = c_char[i];
			adjList[0].push_back(i+1);
		}
		string constraint;
		for (int i=0;i<s.size();i++)
		{
			cin>>constraint;
			for (auto c:constraint)
			{
				// edge between char and indx
				adjMat[1+c-'a'][27+i] = 1;
				adjList[1+c-'a'].push_back(27+i);
				adjList[27+i].push_back(1+c-'a');
			}
		}
		int des = 27+s.size();
		for (int i=0;i<=des;i++)
		{
			sort (adjList[i].begin(), adjList[i].end());
		}

		for (int i=27;i<27+s.size();i++)
		{
			adjList[i].push_back(des);
			adjMat[i][des] = 1;
		}
		int flow = 0;
		bool found_path = 1;
		while (found_path)
		{
			found_path = 0;
			priority_queue<pair<int,int>> q; // node then parent
			q.push({0,0});
			std::vector<bool> vis(des+1,0);
			std::vector<int> par(des+1,0);
			vis[0] = 1;
			while(!q.empty())
			{
				int node = q.top().first;
				par[node] = q.top().second;
				q.pop();
				vis[node] = 1;
				if (node == des)
				{
					found_path = 1;
					break;	
				}
				for (auto ch: adjList[node])
				{
					if (! vis[ch] && adjMat[node][ch])
					{
						q.push({ch,node});
					}
				}
			}
			if (found_path)
			{
				int cur_node = des;
				while(cur_node !=0)
				{
					adjMat[par[cur_node]][cur_node] -= 1;
					adjMat[cur_node][par[cur_node]] += 1;
					cur_node = par[cur_node];
				}
				flow ++;
			}
		}
		if (flow != s.size())
		{
			cout<<"NO SOLUTION";
		}
		else
		{
			for (int node = 0;node<s.size();node++)
			{
				// 27 + node
				for (int ch=1;ch<=26;ch++)
				{
					if (adjMat[27+node][ch] == 1)
					{
						cout<<char('a'+ch-1);
						break;
					}
				}
			}
		}	
		cout<<"\n";
	}
}