// AC
// 8:28
// 8:35
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	while(n)
	{
		std::vector<int> perm(n);
		for(int i=0;i<n;i++)
		{
			cin>>perm[i];
			perm[i]--;
		}
		std::vector<std::vector<int> > cycles;
		std::vector<bool> vis(n,0);
		for (int i=0;i<n;i++)
		{
			if (!vis[i])
			{
				// new cycle here
				vis[i]=1;
				std::vector<int> cur_cycle;
				cur_cycle.push_back(i);
				int cur_node = perm[i];
				while(!vis[cur_node])
				{
					vis[cur_node] = 1;
					cur_cycle.push_back(cur_node);
					cur_node = perm[cur_node];
				}
				cycles.push_back(cur_cycle);
				// for (auto i:cur_cycle)
				// 	cout<<i<<" ";
				// cout<<endl<<endl;
			}
		}
		int k;
		cin>>k;
		while(k)
		{
			string mes;
			getline(cin,mes);
			mes.erase(0,1);
			mes = mes + string ((n - int(mes.size())), ' ');
			for (auto cyc: cycles)
			{
				int it = k % int(cyc.size());
				while (it--)
				{
					string temp = mes;
					for (auto in:cyc)
					{
						temp[perm[in]] = mes[in];
					}
					mes = temp;
				}
			}
			cout<<mes<<endl;
			cin>>k;
		}
		cin>>n;
		cout<<endl;
	}
}