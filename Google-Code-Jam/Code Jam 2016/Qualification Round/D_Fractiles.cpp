#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("D-large.in","r",stdin);
		freopen("D.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	unsigned long long int k,c,s,ans,add;
	for(int te=1;te<=t;te++)
	{
		cin>>k>>c>>s;
		cout<<"Case #"<<te<<": ";
		if(c==1 && s<k)
		{	
			cout<<"IMPOSSIBLE\n";
		}
		else if(c==1 && s==k)
		{
			ans=1;
			for(int mul=1;mul<c;mul++)
				ans*=k;
			add=ans;
			for(int i=1;i<=k;i++)
			{
				cout<<ans<<" ";
				ans+=add;
			}
			cout<<endl;	
		}
		else if(s<ceil(0.5*k))
		{
			cout<<"IMPOSSIBLE\n";
		}
		else
		{
			ans=1;
			for(int mul=1;mul<c;mul++)
				ans*=k;
			add=ans;
			for(int i=1;i<=ceil(0.5*k);i++)
			{
				cout<<ans<<" ";
				add--;
				ans+=add;
			}
			cout<<endl;
		}
	}	
}