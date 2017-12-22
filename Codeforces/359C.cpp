/* AC [Ladder C #66] 
Preprocessing: Combine each x terms of the same power (p) to a single term
of power (p+1)
GCD(Answer) is x^min(min_power, sum_powers)
*/

#include "bits/stdc++.h"
#define MOD (1000000007)
using namespace std;
int modPow(int x,long long int p)
{
	if(p==0)
		return 1;
	if(p==1)
		return x;
	long long int ans=modPow(x,p/2);
	ans=(ans*ans)%MOD;
	if(p%2)
		ans=(ans*x)%MOD;
	return ans;
}


int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,x;
	cin>>n>>x;
	std::vector<int> a(n);
	long long int a_sum =0;
	for(int i=0,v;i<n;i++)
	{
		cin>>v;
		a_sum += v;
		a[i] = v;
	}	
	priority_queue<long long int>q;
	for (int i=0;i<n;i++)
	{
		q.push(-(a_sum - a[i]));
	}
	queue<long long int> values;
	long long int cur_power = -1;
	int cur_count = 0;
	while(!q.empty())
	{
		if (cur_power==-1)
		{
			cur_power = -q.top();
			cur_count = 1;
			q.pop();
		}
		else if (cur_power == -q.top())
		{
			cur_count++;
			q.pop();
			if (cur_count %x ==0)
			{
				q.push(-(cur_power+1));
				cur_power = -1;
			}
		}
		else
		{
			// add cur_power
			values.push(cur_power);
			cur_power = -1;
		}
	}
	if (cur_power!=-1)
	{
		values.push(cur_power);
	}
	long long int ans = values.front();

	cout<<modPow(x, min(ans, a_sum));

}