//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,a,b,T;
	cin>>n>>a>>b>>T;
	string ori;
	cin>>ori;
	
	std::vector<long long int> RCost(n,0); // you are at 1
	int min_cost = 1;
	if (ori[0] == 'w')
		min_cost += b;
	
	if (min_cost >T)
	{
		cout<<0;
		return 0;
	}
	T -= min_cost;
	RCost[0] = 0;
	int ans =1;
	for (int i=1;i<n;i++)
	{
		RCost[i] = 1 + a + RCost[i-1];
		if (ori[i] == 'w')
			RCost[i] += b;
		if (RCost[i] <=T)
			ans = i+1;
	}
	std::vector<long long int> LCost(n,0); // 0 is n and n-1 is 1
	LCost[0] = 0;
	for (int i=1;i<n;i++)
	{
		LCost[i] =LCost[i-1] + 1+a;
		if (ori[n-i] == 'w')
			LCost[i] += b;
		if (LCost[i] <=T)
		{
			ans = max(ans,i+1);
		}
	}

	for (int i=1;i<n;i++)
	{
		long long int req_to_return_to_1 = LCost[i] + (i)*(a);
		long long int rem_t = T - req_to_return_to_1;
		if (rem_t>=0)
		{
			// cout<<"Left "<<i<<endl;
			int cur_ans = i + 1+
				(lower_bound(RCost.begin(), RCost.end(),rem_t) - RCost.begin());
			int val = * (lower_bound(RCost.begin(), RCost.end(),rem_t));
			if (val !=rem_t)
				cur_ans--;
			
			// for (int j=0;j<RCost.size();j++)
			// 	cout<<RCost[j]<<" ";
			// cout<<endl;
			// cout<<rem_t<<" "<<*(lower_bound(RCost.begin(), RCost.end(),rem_t))<<" "<<(lower_bound(RCost.begin(), RCost.end(),rem_t) - RCost.begin())<<endl;
			// cout<<endl;
			ans = max(ans,cur_ans);
		}
		req_to_return_to_1 = RCost[i] + (i)*a;
		rem_t = T - req_to_return_to_1;
		if (rem_t>=0)
		{
			// cout<<"Right "<<i<<endl;
			int cur_ans = i + 1 +
				(lower_bound(LCost.begin(), LCost.end(),rem_t) - LCost.begin());
			int val = * (lower_bound(LCost.begin(), LCost.end(),rem_t));
			if (val !=rem_t)
				cur_ans--;
			ans = max(ans,cur_ans);
			// cout<<val<<" "<<rem_t<<endl;
			// for (auto c:LCost)
			// 	cout<<c<<" ";
			// cout<<endl;
			// cout<<rem_t<<" "<<*(lower_bound(LCost.begin(), LCost.end(),rem_t))<<
			// " "<<(lower_bound(LCost.begin(), LCost.end(),rem_t) - LCost.begin())<<endl;
		}
	}
	if (ans>n)
		ans = n;
	cout<<ans;
}	