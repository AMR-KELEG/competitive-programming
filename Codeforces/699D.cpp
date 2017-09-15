//AC
#include "bits/stdc++.h"
using namespace std;
int n;
std::vector<int> p;
/*
	check if both belong to the same set


*/

int find(int i)
{
	if(p[i]==i)
		return i;
	return p[i]=find(p[i]);
}
void merge(int f,int s)
{
	int p1=find(f);
	int p2=find(s);
	if(p1<p2)
	{
		p[p2]=p1;
		return;
	}
	p[p1]=p2;
}

int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	cin>>n;
	vector<int>par=std::vector<int> (n+1);
	p=std::vector<int> (n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>par[i];
		p[i]=i;
	}

	std::vector<bool> con(n+1,0);
	int root=-1;
	for(int i=1;i<=n;i++)
	{
		if(par[i]==i)
		{
			root=i;
			break;
			con[i]=1;
		}
	}

	int c=0;
	for(int i=1;i<=n;i++)
	{
		if(i==root)
			continue;
		if(i==par[i])
		{
			c++;
			if(root==-1)
			{
				root=i;
			}
			par[i]=root;
			merge(i,root);
		}
		else if(find(i)==find(par[i]))
		{
			// same set
			c++;
			if(root==-1)
			{
				root=i;
			}
			par[i]=root;
			merge(i,root);
		}
		else
		{
			merge(i,par[i]);
		}
	}
	printf("%d\n", c);
	for(int i=1;i<=n;i++)
		printf("%d ", par[i]);

}