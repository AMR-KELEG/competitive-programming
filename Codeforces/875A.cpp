// AC
#include "bits/stdc++.h"
using namespace std;
int find_sum(int n)
{
	if (n==0)
		return 0;
	int ans = 0;
	while(n)
	{
		ans+= n%10;
		n/=10;
	}
	return ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	set<int>s;
	for (int diff = 0;diff<=90;diff++)
	{
		int x = n-diff;
		int s_x = find_sum(x);
		if (s_x == diff && x>0)
		{
			s.insert(x);
		}
	}	
	printf("%d\n", (int)s.size());
	for (auto no:s)
		printf("%d ", no);
}