#include "bits/stdc++.h"
using namespace std;
int main()
{
	int n;
	cin>>n;
	cout<<n<<" ";
	for(int i=n/2;i>=1;i--)
		if(n%i==0)cout<<i<<" ";
	return 0;
}