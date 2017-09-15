//AC - 4 submissions
#include "bits/stdc++.h"
using namespace std;
bool is_pos [501];

bool solve(int indx, int s)
{
	if(indx == 2)
	{
		if(abs(s)!=2)
		{
			return 0;
		}
		is_pos[2] = (s>0);
		return 1;
	}
	// Good optimization :D 
	bool odd_sum = int(ceil(0.5 * indx)-1) % 2;
	bool odd_req = abs(s) %2;
	if( (odd_req ^ odd_sum))
	{
		return 0;
	}
	int max_sum = (indx*(indx+1))/2;
	max_sum -= 1;
	if (s>max_sum || s<-max_sum)
		return 0;
	if(s)
	{
		is_pos[indx] = 1;
		bool done = solve(indx-1,s-indx);
		if (!done)
		{
			is_pos[indx] = 0;
			done = solve(indx-1,s+indx);
		}
		return done;
	}
	is_pos[indx] = 0;
	bool done = solve(indx-1,s+indx);
	if (!done)
	{
		is_pos[indx] = 1;
		done = solve(indx-1,s-indx);
	}
	return done;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,s;
	cin>>n>>s;
	int max_sum = (n*(n+1))/2;
	int min_sum = 2-max_sum;
	if(s<min_sum || s>max_sum)
	{
		cout<<"Impossible";
	}
	else if(n==1)
	{
		if(s==1)
			cout<<1;
		else
			"Impossible";
	}	
	else
	{
		// try to solve
		is_pos[1]=1;
		s -= 1;
		if(solve(n,s))
		{
			cout<<1;
			for(int i=2;i<=n;i++)
			{
				if (is_pos[i])
					cout<<"+"<<i;
				else
					cout<<"-"<<i;
			}
		}
		else
		{
			cout<<"Impossible";
		}
	}
}