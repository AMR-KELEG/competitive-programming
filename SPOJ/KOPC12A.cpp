//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<int> h,c;

long long int cost(long long int H)
{
	long long int ans =0;
	for(int i=0; i<h.size(); i++)
	{
		ans+= abs(H-h[i])*c[i];
	}
	return ans;
}

long long int ter_search(int l,int r)
{
	if(r-l<3)
	{
		// try each one
		long long int ans_cost = cost(l);
		for(int i=l+1;i<=r;i++)
		{
			long long int cur_cost = cost(i);
			if (cur_cost<ans_cost)
			{
				ans_cost =  cur_cost;
			}
		}
		return ans_cost;
	}
	int mid1 = l+(r-l)/3;
	int mid2 = r-(r-l)/3;
	if(cost(mid1)>=cost(mid2))
	{
		return ter_search(mid1,r);
	}
	return ter_search(l,mid2);
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		h = std::vector<int> (n);
		c = std::vector<int> (n);
		for(int i=0;i<n;i++)
		{
			cin>>h[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>c[i];
		}
		cout<<ter_search(0,10000)<<endl;
	}	
}