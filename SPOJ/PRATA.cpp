// AC
#include "bits/stdc++.h"
using namespace std;
int p;
std::vector<int> cooks;
bool valid(int t){
	int ans = 0;
	for (auto c:cooks)
	{
		long double cur_ans = (-1 + sqrt(1+8.0*(t/c)))/(2.0);
		ans+= cur_ans;
	}
	return ans>=p;	
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
		cin>>p;
		int n;
		cin>>n;
		cooks = std::vector<int>(n);
		for (int i=0;i<n;i++)
		{
			cin>>cooks[i];
		}
		int l=1,r=10000000;
		while(l<r)
		{
			int mid = (l+r)>>1;
			if (valid(mid))
			{
				r = mid;
			}
			else
			{
				l = mid+1;
			}
		}
		int ans = (l+r)>>1;
		cout<<ans<<endl;
	}	
}