// AC
#include <bits/stdc++.h>
using namespace std;

int a[100000];
int vis[100000] = {};
int t;
vector<queue<int> > divisors(100001);

vector<int> parent;

int find(int node)
{
	if (node == parent[node])
	return node;
	return parent[node] = find(parent[node]);
}

void merge(int a, int b)
{
	int pa = find(a);
	int pb = find(b);
	if (pa==pb)return;
	// merge
	parent[pa] = pb;
}

int main()
{
	freopen("dream.in", "r", stdin);
	int T;
	cin>>T;
	for (t=1;t<=T;t++){
		int n;
		cin>>n;
		parent = vector<int> (n);
		for (int i=0;i<n;i++){
			cin>>a[i];
			parent[i] = i;
			for (long long int div=1; div*div<=a[i]; div++)
			{
				if (a[i] % div == 0)
				{
					if (div*div == a[i])
					{
						divisors[div].push(i);
					}
					else
					{
						divisors[div].push(i);
						divisors[a[i]/div].push(i);
					}
				}
			}
		}
		long long int ans = 0;
		if (n!=1)
		{
			for (int div=100000; div>=1; div--){
				queue<int> & q = divisors[div];
				if (q.empty())
				{
					continue;
				}
				if (q.size()==1)
				{
					q.pop();
					continue;
				}
				else
				{
					int n_new = 0;
					int gcd_n = q.size();
					// add edges for finding components
					int root = -1;
					queue<int> new_nodes;
					queue<int> old_nodes;
					while(!q.empty())
					{
						int node = q.front();
						q.pop();
						if (vis[node] != t)
						{
							vis[node] = t;
							new_nodes.push(node);
							n_new++;
						}
						else
						{
							old_nodes.push(node);
							root = node;
						}
					}
					if (gcd_n == n_new){
						root = new_nodes.front();
						new_nodes.pop();
					}
					while(!new_nodes.empty()){
						int node = new_nodes.front();
						new_nodes.pop();
						ans += div;
						merge(node, root);
					}

					if (! old_nodes.empty())
					{
						int node_first = old_nodes.front();
						old_nodes.pop();
						while(!old_nodes.empty())
						{
							int node_second = old_nodes.front();
							old_nodes.pop();
							int pf = find(node_first);
							int ps = find(node_second);
							if (pf != ps)
							{
								//merge
								merge(node_second, node_first);
								ans+= div;
							}
						}
					}
				}
			}
		}
		printf("Case %d: %lld\n", t, ans);
	}
}
