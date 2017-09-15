// AC
// 7:01
#include "bits/stdc++.h"
using namespace std;
std::vector<int> a;
int n;
long long int k;

bool validate(int rem)
{
	long long int total_rem =0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==0)
			continue;
		if(a[i]<rem)
			return 0;
		total_rem += rem;
	}
	return total_rem < k;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n>>k;
	a = std::vector<int> (n);
	priority_queue<int> q;
	long long int sum_visits =0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum_visits += a[i];
		q.push(-a[i]);
	}
	if(sum_visits<k)
	{
		cout<<-1;
	}
	else if(sum_visits>k)
	{
		long long int rem = n;
		int last =0;
		while(!q.empty())
		{
			int cur=-q.top();
			q.pop();
			if(cur == last)
			{
				rem --;
				continue;
			}
			// remove 
			if (rem * (cur-last) < k)
			{
				k -= rem * (cur-last);
				rem --;
				last = cur;
			}
			else
			{
				break;
			}
		}

		// cout<<"K: "<<k<<endl;
		for(int i=0;i<n;i++)
		{
			if(a[i]<last)
				a[i]=0;
			else
				a[i] -= last;
			// cout<<a[i]<<" ";
		}
		// cout<<endl<<endl;
		// remove as much as you can
		int l =0;
		int r=1000000000;
		while(l<r)
		{
			int mid = (l+r+1)>>1;
			if(validate(mid))
			{
				l = mid;
			}
			else
			{
				r = mid-1;
			}
		}
		int mid = (l+r+1)>>1;
		for(int i=0;i<n;i++)
		{
			if(a[i]==0)
				continue;
			a[i] -= mid;
			k -=mid;
		}
		queue<int> ans;
		for(int i=0;i<n;i++)
		{
			if(a[i]==0)
				continue;
			else
			{
				ans.push(i);				
			}
		}
		while(k)
		{
			int cur = ans.front();
			ans.pop();
			a[cur]--;
			k--;
			if(a[cur])
				ans.push(cur);
		}

		while(!ans.empty())
		{
			printf("%d ", 1+ans.front());
			ans.pop();
		}
	}
}