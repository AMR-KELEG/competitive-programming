#include "bits/stdc++.h"
using namespace std;
#define Range pair<pair<int,int>,int>
int bucket_size;
bool cmp(const Range r1, const Range r2)
{
	int s1 = r1.first.first / bucket_size;
	int s2 = r2.first.first / bucket_size;
	if (s1<s2)
		return 1;
	if (s1==s2)
		return r1.first.second<r2.first.second;
	return 0;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m;
	scanf("%d %d",&n,&m);	
	bucket_size = sqrt(n);
	std::vector<int> v(n);
	for (int i=0;i<n;i++)
		cin>>v[i];
	std::vector<int> query_ans(m);
	std::vector<Range> ranges(m);
	for (int i=0,l,r;i<m;i++)
	{
		cin>>l>>r;
		l--;r--;
		ranges[i] = {{l,r},i};
	}
	sort(ranges.begin(), ranges.end(), cmp);
	int mo_l = 0, mo_r = -1;
	for (int i=0;i<ranges[i].size();i++)
	{
		int l = ranges[i].first.first;
		int r = ranges[i].first.second;
		int indx = ranges[i].second;
		query_ans[indx] = cur_ans;
	}
}