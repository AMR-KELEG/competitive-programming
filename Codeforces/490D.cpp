//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	int c21=0,c31=0;
	int c22=0,c32=0;
	long long int t1=a1,t2=b1;
	for(int i=2;i<4;i++)
	{
		while(t1%i==0)
		{
			if(i==2)
				c21++;
			else
				c31++;
			t1/=i;
		}	
		while(t2%i==0)
		{
			if(i==2)
				c21++;
			else
				c31++;
			t2/=i;
		}	
	}
	long long int val=t1*t2;
	t1=a2,t2=b2;
	for(int i=2;i<4;i++)
	{
		while(t1%i==0)
		{
			if(i==2)
				c22++;
			else
				c32++;
			t1/=i;
		}
		while(t2%i==0)
		{
			if(i==2)
				c22++;
			else
				c32++;
			t2/=i;
		}	
	}
	if(val!=t1*t2)
	{
		cout<<-1;
	}
	else
	{
		int r21=0,r22=0,r31=0,r32=0;
		if(c31>=c32)
		{
			r31=c31-c32;
			c21+=c31-c32;
		}
		else
		{
			r32=c32-c31;
			c22+=c32-c31;
		}
		if(c21>=c22)
		{
			r21=c21-c22;
		}
		else
		{
			r22=c22-c21;
		}
		cout<<r21+r22+r31+r32<<endl;
		while(r31)
		{
			if(a1%3==0)
			{
				a1/=3;
				a1*=2;
			}
			else
			{
				b1/=3;
				b1*=2;
			}
			r31--;
			// cout<<"1 "<<a1<<" "<<a2<<endl;
		}
		while(r32)
		{
			if(a2%3==0)
			{
				a2/=3;
				a2*=2;
			}
			else
			{
				b2/=3;
				b2*=2;
			}
			r32--;
		}
		while(r21)
		{
			if(a1%2==0)
			{
				a1/=2;
			}
			else
				b1/=2;
			r21--;
			// cout<<"1 "<<a1<<" "<<a2<<endl;
		}
		while(r22)
		{
			if(a2%2==0)
			{
				a2/=2;
			}
			else
				b2/=2;
			r22--;
		}
		cout<<a1<<" "<<b1<<endl<<a2<<" "<<b2;

	}

}