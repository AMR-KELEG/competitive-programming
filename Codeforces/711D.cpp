//AC
#include "bits/stdc++.h"
#define MOD (1000000007)
using namespace std;
std::vector<int> adjList;
std::vector<bool> vis;
std::vector<int> visTime;
std::vector<int> depth;
int len;
int curTime = 0;
long long int ans = 1;

long long int modPow(int mul,int p)
{
	if(p==0)
		return 1;
	if(p==1)
		return mul;
	long long int ans=modPow(mul,p>>1);
	ans=(ans*ans) % MOD;
	if(p%2)
		ans=(ans*mul) % MOD;
	return ans;
}

bool isCycle(int node,int d=0)
{
	if(vis[node] && visTime[node] == curTime)
	{
		int cycleLen = d - depth[node];
		ans = (ans*modPow(2,len-cycleLen)) % MOD;
		len = cycleLen;
		return true;
	}
	if(vis[node])
	{
		return false;
	}
	vis[node] = true;
	visTime[node] = curTime;
	depth[node] = d;
	len++;
	return isCycle(adjList[node],d+1);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	adjList = std::vector<int> (n);
	vis = std::vector<bool> (n,0);
	visTime = std::vector<int> (n,-1);
	depth = std::vector<int> (n,-1);
	for(int i=0;i<n;i++)
	{
		int p;
		cin>>p;
		adjList[i] = p-1;
	}
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			len = 0;
			curTime++;
			if(!isCycle(i))
			{
				//ans*=2^len
				ans=(ans*modPow(2,len)) % MOD;
			}
			else
			{
				long long int mul = modPow(2,len)%MOD;
				mul-=2;
				if(mul<0)
					mul+=MOD;
				ans=(ans*mul)%MOD;
			}
		}
	}
	cout<<ans;

}