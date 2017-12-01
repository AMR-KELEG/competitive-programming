//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<int> t;
std::vector<int> first_untaken;
#define INF 1000000007
void build(int l,int r,int node=1)
{
	if (l == r)
	{
		first_untaken [node] = (t[l] == 0? l:INF);
		return ;
	}
	int mid = (l+r)>>1;
	build(l,mid,2*node);
	build(1+mid,r,1+2*node);
	first_untaken[node] = min (first_untaken[2*node],first_untaken[2*node+1]);
}

void update(int l,int r,int indx,int node = 1)
{
	if (l>indx || r<indx)
		return ;
	if (l==r && l==indx)
	{
		first_untaken[node]= INF;
		return ;
	}
	int mid = (l+r)>>1;
	update(l,mid,indx,2*node);
	update(1+mid,r,indx,1+2*node);
	first_untaken[node] = min (first_untaken[2*node],first_untaken[2*node+1]);
}

int query(int l,int r,int rl,int rr,int node = 1)
{
	if (l>rr || r<rl)
		return INF;
	if (l>=rl && r<=rr)
	{
		return first_untaken[node];
	}
	int mid = (l+r)>>1;
	return min(query(l,mid,rl,rr,2*node),query(1+mid,r,rl,rr,2*node+1));
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		first_untaken = std::vector<int> (4*m);
		t = std::vector<int> (m);
		for (int i=0;i<m;i++)
			cin>>t[i];
		build(0,m-1);
		std::vector<int> ans(m,-1);
		std::vector<int> last_occurence(n+1,-1);
		bool ok = 1;
		for (int i=0;i<m;i++)
		{
			if (t[i]==0)
			{
				ans[i] = 0;
			}
			else
			{
				// search for prev_zero
				int serve_zero = query(0,m-1,last_occurence[t[i]], i-1);
				if (serve_zero == INF)
				{
					ok = 0;
					break;
				}
				else
				{
					ans[serve_zero]  = t[i];
					update(0,m-1,serve_zero);
				}
			}
			last_occurence[t[i]] = i;
		}
		if (!ok)
			printf("NO\n");
		else
		{
			printf("YES\n");
			queue<int> a;
			for (int i=0;i<m;i++)
			{
				if (ans[i] !=-1)
					a.push(ans[i]);
			}
			if (!a.empty())
			{
				printf("%d", a.front());
				a.pop();
				while(! a.empty())
				{
					printf(" %d", a.front());
					a.pop();
				}
				printf("\n");
			}
		}
	}	
}