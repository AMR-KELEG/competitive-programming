//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<int> rep;
std::stack<pair<int,int> > spareroads;
stack<int>newroads;
std::vector<string> out;
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
	if(pa<pb)
	{
		rep[pb]=pa;
	}
	else
	{
		rep[pa]=pb;
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	rep=std::vector<int> (n+5);
	for(int i=1;i<=n;i++)
		rep[i]=i;
	int a,b;
	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b;
		if(find(a)==find(b))
		{
			//same set
			spareroads.push(pair<int,int>(a,b));
		}
		else
		{
			join(a,b);
		}
		/*
		for(int j=1;j<=n;j++)
			cout<<j<<" ";
		cout<<endl;
		for(int j=1;j<=n;j++)
			cout<<rep[j]<<" ";
		cout<<endl<<endl;
		*/
	}
	pair<int,int>oldroad;
	for(int i=2;i<=n;i++)
	{
		//cout<<find(1)<<" "<<find(i)<<endl;
		if(find(i)!=find(1))
		{
			//cout<<i<<endl;
			join(i,1);
			newroads.push(i);
		}
	}
	cout<<newroads.size()<<endl;
	while(!newroads.empty())
	{
		oldroad=spareroads.top();
		spareroads.pop();
		cout<<oldroad.first<<" "<<oldroad.second<<" "<<1<<" "<<newroads.top()<<endl;
		newroads.pop();
	}
}