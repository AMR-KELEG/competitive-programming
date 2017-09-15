//AC
#include "bits/stdc++.h"
using namespace std;
long long int n;
long long int counter=0;
void inc(long long int no)
{
	if(no>n)
		return;
	counter++;
	inc(no*10);
	inc((no*10)+1);
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n;	
	inc(1);
	cout<<counter;
}