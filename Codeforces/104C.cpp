#include "bits/stdc++.h"
using namespace std;
std::vector<int> rep,setsize,setedges;
int find(int a)
{
	if(a!=rep[a])
		rep[a]=find(rep[a]);
	return rep[a];
}

void join(int a,int b)
{
	int pa=find(a);
	int pb=find(b);
	if(pa<pb)
	{
		rep[pb]=pa;
		setsize[pa]+=setsize[pb];
		setedges[pa]+=setedges[pb]+1;
		setedges[pb]=0;
		setsize[pb]=0;
	}
	else
	{
		rep[pa]=pb;
		setsize[pb]+=setsize[pa];
		setedges[pb]+=setedges[pa]+1;
		setedges[pa]=0;
		setsize[pa]=0;	
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;
	rep=std::vector<int> (n+5);
	setsize=std::vector<int> (n+5,1);
	setedges=std::vector<int> (n+5,0);
	int a,b;
	for(int i=1;i<=n;i++)
		rep[i]=i;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		if(find(a)!=find(b))
		{
			join(a,b);	
		}
	}
	int sets=0;
	bool ok=1;

	for(int i=1;i<=n;i++)
		cout<<setsize[i]<<" "<<setedges[i]<<endl;
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		//cout<<setsize[i]<<" "<<setedges[i]<<endl;
		if( (setsize[i]==setedges[i]+1) || setsize[i]==0)
		{
			sets++;
		}
		else
		{
			ok=0;
			break;
		}
	}
	cout<<sets<<endl;
	if(!ok || (ok && sets<=3))
	{
		cout<<"NO";
	}
	else
	{
		cout<<"FHTAGN!";
	}

}