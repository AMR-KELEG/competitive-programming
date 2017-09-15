#include "bits/stdc++.h"
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;
	long long int odd=(x2-x1)/2;
	long long int even=(x2-x1)/2;
	if(x1%2)
		odd++;
	else
		even++;
	cout<<odd<<" "<<even<<endl;
	cout<<(odd*(1+((y2)/2)))+(even*((1+y2)/2))-(odd*(1+((y1)/2)))+(even*((1+y1)/2));	
}