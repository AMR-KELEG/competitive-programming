// WA
// 6:50 -> DONE
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%d", &n);
		std::vector<int> p(n);
		for (int i=0,v;i<n;i++)
		{
			scanf("%d", &v);
			p[i] = v;
		}
		p.push_back(0);
		sort(p.begin(), p.end());
		int nim_val = 0;
		for (int i=1;i<p.size();i++)
		{
			nim_val ^= p[i]-p[i-1]-1;
		}
		if (nim_val)
		{
			printf("Georgia will win\n");
		}
		else
		{
			printf("Bob will win\n");
		}
	}
}