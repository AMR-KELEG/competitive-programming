/* AC

*/
#include "bits/stdc++.h"
using namespace std;
std::vector<int> prime_div;
std::vector<int> count_div;
std::vector<int> values;
std::vector<int> ans;
set<int> vis;
set<int> essential;

int N,R,K;
int origK;

void gen_output(int indx , int no)
{
	if (vis.find(no)!=vis.end() && essential.find(no)== essential.end())
		return ;
	if (vis.size()>=N)
		return;
	if (no<=R)
	{
		if (vis.find(no)==vis.end())
		{
			vis.insert(no);
			ans.push_back(no);	
		}
	}
	if (indx == prime_div.size())
	{
		return ;
	}

	int orig_no = no;
	for (int div_indx = indx; div_indx<prime_div.size() && vis.size()<N; div_indx++)
	{
		int cur_no = orig_no;
		for (int i=0;i<count_div[div_indx] && vis.size()<N; i++)
		{
			cur_no/=prime_div[div_indx];
			gen_output(div_indx+1, cur_no);
		}
	}
}

void find_div(int k)
{
	for (int i=2;i*i<=origK;i++)
	{
		if (k%i==0)
		{
			prime_div.push_back(i);
			count_div.push_back(0);
			while(k%i==0)
			{
				k/=i;
				count_div.back()++;
			}
		}
	}
	if (k>1)
	{
		prime_div.push_back(k);
		count_div.push_back(1);
	}
}

int dp[1024];

int solve(int mask)
{
	if (mask == 0)
		return 0;
	if (dp[mask]!=-1)
		return dp[mask];
	int min_steps = 10000000;
	for (int m=1;m<(1<<prime_div.size());m++)
	{
		if ((m & mask)== m)
		{
			// ok try it
			int val = 1;
			for (int sh=0;sh<prime_div.size();sh++)
			{
				if (m & (1<<sh))
				{
					val *= values[sh];
				}
			}
			if (val>R)
				continue;
			min_steps = min(min_steps, 1+solve(mask ^ m));
		}
	}
	return dp[mask] = min_steps;
}

void generate_essential_no(int mask)
{
	if (mask == 0)
		return ;
	int min_steps = solve(mask);
	for (int m=1;m<(1<<prime_div.size());m++)
	{
		if ((m & mask) == m)
		{
			// ok try it
			int val = 1;
			for (int sh=0;sh<prime_div.size();sh++)
			{
				if (m & (1<<sh))
				{
					val *= values[sh];
				}
			}
			if (val>R)
				continue;
			if (1+solve(mask^m) == min_steps)
			{
				ans.push_back(val);
				essential.insert(val);
				vis.insert(val);
				generate_essential_no(mask ^ m);
				return ;
			}
		}
	}
}
void prepare(int k)
{
	find_div(k);
	
	for (int i=0;i<prime_div.size();i++)
	{
		int p = prime_div[i];
		int val = p;
		for (int j=1;j<count_div[i];j++)
		{
			val *=p;
		}
		if (val>R)
		{
			printf("-1");
			return ;
		}
		// cout<<p<<"^"<<count_div[i]<<"="<<val<<endl;
		values.push_back(val);
	}

	memset(dp,-1, sizeof dp);
	int mask = (1<<(prime_div.size()))-1;
	if (solve(mask)>N)
	{
		printf("-1\n");
		return ;
	}
	// cout<<"Req "<<solve(mask)<<endl;
	// Generate numbers
	generate_essential_no(mask);
	// for (auto e:essential)
	// 	cout<<e<<endl;
	gen_output(0,K);
	if (ans.size()<N)
	{
		printf("-1\n");
		return ;
	}
	for (int i=0;i<N;i++)
	{
		if (i)
			printf(" ");
		printf("%d", ans[i]);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	scanf("%d %d %d", &N, &R, &K);
	if (K==1)
	{
		if (N==1)
			printf("1");
		else
			printf("-1");
		return 0;
	}
	origK=K;
	prepare(K);
	return 0;
}