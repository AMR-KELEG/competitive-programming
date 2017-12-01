//AC
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
	queue<int>q;
	for (int i=0,no;i<n;i++)	
	{
		cin>>no;
		q.push(no);
	}
	int no = -1;
	int c=0;
	std::vector<int> co;
	std::vector<int> val;
	while(!q.empty())
	{
		if (c==0)
		{
			no = q.front();
			c = 1;
		}
		else if (no == q.front())
		{
			c++;
		}
		else
		{
			co.push_back(c);
			val.push_back(no);
			no = q.front();
			c = 1;
		}
		q.pop();
	}
	if (c)
	{
		co.push_back(c);
		val.push_back(no);
	}
	printf("%d %d", co[0], val[0]);
	for (int i=1;i<co.size();i++)
	{
		printf(" %d %d", co[i], val[i]);
	}
}