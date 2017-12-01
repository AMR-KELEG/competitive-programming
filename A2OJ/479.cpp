//AC
#include "bits/stdc++.h"
using namespace std;

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
		std::vector<int> scores(n);
		for (int i=0;i<n;i++)
		{
			cin>>scores[i];
		}
		sort(scores.rbegin(), scores.rend());
		int ans = 0;
		for (int i=0;i<n;i++)
		{
			if (scores[i]>=scores[m-1] && scores[i])
			{
				ans++;
			}
			else
				break;
		}
		cout<<ans<<endl;
	}
}