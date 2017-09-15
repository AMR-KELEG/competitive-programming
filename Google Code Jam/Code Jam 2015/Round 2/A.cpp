//AC (small/large)
#include "bits/stdc++.h"
using namespace std;
string ans;
int n,R,P,S;
int nr,np,ns;
bool solve(char par,int level,int l,int r)
{
	if(level==n)
	{
		if(par=='R')
			nr++;
		if(par=='P')
			np++;
		if(par=='S')
			ns++;
		ans[l]=par;
		return 1;
	}
	int nEl=r-l+1;
	if(par=='R')
	{
		solve('R',level+1,l,l-1+(nEl/2));
		solve('S',level+1,l+(nEl/2),r);
	}
	else if(par=='S')
	{
		solve('P',level+1,l,l-1+(nEl/2));
		solve('S',level+1,l+(nEl/2),r);
	}
	else if(par=='P')
	{
		solve('P',level+1,l,l-1+(nEl/2));
		solve('R',level+1,l+(nEl/2),r);
	}
	if(level==0)
	{
		return (nr==R && ns==S && np==P); 
	}
	return 1;

}

void sortAns(int l,int r)
{
	if(l==r)
		return ;
	int mid=(r-l+1)/2;
	// cout<<l<<" "<<r<<" "<<mid<<endl;
	sortAns(l,l+mid-1);
	sortAns(l+mid,r);
	for(int j=l;j<l+mid;j++)
	{
		if(ans[j]>ans[j+mid])
		{
			//do the swap
			for(int i=l;i<l+mid;i++)
			{
				// cout<<l<<" "<<i<<" "<<i+mid-1<<" "<<r<<endl;
				swap(ans[i],ans[i+mid]);
			}
			j=l+mid;
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("A-large-practice.in","r",stdin);
		freopen("A-large-practice.out","w",stdout);
	#endif
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		cin>>n>>R>>P>>S;
		int N = ceil(pow(2,n));
		ans=string(N,'x');
		char cand[]="RPS";
		bool done = false;
		for(int i=0;i<3;i++)
		{
			nr=0;ns=0;np=0;
			if(solve(cand[i],0,0,N-1))
			{
				done=1;
				sortAns(0,N-1);
				cout<<"Case #"<<t<<": "<<ans<<endl;
				break;
			}
		}
		if(!done)
		{
			cout<<"Case #"<<t<<": IMPOSSIBLE\n";
		}

	}
		
}