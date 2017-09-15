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
	priority_queue<pair<pair<int,int>,int>>q;//max(a,b) -steps min(a,b) 
	q.push({{1,0},1});
	int ans=1000000;
	while(!q.empty())
	{
		int a=q.top().first.first;
		int steps=q.top().first.second;
		int b=q.top().second;
		q.pop();
		if(steps>=ans)
			continue;
		if(a==n)
		{
			ans=min(ans,-steps);
		}
		else if(a+b<=n)
		{
			q.push({{a+b,steps-1},b});
			q.push({{a+b,steps-1},a});
		}
	}
	cout<<ans;
}