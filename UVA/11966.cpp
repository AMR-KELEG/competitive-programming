// AC
// 1:12 -> 1:19
#include "bits/stdc++.h"
using namespace std;
#define EPS 0.0000000001
std::vector<int> par;
int find (int node)
{
	if(node == par[node])
		return node;
	return par[node] = find(par[node]);
}

void join (int a,int b)
{
	int pa = find(a);
	int pb = find(b);
	if (pa==pb)
		return;
	par[pa]=pb;
}


int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	for (int t=1;t<=T;t++)
	{
		int n;
		long double D;
		cin>>n>>D;
		D *= D;
		par =std::vector<int> (n);
		for (int i=0;i<n;i++)
			par[i]=i;
		std::vector<long double> x(n);
		std::vector<long double> y(n);
		for (int i=0;i<n;i++)
		{
			cin>>x[i]>>y[i];
		}

		for (int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				long double dis = ((x[i]-x[j])*(x[i]-x[j])) + ((y[i]-y[j])*(y[i]-y[j]));
				if (dis<D || abs(dis-D)<EPS)
					join(i,j);
			}
		}
		int ans =0;
		for(int i=0;i<n;i++)
		{
			if (i==find(i))
				ans++;
		}

		printf("Case %d: %d\n", t,ans);
	}		
}