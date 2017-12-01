//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<std::vector<int> > droid;
std::vector<int> cur_ans;
int n,m,k;

bool valid (int len)
{
	if (len == 0)
	{
		for (int d=0;d<m;d++)
			cur_ans[d] = 0;
		return 1;
	}
	std::vector<priority_queue<int>> max_droid(m);
	std::vector<priority_queue<int>> remove_droid(m);
	for (int i=0;i<len;i++)
	{
		for (int d=0;d<m;d++)
		{
			max_droid[d].push(droid[i][d]);
		}
	}
	long long int total_req = 0;
	for (int d=0;d<m;d++)
	{
		int cur_req = max_droid[d].top();
		total_req += cur_req;
		cur_ans[d] = cur_req;
	}
	if (total_req<=k)
	{
		return 1;
	}
	for (int i=len;i<n;i++)
	{
		total_req = 0;
		for(int d=0;d<m;d++)
		{
			// remove i-len
			while (!remove_droid[d].empty() && 
				   !max_droid[d].empty() &&
				   remove_droid[d].top() == max_droid[d].top())
			{
				remove_droid[d].pop();
				max_droid[d].pop();
			}
			int rem_val = droid[i-len][d];
			if (max_droid[d].top() == rem_val)
			{
				max_droid[d].pop();
			}
			else
			{
				remove_droid[d].push(rem_val);
			}
			while (!remove_droid[d].empty() && 
				   !max_droid[d].empty() &&
				   remove_droid[d].top() == max_droid[d].top())
			{
				remove_droid[d].pop();
				max_droid[d].pop();
			}
			max_droid[d].push(droid[i][d]);
			total_req += max_droid[d].top();
			cur_ans[d] = max_droid[d].top();
		}
		if (total_req <=k)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif

	cin>>n>>m>>k;
	droid = std::vector<std::vector<int> > (n, std::vector<int> (m));
	cur_ans = std::vector<int> (m,0);
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
			cin>>droid[i][j];
	}
	int l = 0, r = n;
	while (l<r)
	{
		int mid = (l+r+1)>>1;
		if (valid(mid))
		{
			l = mid;
		}
		else
		{
			r = mid-1;
		}
	}
	if (r<0)
	{
		l = 0;
		r = 0;
	}
	valid((l+r+1)>>1);
	for (int i=0;i<m;i++)
		cout<<cur_ans[i]<<" ";

}