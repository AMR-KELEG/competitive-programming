/* AC
Find the maximum three values in range of two successive 0
Push these values to stack, queue, queueFront
Push remaining values to queueBack (NEGLECTED)
*/
#include "bits/stdc++.h"
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	scanf("%d", &n);
	// 0 -> Extraction
	int no = 0;
	// req are indecies of stack queue and queueFront
	std::vector<string> ans(n, "pushBack");
	priority_queue<pair<int,int> >q;
	string st[]={"pushStack","pushQueue","pushFront"};
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d", &a);
		if (a==0)
		{
			// pop
			if (q.empty())
			{
				ans[i] = "0";
			}
			else if (q.size()==1)
			{
				ans[i] = "1 popStack";
				for (int _=0;_<1;_++)
				{
					ans[q.top().second] = st[_];
					q.pop();
				}
			}
			else if (q.size()==2)
			{
				ans[i] = "2 popStack popQueue";
				for (int _=0;_<2;_++)
				{
					ans[q.top().second] = st[_];
					q.pop();
				}
			}
			else
			{
				ans[i] = "3 popStack popQueue popFront";
				for (int _=0;_<3;_++)
				{
					ans[q.top().second] = st[_];
					q.pop();
				}
				while(!q.empty())
					q.pop();
			}
		}
		else
		{
			q.push({a,i});
		}
	}
	for (auto s:ans)
	{
		printf("%s\n", s.c_str());
	}
}