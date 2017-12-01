// AC
#include "bits/stdc++.h"
using namespace std;
#define Query pair<int,pair<int,int>>
#define L second.first
#define R second.second
int S;
std::vector<int> a;

bool cmp(const Query & q1, const Query & q2)
{
	int b1 = q1.L / S;
	int b2 = q2.L / S;
	return (b1<b2) || (b1==b2 && q1.R<q2.R);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,q;
	cin>>n>>q;
	S = sqrt(n);		
	a = std::vector<int> (n);
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	std::vector<Query> qu(q);
	for (int i=0;i<q;i++)
	{
		cin>>qu[i].L>>qu[i].R;
		// scanf("%d %d", &qu[i].L, &qu[i].R);
		qu[i].L--;
		qu[i].R--;
		qu[i].first = i;
	}
	sort(qu.begin(), qu.end(), cmp);
	std::vector<long long int> ans(q);
	int mo_l = 0;
	int mo_r = -1;
	std::vector<long long int> mp(1000001,0);
	long long int cur_ans = 0;
	for (int i=0;i<q;i++)
	{
		int cur_indx = qu[i].first;
		int l = qu[i].L;
		int r = qu[i].R;
		while(mo_r < r)
		{
			// insert mo_r+1
			mo_r++;
			int cur_val = a[mo_r];
			long long int cur_cnt = mp[cur_val];
			mp[cur_val]++;
			cur_ans += cur_val * (2*(cur_cnt) + 1);
		}
		while(mo_r > r)
		{
			// remove mo_r
			int cur_val = a[mo_r];
			long long int cur_cnt = mp[cur_val];
			mp[cur_val]--;
			cur_ans += cur_val * (1 - 2*(cur_cnt));
			mo_r--;
		}
		while(mo_l > l)
		{
			//insert mo_l-1
			mo_l--;
			int cur_val = a[mo_l];
			long long int cur_cnt = mp[cur_val];
			mp[cur_val]++;
			cur_ans += cur_val * (2*(cur_cnt) + 1);
		}
		while(mo_l <l)
		{
			// remove mo_l
			int cur_val = a[mo_l];
			long long int cur_cnt = mp[cur_val];
			mp[cur_val]--;
			cur_ans += cur_val * (1 - 2*(cur_cnt));
			mo_l++;
		}
		ans[cur_indx] = cur_ans;
	}
	for (int i=0;i<q;i++)
	{
		printf("%I64d\n", ans[i]);
	}
}