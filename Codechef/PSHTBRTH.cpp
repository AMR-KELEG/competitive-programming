// AC
#include "bits/stdc++.h"
using namespace std;
int find_hash(std::vector<std::vector<int> > & grid)
{
	short shift=0;
	int ans = 0;
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			ans += (grid[i][j]<<shift);
			shift++;
		}
	}
	return ans;
}

int gr[1<<17];
std::vector<int> tree;
std::vector<int> v;
int solve(std::vector<std::vector<int> > grid)
{
	int hash_val = find_hash(grid);
	if (gr[hash_val] !=-1)
		return gr[hash_val];
	if (hash_val==0)
		return 0;
	set<int> ch;
	for (int rs = 0;rs<4;rs++)
	{
		for (int cs=0;cs<4;cs++)
		{
			if (!grid[rs][cs])
			{
				continue;
			}
			for (int re=rs; re<4;re++)
			{
				for (int ce=cs;ce<4;ce++)
				{
					bool ok = 1;
					for (int r=rs;r<=re;r++)
					{
						for (int c=cs;c<=ce;c++)
						{
							if (!grid[r][c])
							{
								ok= 0;
								r=re+1;
								break;
							}
						}
					}
					if (ok)
					{
						// try it
						std::vector<std::vector<int> > new_grid = grid;
						for (int r=rs;r<=re;r++)
						{
							for (int c=cs;c<=ce;c++)
							{
								new_grid[r][c] = 0;
							}
						}
						ch.insert(solve(new_grid));
					}
				}
			}
		}
	}
	for (int i=0;i<1000000;i++)
	{
		if (ch.find(i) == ch.end())
			return gr[hash_val] = i;
	}
}

void update(int l, int r,int indx, int val, int node = 1)
{
	if (l>indx || r<indx)
		return ;
	if (l==r && r==indx)
	{
		tree[node] = val;
		return ;
	}
	int mid = (l+r)>>1;
	update(l, mid, indx, val, 2*node);
	update(1+mid, r, indx, val, 2*node+1);
	tree[node] = tree[2*node] ^ tree[2*node+1];
}

int query(int l,int r,int rl,int rr,int node= 1)
{
	if (l>rr || r<rl)
		return 0;
	if (l>=rl && r<=rr)
		return tree[node];
	int mid = (l+r)>>1;
	return query(l,mid,rl,rr,2*node) ^ 
		   query(1+mid,r,rl,rr,2*node+1);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	memset(gr, -1, sizeof gr);
	int T;
	scanf("%d", &T);
	std::vector<std::vector<int> > cake(4,std::vector<int> (4));
	int n,q;
	while(T--)
	{
		scanf("%d %d", &n, &q);
		v = std::vector<int> (n, 0);
		tree = std::vector<int> (4*n, 0);
		for (int c=0; c<n; c++)
		{
			for (int i=0;i<4;i++)
			{
				for (int j=0;j<4;j++)
				{
					char ch;
					scanf("%c",&ch);
					while(ch!='0' && ch!='1')
						scanf("%c",&ch);
					cake[i][j] = ch - '0';
				}
			}
			update(0,n-1,c,solve(cake));
		}

		while(q--)
		{
			int qt;
			scanf("%d", &qt);
			if (qt==1)
			{
				int l,r;
				scanf("%d %d",&l, &r);
				// int query(int l,int r,int rl,int rr,int node= 1)
				int nim_val = query(0,n-1,l-1,r-1);
				if (nim_val)
					printf("Pishty\n");
				else
					printf("Lotsy\n");
			}
			else
			{
				int indx;
				scanf("%d", &indx);
				indx--;
				for (int i=0;i<4;i++)
				{
					for (int j=0;j<4;j++)
					{
						char ch;
						scanf("%c",&ch);
						while(ch!='0' && ch!='1')
							scanf("%c",&ch);
						cake[i][j] = ch - '0';
					}
				}
				update(0,n-1,indx,solve(cake));
			}
		}
	}

}