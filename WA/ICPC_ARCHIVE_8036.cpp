// WA (WRONG TEST DATA?!)
#include "bits/stdc++.h"
using namespace std;
bool dp[15][10007];
int vis[15][10007];
int t=0;
int req_len;
#define MOD 10007
std::vector<int> indx_hash;
bool solve(int indx, int req_hash)
{
	req_hash %= MOD;
	if (indx == req_len)
	{
		return req_hash == 0;
	}

	if (vis[indx][req_hash] == t)
	{
		return dp[indx][req_hash];
	}
	vis[indx][req_hash] = t;
	for (int i=0;i<26;i++)
	{
		int cur_hash = (i * indx_hash[indx]) % MOD;
		int new_hash = (req_hash - cur_hash);
		while(new_hash<0)
			new_hash += MOD;
		if (solve(indx+1, new_hash))
		{
			return dp[indx][req_hash] = 1;
		}
	}
	return dp[indx][req_hash] = 0;
}
void generate_output(int indx, int req_hash)
{
	if (indx == req_len)
	{
		cout<<"\n";
		return ;
	}
	for (int i=0;i<26;i++)
	{
		int cur_hash = (i * indx_hash[indx]) % MOD;
		int new_hash = req_hash - cur_hash;
		while(new_hash<0)
			new_hash += MOD;
		if (solve(indx+1, new_hash))
		{
			cout<<char('A'+i);
			generate_output(indx+1, new_hash);
			return ;
		}
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	scanf("%d", &T);	
	for (t=1; t<=T; t++)
	{
		int L,H,M;
		scanf("%d %d %d", &L, &H, &M);
		if (M==0)
		{
			if (H>25)
				cout<<"None\n";
			else
				cout<<string(L-1,'A')<<char('A'+H)<<"\n";
			continue;
		}
		if (M==1)
		{
			if (H>25*L)
				cout<<"None\n";
			else
			{
				stack<char>st;
				while(L--)
				{
					if (H>=25)
					{
						H -=25;
						st.push('Z');
					}
					else
					{
						st.push('A'+H);
						H=0;
					}
				}
				while(!st.empty())
				{
					cout<<st.top();
					st.pop();
				}
				cout<<"\n";
			}
			continue;
		}
		// solve for 15 digits only
		req_len = min(L,15); 
		indx_hash = std::vector<int> (req_len,1);
		for (int i=req_len-2;i>=0;i--)
		{
			indx_hash[i] = (indx_hash[i+1] * M) % MOD;
		}
		if (!solve(0, H))
		{
			cout<<"None"<<"\n";
		}
		else
		{
			for (int i=0;i<L-15;i++)
				cout<<"A";
			generate_output(0, H);
		}

	}
}