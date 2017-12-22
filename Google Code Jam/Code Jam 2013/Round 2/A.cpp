/* AC
- Greedy assignment
- It is better to keep oldest tickets in order to maximize the discount
- Don't forget mod
*/
#include "bits/stdc++.h"
using namespace std;
int n,p;
#define INF n+1
#define MOD 1000002013LL
long long int find_cost(int st, int des)
{
	long long int dis = des-st;
	long long int ans = (dis+1)*n - (dis*(dis+1))/2;
	return ans % MOD;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("A-large-practice.in","r",stdin);
		freopen("A-large-practice.out","w",stdout);
	#endif
	int T;
	scanf("%d", &T);
	for (int _=1;_<=T;_++)
	{
		scanf("%d %d", &n, &p);
		priority_queue<pair<int,int> >in;
		priority_queue<pair<int,pair<int,int>> >out;
		priority_queue<pair<int,int> >cur_tickets; // biggest st first, count
		long long int discounted_cost = 0;
		while(p--)	
		{
			int st,des,co;
			scanf("%d %d %d", &st, &des, &co);
			// insert somehow in queue
			in.push({-st,co});
			out.push({-des,{co, st}});
		}
		while (!out.empty())
		{
			int out_st = -out.top().first;
			int in_st = INF;
			if (!in.empty())
			{
				in_st = -in.top().first;
			}
			if (in_st<=out_st)
			{
				cur_tickets.push({in_st, in.top().second});
				in.pop();
			}
			else
			{	
				int out_c = out.top().second.first;
				int out_orig_st = out.top().second.second;
				out.pop();
				while(out_c)
				{
					int fake_st = cur_tickets.top().first;
					int fake_co = cur_tickets.top().second;
					cur_tickets.pop();
					int taken_co = min(fake_co, out_c);
					discounted_cost += 
						((find_cost(out_orig_st, out_st) - find_cost(fake_st, out_st))%MOD) *
						taken_co;
					discounted_cost %= MOD;
					while(discounted_cost<0)
					{
						discounted_cost+= MOD;
					}
					out_c-= taken_co;
					fake_co-= taken_co;
					if (fake_co)
					{
						cur_tickets.push({fake_st, fake_co});
					}
				}
			}
		}
		printf("Case #%d: %lld\n", _,discounted_cost%MOD);
	}
}