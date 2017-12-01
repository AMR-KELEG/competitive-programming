#include "bits/stdc++.h"
using namespace std;
set<long long int>s;
map<long long int, int> fwd_map;
map<int,long long int> bck_map;
int MAX_SIZE;
std::vector<int> first_missing;
std::vector<int> first_present;
std::vector<int> lazy_t;
int INF;
int n;
void compress()
{
	auto it = s.begin();
	long long int val = * (it);
	val--;
	int indx = 0;
	if (val)
	{
		val = 1;
		fwd_map[val] = indx;
		bck_map[indx] = val;
		indx++;
	}
	while(it != s.end())
	{
		if (*it > val+1)
		{
			// add new one
			val++;
			fwd_map[val] = indx;
			bck_map[indx] = val;
			indx++;
		}
		if (*it > val+1)
		{
			val = (*it)-1; 
			fwd_map[val] = indx;
			bck_map[indx] = val;
			indx++;
		}
		val = *it;
		fwd_map[val] = indx;
		bck_map[indx] = val;
		indx++;
		it++;
	}
	val++;
	fwd_map[val] = indx;
	bck_map[indx] = val;
	INF = indx;
	MAX_SIZE = indx;
	first_missing = std::vector<int> (4 * MAX_SIZE, indx);
	first_present = std::vector<int> (4 * MAX_SIZE, indx);
	lazy_t = std::vector<int> (4 * MAX_SIZE, 0);
}

void relax(int l, int r, int node)
{
	if (!lazy_t[node])
		return ;
	if (lazy_t[node] == 1)
	{
		first_missing[node] = INF;
		first_present[node] = l;
	}
	else if (lazy_t[node] == 2)
	{
		first_missing[node] = l;
		first_present[node] = INF;
	}
	else
	{
		swap(first_missing[node], first_present[node]);
	}
	if (l==r)
	{
		lazy_t[node] = 0;
		return ;
	}
	lazy_t[2*node] = lazy_t[node];
	lazy_t[2*node+1] = lazy_t[node];
	lazy_t[node] = 0;
}

void update(int l, int r, int rl, int rr, int t, int node=1)
{
	relax(l,r,node);
	if (l>rr || r<rl)
		return;
	if (l>=rl && r<=rr)
	{
		lazy_t[node] = t;
		relax(l,r,node);
		return ;
	}
	int mid = (l+r)>>1;
	update(l,mid,rl,rr,t,2*node);
	update(1+mid,r,rl,rr,t,1+2*node);
	first_missing[node] = min(first_missing[2*node],first_missing[2*node+1]);
	first_present[node] = min(first_present[2*node],first_present[2*node+1]);
}

int query(int l, int r, int rl, int rr, int node=1)
{
	relax(l,r,node);
	if (l>rr || r<rl)
		return INF;
	if (l>=rl && r<=rr)
	{
		return first_missing[node];
	}
	int mid = (l+r)>>1;
	return min(query(l,mid,rl,rr,2*node),
				query(1+mid,r,rl,rr,1+2*node));
}

void build(int l,int r,int node=1)
{
	if (l==r)
	{
		first_missing[node] = l;
		first_present[node] = INF;
		return;
	}
	int mid = (l+r)>>1;
	build(l,mid,2*node);
	build(1+mid,r,1+2*node);
	first_missing[node] = first_missing[2*node];
	first_present[node] = INF;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int Q;
	scanf("%d", &Q);
	std::vector<long long> L(Q), R(Q);
	std::vector<int> T(Q);
	for (int i=0;i<Q;i++)
	{
		long long l,r;
		int t;
		scanf("%d %lld %lld", &t, &l, &r);
		L[i] = l;
		R[i] = r;
		T[i] = t;
		s.insert(l);
		s.insert(r);
	}
	compress();
	n = fwd_map.size();
	// for (auto p:fwd_map)
	// 	cout<<p.first<<" "<<p.second<<endl;
	// cout<<endl<<endl;
	// cout<<n<<endl<<endl;
	build(0,n-1);
	for (int i=0;i<Q;i++)
	{
		int l = fwd_map[L[i]];
		int r = fwd_map[R[i]];
		update(0, n-1, l, r, T[i]);
		int missing = query(0,n-1,0,n-1);
		long long int val = bck_map[missing];
		// printf("l: %d r: %d -> ", l, r);
		printf("%lld\n", val);
	}
}