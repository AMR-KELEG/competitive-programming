#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	string s;
	cin>>s;
	long long int index=s.find("bear");
	long long int count=0;
	while(index!=-1)
	{
		count+=(index+1)*(s.size()-(index+3));
		s=s.substr(index+1);
		index=s.find("bear");
	}	
	cout<<count;
}