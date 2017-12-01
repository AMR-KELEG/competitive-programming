// AC
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
		int n;
		cin>>n;
		std::vector<int> v(n);
		for (int i=0;i<n;i++)
			cin>>v[i];
		sort(v.begin(), v.end());
		stack<int>st;
		std::vector<int> ans(n);
		ans[0] = v[0];
		int j=1;
		for (int i=1;i<n;i++)
		{
			if(v[i] == ans[j-1])
			{
				st.push(v[i]);
			}
			else
			{
				ans[j++] = v[i];
			}
		}
		int inv = 0;
		int last = -1;
		while(!st.empty())
		{
			if (st.top()==last)
				inv++;
			last = st.top();
			st.pop();
		}
		printf("%d\n", inv);
	}	
}