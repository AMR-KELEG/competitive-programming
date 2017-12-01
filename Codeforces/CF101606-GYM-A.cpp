// AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	std::vector<int> h(n);
	std::vector<int> ri(n);
	std::vector<int> se(n);
	int max_h = 0;	
	for (int i=0;i<n;i++)
	{
		cin>>h[i]>>ri[i]>>se[i];
		max_h = max(max_h, h[i]);
	}
	for (int d=0;d<1825*max_h;d++)
	{
		int n_d = 0;
		for(int i=0;i<n;i++)
		{
			int cur_h = d%h[i];
			if (ri[i]<se[i])
			{
				if (! (cur_h>ri[i] && cur_h<se[i]))
					n_d++;
			}
			else
			{
				if (cur_h>=se[i] && cur_h<=ri[i])
				{
					n_d++;
				}
			}
		}
		if (n_d == n)
		{
			cout<<d;
			return 0;
		}
	}
	cout<<"impossible";
}