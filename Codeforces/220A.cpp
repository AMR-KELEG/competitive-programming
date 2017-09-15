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
	std::vector<int> a(n),b;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}	
	long long int counter=0;
	b=a;
	sort(b.begin(), b.end());
	for(int i=0;i<n;i++)
	{
		if(a[i]!=b[i])
		{
			counter++;
		}
	}
	if(counter<=2)
		cout<<"YES";
	else
		cout<<"NO";
}