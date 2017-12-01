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
	long long int k;
	cin>>n>>k;
	queue<pair<int,int> >q;	// player, wins
	for (int i=0,a;i<n;i++)
	{
		cin>>a;
		q.push({a,0});
	}
	int cur_top = q.front().first;
	int cur_wins = q.front().second;
	q.pop();
	while(!q.empty())
	{
		if (cur_top==n)
		{
			printf("%d\n", n);
			return 0;
		}
		if (cur_wins == k)
		{	
			printf("%d\n", cur_top);
			return 0;
		}
		int p = q.front().first;
		int wins = q.front().second;
		q.pop();
		if (cur_top<p)
		{
			swap(cur_top, p);
			swap(cur_wins, wins);
		}
		q.push({p,wins});
		cur_wins++;
	}
}