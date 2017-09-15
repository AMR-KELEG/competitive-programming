//AC
#include "bits/stdc++.h"
#define EPS 0.0000000000001
using namespace std;
std::vector<long double> v;
long double newVal(long double oldVal,long double mult,long double p)
{
	return (oldVal*(1-p))+(p*mult);
}
long double solve(int last)
{
	int l=0;
	int r=last;
	long double ans=0;
	long double curAns=0;
	long double mult=1;
	while(l<=r)
	{
		if(newVal(curAns,mult,v[l])>newVal(curAns,mult,v[r]))
		{
			curAns=newVal(curAns,mult,v[l]);
			mult*=(1-v[l]);
			l++;
		}
		else
		{
			curAns=newVal(curAns,mult,v[r]);
			mult*=(1-v[r]);
			r--;	
		}
		ans=max(ans,curAns);
	}
	return ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	long double ans=0;
	v=std::vector<long double> (n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	sort(v.begin(), v.end());
	for(int last=n-1;last>=0;last--)
	{
		ans=max(ans,solve(last));
	}
	cout<<std::fixed<<setprecision(12)<<ans;
}