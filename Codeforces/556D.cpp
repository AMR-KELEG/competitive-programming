//AC
#include "bits/stdc++.h"
using namespace std;
#define Segment pair<long long int,pair<long long int,int>>
//curl isin minlen indx
int main()
{
	// std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m;
	scanf("%d%d",&n,&m);
	if(m<n-1)
	{
		cout<<"No";
		return 0;
	}
	//for each segment carry l r 
	std::vector<pair<long long int,long long int> > seg(n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld",&seg[i].first,&seg[i].second);
	}
	multiset<pair<long long int,int>>bridges;
	long long int blen;
	for(int i=0;i<m;i++)
	{
		scanf("%lld",&blen);
		bridges.insert({blen,i});
	}
	//minlen maxlen indx
	vector<Segment>q(n-1);
	for(int i=1;i<n;i++)
	{
		// q.push({{seg[i].first-seg[i-1].second,1},{seg[i].first-seg[i-1].second,i-1}});
		q[i-1]={seg[i].second-seg[i-1].first,{seg[i].first-seg[i-1].second,i-1}};
	}
	sort(q.begin(), q.end());
	std::vector<int> bridgeIndx(n-1);
	bool invalid=0;
	int in=0;
	while(in<n-1)
	{
		Segment s=q[in];
		in++;
		long long int low=s.second.first,high=s.first;
		int indx=s.second.second;
		// cout<<"Curlen "<<s.first<<" mi?nlen "<<s.second.first<<endl;
		auto it=bridges.lower_bound({low,0});
		if(it==bridges.end() || it->first>high)
		{
			invalid=1;
			break;
		}
		else
		{
			bridgeIndx[indx]=it->second+1;
			bridges.erase(it);
		}
	}
	if(invalid)
	{
		cout<<"No";
	}
	else
	{
		printf("Yes\n");
		for(int i=0;i<n-1;i++)
		{
			printf("%d ", bridgeIndx[i]);
		}
	}
}