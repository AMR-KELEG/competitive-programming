//AC
#include "bits/stdc++.h"
#define INF 1000000000
using namespace std;
int n = 300000 ;
std::vector<int> expiry_time(n,-1);
std::vector<int> tree(4*(n));

void build(int node =1 , int l = 0, int r = n-1)
{
	if(l>r)
	{
		return;	
	}
	if(l==r)
		tree[node]=l;
	else
	{
		int mid = (l+r)>>1;
		build(2*node,l,mid);
		build(2*node+1,1+mid,r);
		tree[node]=l;
	}
	// cout<<l<<" "<<tree[node]<<" "<<r<<endl;
}

void update(int indx, int val, int node =1, int l=0, int r=n-1)
{
	if(l>indx || r<indx)
		return;
	if(l==r && l==indx)
	{
		expiry_time[indx]=val;
		tree[node]=l;
		return ;
	}
	int mid = (l+r)>>1;
	update(indx,val,2*node,l,mid);
	update(indx,val,2*node+1,1+mid,r);
	int lv = expiry_time[tree[2*node]];
	int rv = expiry_time[tree[1+2*node]];
	if(lv<=rv)
		tree[node] = tree[2*node];
	else
		tree[node] = tree[2*node+1];
}

int minQuery(int rl=0,int rr=n-1,int node=0,int l=0,int r=n-1)
{
	return tree[1];
	if(rl>r || rr<l)
		return -1;
	if(rl>=l && rr<=r)
	{
		return tree[node];
	}
	int mid = (l+r)>>1;
	int li = minQuery(rl,rr,2*node,l,mid);
	int ri = minQuery(rl,rr,1+2*node,1+mid,r);
	int lv = (li==-1)? INF: expiry_time[li];
	int rv = (ri==-1)? INF: expiry_time[ri];
	if(lv<=rv)
		return li;
	return ri;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	build();
	priority_queue<pair<int,int> >q; // -time and id
	int block;
	char op;
	while(cin>>t)
	{
		cin>>op;
		while(!q.empty() && -q.top().first< t)
		{
			int ext = -q.top().first;
			int id = q.top().second;
			q.pop();
			if(ext == expiry_time[id])
			{
				//update
				update(id,-1);
			}
		}
		if(op=='+')
		{
			int id = minQuery();
			printf("%d\n", id+1);
			expiry_time[id]=t+599;
			update(id,t+599);
			q.push({-(t+599),id});
			// cout<<"D "<<tree[0]<<endl;
		}
		else
		{
			cin>>block;
			block--;
			if(expiry_time[block] >=t)
			{
				printf("+\n");
				expiry_time[block]=t+599;
				update(block,t+599);
				q.push({-(t+599),block});		
			}
			else
			{
				printf("-\n");
			}
		}
	}
}