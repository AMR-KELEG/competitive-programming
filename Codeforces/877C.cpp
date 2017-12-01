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
	std::vector<int> moves;
	for (int i=2;i<=n;i+=2)
	{
		moves.push_back(i);
	}
	for (int i=1;i<=n;i+=2)
	{
		moves.push_back(i);
	}
	for (int i=2;i<=n;i+=2)
	{
		moves.push_back(i);
	}
	printf("%d\n", (int)moves.size());
	for (auto m:moves)
		printf("%d ", m);
}