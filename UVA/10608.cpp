//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<int> rep,setsize;
int find(int i)
{
	if(i!=rep[i])
		rep[i]=find(rep[i]);
	return rep[i];
}
void join(int a,int b)
{
	int pa=find(a);
	int pb=find(b);
	if(pb>pa)
	{
		rep[pb]=pa;
		if(setsize[pa]==0)
			setsize[pa]++;
		if(setsize[pb]==0)
			setsize[pb]++;
		setsize[pa]+=setsize[pb];
		setsize[pb]=0;
	}
	else
	{
		rep[pa]=pb;
		if(setsize[pa]==0)
			setsize[pa]++;
		if(setsize[pb]==0)
			setsize[pb]++;
		setsize[pb]+=setsize[pa];
		setsize[pa]=0;	
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	int n,m,a,b;
	while(t--)
	{
		cin>>n>>m;
		rep=std::vector<int> (n+5,0);
		for(int i=1;i<=n;i++)
			rep[i]=i;
		setsize=std::vector<int> (n+5,0);
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			if(find(a)!=find(b))
				join(a,b);
			else if(setsize[find(a)]==0)
				setsize[find(a)]++;
		}
		int maxsize=0;
		for(int i=1;i<=n;i++)
			maxsize=max(maxsize,setsize[i]);
		cout<<maxsize<<endl;
	}	
}