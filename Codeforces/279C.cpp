#include <bits/stdc++.h>
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m;
	cin>>n;
	cin>>m;
	vector<int>l(n),a(n),boundary(n,0),rboundary(n,0);
	int cur=1;
	l[0]=1;
	bool inc=1;
	cin>>a[0];
	for(int i=1;i<n;i++)
	{
		cin>>a[i];
		if(inc)
		{
			if(a[i]>=a[i-1])
			{
				l[i]=cur;
			}
			else
			{
				inc=0;
				l[i]=cur;
			}
		}
		else
		{
			if(a[i]<=a[i-1])
			{
				l[i]=cur;
			}
			else
			{
				cur++;
				l[i]=cur;
				inc=1;
				boundary[i-1]=1;
			}
		}
		
	}
	reverse(a.begin(),a.end());
	vector<int>rl(n);
	cur=1;
	rl[0]=cur;
	inc=1;
	for(int i=1;i<n;i++)
	{
		if(inc)
		{
			if(a[i]>=a[i-1])
			{
				rl[i]=cur;
			}
			else
			{
				inc=0;
				rl[i]=cur;
			}
		}
		else
		{
			if(a[i]<=a[i-1])
			{
				rl[i]=cur;
			}
			else
			{
				rboundary[i-1]=1;
				cur++;
				rl[i]=cur;
				inc=1;
			}
		}
		
	}
	int le,ri;
	
	for(int i=0;i<m;i++)
	{
		cin>>le>>ri;
		le--;
		ri--;

		//if(l[le]==l[ri] || rl[n-1-le]==rl[n-1-ri] || ( (l[le]+1==l[ri]) && boundary[le]) || ( abs(rl[n-1-le]-=rl[n-1-ri])==1 && boundary[n-1-ri] ) )
		if(l[le]==l[ri] || rl[n-1-le]==rl[n-1-ri] || ( (l[le]+1==l[ri]) && boundary[le]) || ( rl[n-1-le]==1+rl[n-1-ri] && rboundary[n-1-ri] ) )		
		cout<<"Yes\n";
		else
		cout<<"No\n";
	}
	return 0;
}