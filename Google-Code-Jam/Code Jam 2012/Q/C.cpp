#include "bits/stdc++.h"
using namespace std;
int find_next(int &n)
{
	int d=0;
	int tem=n;
	while(tem>0)
	{
		tem/=10;
		d++;
	}
	n=(n/10)+((n%10)*ceil(pow(10,d-1)));
	return n;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		//B-small-practice
		// freopen("B-large-practice.in","r",stdin);
		// freopen("b-large.txt","w",stdout);
	#endif
	int T;
	cin>>T;
	int l,r;
	for(int test=1;test<=T;test++)
	{
		cout<<"Case #"<<test<<": ";
		//n s p t
		cin>>l>>r;
		for(int i=l;i<=r;i++)
		{
			
		}
		cout<<find_next(l);
		cout<<endl;	
	}
}