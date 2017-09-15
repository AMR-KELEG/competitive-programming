#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("A-large.in","r",stdin);
		freopen("A-large.out","w",stdout);
	#endif
	int T;
	cin>>T;
	int n,p;
	for(int t=1;t<=T;t++)
	{
		int ans=0;
		cin>>n>>p;
		if(p==2)
		{
			int g;
			int e=0,o=0;
			while(n--)
			{
				cin>>g;
				if(g%2)
					o++;
				else
					e++;
			}
			ans=e+ceil(o/2.0);
		}
		else if(p==3)
		{
			int g;
			int r1=0,r2=0;
			while(n--)
			{
				cin>>g;
				if(g%3==0)
					ans++;
				else if(g%3==1)
					r2++;
				else
					r1++;
			}
			if(r1>=r2)
			{
				r1-=r2;
				ans+=(r2);
				r2=0;
			}
			else
			{
				r2-=r1;
				ans+=(r1);
				r1=0;	
			}
			ans+=r1/3;
			r1=r1%3;
			ans+=r2/3;
			r2=r2%3;
			if(r1>0 || r2>0)
				ans++;			
		}
		else
		{
			int g;
			int r1=0,r2=0,r3=0;
			while(n--)
			{
				cin>>g;
				if(g%4==0)
					ans++;
				else if(g%4==1)
					r3++;
				else if(g%4==2)
					r2++;
				else
					r1++;
			}
			ans+=(r2/2);
			r2=r2%2;
			if(r1>=r3)
			{
				r1-=r3;
				ans+=(r3);
				r3=0;
			}
			else
			{
				r3-=r1;
				ans+=(r1);
				r1=0;	
			}	
			r1=max(r1,r3);
			if(r1>0 && r2>0)
			{
				if(r1>1)
				{
					ans++;
					r2=0;
					r1-=2;
				}
				ans+=(r1/4);
				r1=r1%4;
				ans+=(r1>0);	
			}
			else if(r1>0)
			{
				ans+=(r1/4);
				r1=r1%4;
				ans+=(r1>0);
			}
		}
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
}