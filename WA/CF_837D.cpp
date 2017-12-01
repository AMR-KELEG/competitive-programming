// TLE
#include "bits/stdc++.h"
using namespace std;
map<pair<int,pair<int,int> >,int> dp; // indx, k, OFF + c5 - c2
#define INF 0x3f3f3f3f 
#define OFF 12800
std::vector<int> c2,c5;
int n,k;
int solve(int indx, int rem_k, int hash_val)
{
	if (indx == n)
		return (rem_k == 0)?0:-INF;
	if (rem_k == 0)
		return 0;
	// take or leave
	if (dp.find({indx,{rem_k,hash_val}}) != dp.end())
		return dp[{indx,{rem_k,hash_val}}];
	int ans = solve(indx+1,rem_k,hash_val);
	int c_2 = c2[indx];
	int c_5 = c5[indx];
	if (hash_val>OFF)
		c_5 += hash_val - OFF;
	else
		c_2 += OFF - hash_val;
	int cur_ans = min(c_2 , c_5);
	c_2 -= cur_ans;
	c_5 -= cur_ans;
	int new_hash_val = 0;
	if (c_2 > 0)
		new_hash_val = OFF - c_2;
	else
		new_hash_val = OFF + c_5;
	return dp[{indx,{rem_k,hash_val}}] = 
			max(ans,cur_ans + solve(indx+1,rem_k-1,new_hash_val));

}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n>>k;
	c2 = std::vector<int> (n,0);
	c5 = std::vector<int> (n,0);
	long long int no;
	for(int i=0;i<n;i++)
	{
		cin>>no;
		while(no%5==0)
		{
			c5[i]++;
			no/=5;
		}
		while(no%2==0)
		{
			c2[i]++;
			no/=2;
		}
	}
	cout<<solve(0,k,OFF);
}

// #include "bits/stdc++.h"
// using namespace std;
// std::vector<int> c2,c5;
// int dp[201][2][18002];
// #define INF 0x3f3f3f3f 
// #define OFF 12800
// int main()
// {
// 	std::ios::sync_with_stdio(false);
// 	#ifndef ONLINE_JUDGE
// 		freopen("in.txt","r",stdin);
// 	#endif
// 	memset(dp,-INF,sizeof dp);
// 	int n,k;
// 	cin>>n>>k;
// 	c2 = std::vector<int> (n,0);
// 	c5 = std::vector<int> (n,0);
// 	long long int no;
// 	for(int i=0;i<n;i++)
// 	{
// 		cin>>no;
// 		while(no%5==0)
// 		{
// 			c5[i]++;
// 			no/=5;
// 		}
// 		while(no%2==0)
// 		{
// 			c2[i]++;
// 			no/=2;
// 		}
// 	}
// 	int ans = 0;
// 	if (c2[0] > c5[0])
// 	{
// 		// OFF - (c2[0]-c5[0])
// 		if (c2[0]>c5[0])
// 		{
// 			dp[1][0][OFF - (c2[0]-c5[0])] = c2[0] - c5[0];
// 			if (k==1)
// 				ans = max(ans, dp[1][0][OFF - (c2[0]-c5[0])]);
// 		}
// 		else
// 		{
// 			dp[1][0][OFF + (c5[0]-c2[0])] = c5[0] - c2[0];
// 			if (k==1)
// 				ans = max(ans, dp[1][0][OFF + (c5[0]-c2[0])]);
// 		}

// 		for (int s = 0;s<=18001;s++)
// 			dp[0][0][s] = 0;
// 	}

// 	for (int indx = 1;indx<n;indx++)
// 	{
// 		for (int rk=0;rk<=k;rk++)
// 		{
// 			for (int s = 0;s<=18001;s++)
// 			{
// 				if (rk == 0)
// 				{
// 					dp[0][indx % 2][s] = 0;
// 					continue;
// 				}
// 				dp[rk][indx % 2][s] = dp[rk][(indx+1) %2][s];// leave it
// 				int co_2 = c2[indx],co_5 = c5[indx];
// 				int cur_s = OFF;
// 				if (s<OFF)
// 				{
// 					co_2 += OFF - s;
// 				}
// 				else
// 				{
// 					co_5 += s - OFF;
// 				}
// 				int cur_ans = abs(co_2 - co_5);
// 				co_5 -= cur_ans;
// 				co_2 -= cur_ans;
// 				if (co_2)
// 					cur_s = OFF - co_2;
// 				else
// 					cur_s = OFF - co_5;
// 				if (cur_s < 0 || cur_s > 18001)
// 					continue;	
				
// 				dp[rk][indx % 2][s] = 
// 					max(dp[rk][(indx+1) %2][s],
//     					cur_ans + dp[rk-1][(indx+1) %2][cur_s]);
// 				if (rk == k)
// 				{
// 					// cout<<"OK??\n";
// 					ans = max(ans, dp[rk][indx % 2][s]);
// 				}	
// 			}
			
// 		}
// 	}
// 	cout<<ans;
// 	return 0;
// }