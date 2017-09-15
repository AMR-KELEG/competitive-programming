//AC
#include "bits/stdc++.h"
using namespace std;
#define INF 1000000000
int adjMat[1022][1022];

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int categ;
	int pool;
	cin>>categ>>pool;

	while(! (categ == 0 && pool == 0))
	{
		memset(adjMat, 0 , sizeof adjMat);
		int des = 1+pool+categ;
		int req_flow = 0;
		for(int i=1+pool;i<=pool+categ;i++)
		{
			int req;
			cin>>req;
			req_flow += req;
			adjMat[i][des] = req;
		}
		for(int i=1;i<=pool;i++)
		{
			adjMat[0][i]= 1;
			int n_cat;
			cin>>n_cat;
			while(n_cat--)
			{
				int cat;
				cin>>cat;
				adjMat[i][cat+pool]=1;
			}
		}


		bool found_path=0;
		do 
		{	
			found_path=0;
			std::vector<int> par(1022,-1);
			queue<int>q;
			q.push(0);
			par[0]=0;
			while(!q.empty())
			{
				int node = q.front();
				q.pop();
				if (node == des)
				{
					// found a path
					found_path = 1;
					int cur_node = des;
					int flow_val = INF;
					while (cur_node!=0)
					{
						// edge between par[node] & node
						flow_val = min(flow_val, adjMat[par[cur_node]][cur_node]);
						cur_node = par[cur_node];
					}
					cur_node = des;
					req_flow -= flow_val;
					while (cur_node!=0)
					{
						// edge between par[node] & node
						adjMat [par[cur_node]][cur_node] -= flow_val;
						adjMat [cur_node][par[cur_node]] += flow_val;
						cur_node = par[cur_node];
						// cout<<cur_node<<" "<<par[cur_node]<<endl;
					}
					// cout<<endl;
					break;
				}
				int ch = 0;
				int lim = 1022;
				if (node == 0)
				{
					ch = 1;
					lim = pool;
				}
				else if (node<1+pool)
				{
					ch = pool+1;
					lim = pool+categ;
				}
				else
				{
					ch = 1;
					lim = des;
				}
				for (;ch<=lim;ch++)
				{
					if (ch==node)
						continue;
					if (par[ch]!=-1)
						continue;
					if (adjMat[node][ch])
					{
						q.push(ch);
						par[ch] = node;
					}
				}
			}

		}while(found_path);
		if (req_flow == 0)
		{
			printf("1\n");
			queue<int>q;
			for (int c = 1+pool;c<=pool+categ;c++)
			{
				// check connections of c
				// adjMat[c][ch] = 1
				// cout<<ch
				for (int ch = 1;ch<=pool;ch++)
				{
					if (adjMat[c][ch])
					{
						q.push(ch);
					}
				}
				if (!q.empty())
				{
					printf("%d", q.front());
					q.pop();
					while(!q.empty())
					{
						printf(" %d", q.front());
						q.pop();
					}
				}
				printf("\n");
			}
		}
		else
		{
			printf("0\n");
		}
		cin>>categ>>pool;
	}

}