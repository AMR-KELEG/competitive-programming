#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,c;
	cin>>n>>c;
	int lastin=0,curin,words=0;
	for(int i=0;i<n;i++)
	{
		cin>>curin;
		if(curin-lastin>c)
		{
			words=1;
		}
		else
			words++;
		lastin=curin;
	}
	cout<<words;
}