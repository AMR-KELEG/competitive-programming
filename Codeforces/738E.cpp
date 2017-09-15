//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,root;
	scanf("%d%d",&n,&root);
	root--;
	std::vector<int> parents(n);
	int fakeRoot=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&parents[i]);
		if(i==root)
		{
			if(parents[i]!=0)
			{
				ans++;
				parents[i]=0;
			}
		}
		else if(parents[i]==0)
		{
			parents[i]=n;
			ans++;
			fakeRoot++;
		}
	}
	sort(parents.begin(), parents.end());
	
	int lastlevel=-1;
	int Max=parents.size()-1;
	for(int i=0;i<parents.size();i++)
	{
		if(parents[i]<=lastlevel || parents[i]==lastlevel+1)
		{
			lastlevel=max(parents[i],lastlevel);
		}
		else if(fakeRoot)
		{
			fakeRoot--;
			lastlevel++;
			parents[Max--]=lastlevel;
			i--;
		}
		else
		{
			ans++;
			lastlevel++;
			parents[Max--]=lastlevel;
			i--;
		}
	}
	cout<<ans;
}