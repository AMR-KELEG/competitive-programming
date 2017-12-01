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
	priority_queue<int>q;
	long long int tot = 0;
	for (int i=0;i<n;i++)
	{
		int no;
		cin>>no;
		tot += no;
		if (i%2 == 0)
		{
			q.push(-no);
		}
		else
		{
			if (!q.empty() && no>-q.top())
			{
				q.pop();
				q.push(-no);
			}
		}
	}	
	long long int jack = 0;
	while(!q.empty())
	{
		jack += -q.top();
		q.pop();
	}
	cout<<jack<<" "<<tot-jack;
}