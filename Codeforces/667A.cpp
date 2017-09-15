//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int n,h;
	cin>>n>>h;
	int a;
	int count=0;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(a>h)
			count+=2;
		else
			count++;
	}
	cout<<count;
}