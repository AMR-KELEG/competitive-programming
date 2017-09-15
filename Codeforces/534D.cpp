//AC
#include "bits/stdc++.h"
using namespace std;
int nos_at_val[200000];
int par[200000];
pair<int,int> arr[200000];
int ans[200000];
pair<int,int> req[200000];
int n;

int find_par(int val)
{
	if(val < 0)
		return val;
	if(nos_at_val[val])
		return val;
	return par[val] = find_par(par[val]);
}

int find_val(int val)
{
	if (val < 0)
		return -1;
	if(nos_at_val[val] == 0)
	{
		par[val] = find_par(par[val]);
		return find_val(par[val]);
	}
	nos_at_val[val]--;
	return val;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n;
	memset(par,-1,sizeof par);
	int last[3]={-1,-1,-1};
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].first;
		arr[i].second = i;
	}
	sort(arr, arr+n);
	for(int i=0;i<n;i++)
	{
		nos_at_val[arr[i].first]++;
		if(par[arr[i].first] == -1 && arr[i].first !=last[(arr[i].first)%3])
		{
			par[arr[i].first] = last[(arr[i].first)%3];
		}
		last[(arr[i].first)%3] = arr[i].first;
	}
	for(int i=3;i<n;i++)
	{
		if(par[i]< 0)
			par[i] = find_par(i-3);
	}

	int cur_val = 0;
	for(int i=0;i<n;i++)
	{
		int val = find_val(cur_val);
		if(val < 0)
		{
			printf("Impossible");
			return 0;
		}
		// at index i we need value v
		req[i] = {val, i};
		cur_val = val +1;
	}
	sort(req, req+n);
	for(int i=0;i<n;i++)
	{
		// at index req[i].second
		// put element arr[i].second
		ans[req[i].second] = arr[i].second+1;
	}
	printf("Possible\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ", ans[i]);
	}
	return 0;
}