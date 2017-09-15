//AC -- 1 is a GCD 
#include "bits/stdc++.h"
using namespace std;
int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int a,b;
	cin>>a>>b;
	int GCD=gcd(a,b);
	std::set<int> div;
	div.insert(GCD);
	div.insert(1);
	for(int i=2;i*i<=GCD;i++)
	{
		if(GCD%i==0)
		{
			div.insert(i);
			div.insert(GCD/i);
		}
	}
	/*
	for(set<int>::iterator it=div.begin();it!=div.end();it++)
		cout<<*it<<" ";
	cout<<endl;
	*/
	int n;
	cin>>n;
	int x,y;
	set<int>::iterator it2;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		it2=div.upper_bound(y);
		it2--;
		if(*it2 >=x && it2!=div.end())
			cout<<*it2<<endl;
		else
			cout<<-1<<endl;
		/*
		if(it==div.end())
			cout<<-1<<endl;
		else if(*it<=y)
		{
			if(div.find(y)!=div.end())
				cout<<y<<endl;
			else
				cout<<*it<<endl;
		}
		else
			cout<<-1<<endl;
			*/
	}
}