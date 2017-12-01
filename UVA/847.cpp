// AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	std::vector<long long int> v;
	long long int val = 1;
	bool mult_by_two = 0;
	while(val<10000000000000LL)
	{
		if (mult_by_two)
			val*=2;
		else
			val*=9;
		mult_by_two = ! mult_by_two;
		v.push_back(val);
	}
	unsigned int n;
	while (cin>>n)
	{
		int indx = lower_bound(v.begin(), v.end(), n) - v.begin();
		if (indx%2)
			printf("Ollie wins.\n");
		else
			printf("Stan wins.\n");
	}
}