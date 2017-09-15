//AC
#include "bits/stdc++.h"
using namespace std;
int val[10]={2,7,2,3,3,4,2,5,1,2};
int findV(char c)
{
	return val[c-'0'];
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	char f,s;
	cin>>f>>s;
	cout<<findV(f)*findV(s);
}