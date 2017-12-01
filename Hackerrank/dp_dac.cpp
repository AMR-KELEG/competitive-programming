/* AC
   Divide and Conquer DP optimization
   Good Editorial (y)
*/
#include "bits/stdc++.h"
using namespace std;
long long int F[801][8001]; // Group - Prisoner
int Craziness[8001];
long long int cum_sum[8001];
#define INF 10000000000000000LL

inline long long int Cost(int l, int r)
{
	if (l>r)
		return 0;
	return (r-l+1) * (cum_sum[r] - cum_sum[l-1]);
}

void fill(int g, int l1, int l2, int p1, int p2)
{
	if (l2<l1)
		return ;
	
	int lmid = (l1+l2)>>1;
	F[g][lmid] = INF;
	int best_k = -1;
	for (int k=p1;k<=p2;k++)
	{
		long long int cur_ans = F[g-1][k] + Cost(k+1, lmid);
		if (cur_ans< F[g][lmid])
		{
			best_k = k;
			F[g][lmid] = cur_ans;			
		}
	}
	fill(g,l1,lmid-1,p1,best_k);
	fill(g,lmid+1,l2,best_k,p2);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int L,G;
	scanf("%d %d",&L, &G);	
	for (int i=1,c;i<=L;i++)
	{
		scanf("%d", &c);
		Craziness[i] = c;
	}
	for (int i=1;i<=L;i++)
	{
		cum_sum[i] = cum_sum[i-1] + Craziness[i];
	}
	for (int l=1;l<=L;l++)
	{
		F[1][l] = Cost(1,l);
	}
	for (int g=2;g<=G;g++)
	{
		fill(g,1,L,1,L);
	}
	printf("%lld\n", F[G][L]);
}