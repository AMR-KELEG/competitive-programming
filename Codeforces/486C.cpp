#include "bits/stdc++.h"
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
	   freopen("in.txt","r",stdin);
    #endif
	std::ios::sync_with_stdio(false);
	int n,p;
	cin>>n>>p;
	p--;
	string s;
	cin>>s;
	if(p>=(n/2))
	{
		reverse(s.begin(), s.end());
		p=n-p-1;
	}
	long long int r=(1<<29);
	long long int l=1<<29;
	long long int op=0;
	if(s[p]!=s[n-p-1])
	{
		op+=min(abs(s[n-p-1]-s[p]),abs((26+min(s[n-p-1],s[p]))-max(s[n-p-1],s[p])));
		//cout<<p<<" "<<op<<endl;
	}
	for(int i=p+1;i<n/2;i++)
	{
		if(s[i]!=s[n-1-i])
		{
			op+=min(abs(s[n-i-1]-s[i]),abs((26+min(s[n-i-1],s[i]))-max(s[n-i-1],s[i])));
			//cout<<i<<" "<<op<<endl;
			s[i]=s[n-1-i];
			r=i;
		}
	}
	for(int i=p-1;i>=0;i--)
	{
		if(s[i]!=s[n-1-i])
		{
			op+=min(abs(s[n-i-1]-s[i]),abs((26+min(s[n-i-1],s[i]))-max(s[n-i-1],s[i])));
			//cout<<i<<" "<<op<<endl;
			s[i]=s[n-1-i];
			l=i;
		}
	}
	if(l==(1<<29))
	{
		if(r!=(1<<29))
		{
			for(int i=p+1;i<=r;i++)
			{
				op++;
				//cout<<i<<" "<<op<<endl;
			}
		}
	}
	else if(r==(1<<29))
	{
		if(l!=(1<<29))
		{
			for(int i=p-1;i>=l;i--)
			{
				op++;
				//cout<<i<<" "<<op<<endl;
			}
		}
	}
	else if(abs(l-p)<abs(r-p))
	{
		//go to the left first
		int i;
		for(i=p-1;i>=l;i--)
		{
				op++;
				//cout<<i<<" "<<op<<endl;
		}
		i+=2;
		for(;i<=r;i++)
		{
			op++;
			//cout<<i<<" "<<op<<endl;
		}
	}
	else
	{
		int i;
		for(i=p+1;i<=r;i++)
		{
			op++;
			//cout<<i<<" "<<op<<endl;
		}
		i-=2;
		for(;i>=l;i--)
		{
			op++;
			//cout<<i<<" "<<op<<endl;
		}
	}
	cout<<op;
}