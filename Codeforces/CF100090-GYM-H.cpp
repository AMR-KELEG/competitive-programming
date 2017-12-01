/* AC
Pattern
The largest pile determines the solution of the game
*/

#include "bits/stdc++.h"
using namespace std;

/*
int gr[100];
int solve(int rem)
{
	if (rem==1)
		return 0;
	if (gr[rem]!=-1)
		return gr[rem];
	set<int>s;
	for (int new_pile = rem-1;new_pile>=round(0.5*rem);new_pile--)
	{
		s.insert(solve(new_pile));
	}
	for (int i=0;i<1000;i++)
	{
		if (s.find(i)==s.end())
			return gr[rem] = i;
	}
}
*/

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	/*
	memset(gr, -1, sizeof gr);
	for (int i=1;i<100;i++)
	{
		// cout<<"Pile "<<i<<" Has Gr "<<solve(i)<<endl;
		if(!solve(i))
			cout<<i<<endl;
	}
	return 0;
	*/
	set<int> losing_pos;
	int cur = 1;
	while(cur<=1000000000)
	{
		losing_pos.insert(cur);
		cur = (2*cur)+1;
	}
	int n;
	cin>>n;
	int max_val = 0;
	for (int i=0,a;i<n;i++)
	{
		cin>>a;
		max_val = max(max_val, a);
	}
	if (losing_pos.find(max_val)==losing_pos.end())
		cout<<"Constantine";
	else
		cout<<"Mike";
}