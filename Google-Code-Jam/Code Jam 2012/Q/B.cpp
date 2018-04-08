//AC
#include "bits/stdc++.h"
using namespace std;
int n,s,p,t;
bool check(int t)
{
	if(t%3==0)
	{
		if((t/3)>=p)
			return 1;
	}
	if((t+1)%3==0 && ((t+1)/3)>=p && (((t+1)/3)-1)>=0)
	{
		return 1;
	}
	if((t+2)%3==0 && ((t+2)/3)>=p && (((t+2)/3)-1)>=0)
	{
		return 1;
	}
	if(s>0)
	{
		if((t+4)%3==0 && ((t+4)/3)>=p && (((t+4)/3)-2)>=0)
		{
			s--;
			return 1;
		}
		if((t+3)%3==0 && ((t+3)/3)>=p && (((t+3)/3)-2)>=0)
		{
			s--;
			return 1;
		}
	}
	return 0;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		//B-small-practice
		freopen("B-large-practice.in","r",stdin);
		freopen("b-large.txt","w",stdout);
	#endif
	int T;
	cin>>T;
	for(int test=1;test<=T;test++)
	{
		cout<<"Case #"<<test<<": ";
		//n s p t
		int ans=0;
		cin>>n>>s>>p;
		for(int i=0;i<n;i++)
		{
			cin>>t;
			ans+=check(t);
		}
		cout<<ans<<endl;	
	}
}