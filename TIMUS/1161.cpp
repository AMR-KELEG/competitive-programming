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
	priority_queue<long double>q;
	for (int i=0,no;i<n;i++)
	{
		cin>>no;
		q.push(no);
	}	
	while(!q.empty() && q.size()>1)
	{
		long double v1 = q.top();
		q.pop();
		long double v2 = q.top();
		q.pop();
		long double v = 2* sqrt(v1*v2);
		q.push(v);
	}
	printf("%0.2LF\n", q.top());
}