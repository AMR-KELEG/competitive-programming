/* AC
- Greedily add person at last possible moment.
- Make sure there is always k persons or more at any time
- Make sure there is someone to handle the key to the person at n+m+1
- The pattern will be repeated after n+m (at n+m+1 == at 1)
*/
#include "bits/stdc++.h"
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m,k;
	scanf("%d %d %d",&n, &m, &k);
	std::vector<int> co(2*(n+m),0);
	int cur_indx = 1;
	queue<int>q;
	q.push(1);
	for (int i=1;i<=n;i++)
	{
		co[i]++;
	}
	while(cur_indx<=n+m)
	{
		if (co[cur_indx]>=k)
		{
			cur_indx++;
		}
		else if (co[cur_indx]==0)
		{
			q.push(cur_indx-1);
			for (int i=0;i<n;i++)
			{
				co[cur_indx+i-1]++;
			}
		}
		else
		{
			// add people here
			int no_of_added = k - co[cur_indx];
			for (int _=0;_<no_of_added;_++)
			{
				q.push(cur_indx);
			}
			for (int i=0;i<n;i++)
			{
				co[cur_indx+i]+=no_of_added;
			}
			cur_indx++;
		}
	}
	if (co[n+m+1]==0)
	{
		q.push(n+m);
	}
	printf("%d\n", (int)q.size());
	while(!q.empty())
	{
		printf("%d ", q.front());
		q.pop();
	}
}