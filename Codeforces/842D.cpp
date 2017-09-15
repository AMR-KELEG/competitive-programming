//AC
#include "bits/stdc++.h"
#define INF 1000000007
using namespace std;
std::vector<std::vector<int> > is_set(19);
std::vector<int> min_set_indx(19,-1);
std::vector<int> nos;
void add(int val, int bit = 18)
{
	if(bit == -1)
		return ;
	if (val >= (1<<bit))
	{
		val -= (1<<bit);
		is_set[bit].push_back(1);
		if(min_set_indx[bit]==-1)
		{
			min_set_indx[bit] = int(nos.size());
		}
	}
	else
		is_set[bit].push_back(0);
	add(val,bit-1);
}

int solve(int m)
{
	int l = 0;
	int r = nos.size() - 1;
	for(int bit=18;bit>=0;bit--)
	{
		if(min_set_indx[bit] == -1)
			continue;
		if(l==r)
			break;
		if ((!is_set[bit][r] || is_set[bit][l]))
			continue;
		// cout<<"Bit: "<<bit<<" L,no[L]: "<<l<<" "<<nos[l]<<" R,no[R]: "<<r<<" "<<nos[r]<<endl;
		int tl = l;
		int tr = r;
		while(tl<tr)
		{
			// cout<<tl<<" "<<tr<<endl;
			int mid = (tl+tr)>>1;
			if(is_set[bit][mid])
			{
				tr = mid;
			}
			else
			{
				tl = mid+1;
			}
		}
		if(tl>tr)
			continue;
		int mid = (tl+tr)>>1;
		if (m & (1<<bit))
		{
			// take from mid to r
			l = mid;
		}
		else
		{
			// take from l to mid-1
			r = mid-1;
		}
	}
	// cout<<nos[l]<<" ";
	return l;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;
	std::vector<bool> av( (1<<19),1);
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		av[a]=0;
	}
	int N=0;
	int min_val = INF;		
	for(int i=0;i< (1<<19);i++)
	// for(int i=0;i<3;i++)
	{
		if(av[i])
		{
			nos.push_back(i);
			min_val = min(min_val, i);
			add(i);
			// cout<<endl;
		}
	}
	int res =0;
	while(m--)
	{
		int x;
		cin>>x;
		res = res ^ x;
		if(av[res])
		{
			printf("0\n");
		}
		else
		{
			printf("%d\n", nos[solve(res)] ^ res);	
		}
	}
}