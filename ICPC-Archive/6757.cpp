/* AC
   ACPC 2013
   Brute Force on three heros and binary search on other two.
*/
#include "bits/stdc++.h"
using namespace std;
pair<long long int,long long int> arr[1000000];
#define DAMAGE first
#define COST second
const long long int INF = 1e15;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int H;
		scanf("%lld", &H);
		int hits[5], damage[5], cost[5];
		for (int i=0;i<5;i++)
		{
			scanf("%d %d %d", &hits[i], &damage[i], &cost[i]);
		}
		int cur_indx = 0;
		for (long long int i=0;i<=hits[0];i++)
		{
			for (long long int j=0;j<=hits[1];j++)
			{
				long long int cur_cost = i * cost[0] + j*cost[1];
				long long int cur_damage = i * damage[0] + j*damage[1];
				arr[cur_indx++] = {cur_damage, cur_cost};
			}
		}
		sort(arr, arr+cur_indx);
		for (int i=cur_indx-2;i>=0;i--)
		{
			if (arr[i].COST>arr[i+1].COST)
			{
				arr[i] = arr[i+1];
			}
		}
		long long int min_cost = INF;
		long long int min_damage = INF; 
		for (long long int i=0;i<=hits[2];i++)
		{
			for (long long int j=0;j<=hits[3];j++)
			{
				for (long long int k=0;k<=hits[4];k++)
				{
					long long int cur_cost = i * cost[2] + j*cost[3] + k * cost[4];
					long long int cur_damage = i * damage[2] + j*damage[3] + k * damage[4];
					if (cur_damage >=H)
					{
						if (cur_cost<min_cost)
						{
							min_cost = cur_cost;
							min_damage = cur_damage;
						}
						else if (cur_cost == min_cost && cur_damage<min_damage)
						{
							min_damage = cur_damage;
						}
					}
					else
					{
						pair<long long ,long long> p = {H-cur_damage, -1};
						//search
						// lower bound on H - cur_damage
						int indx = lower_bound(arr, arr + cur_indx, p) - arr;
						if (indx < cur_indx)
						{
							cur_cost += arr[indx].COST;
							cur_damage += arr[indx].DAMAGE;
							if (cur_cost<min_cost)
							{
								min_cost = cur_cost;
								min_damage = cur_damage;
							}
							else if (cur_cost == min_cost && cur_damage<min_damage)
							{
								min_damage = cur_damage;
							}
						}
					}
				}
			}
		}
		if (min_damage == INF)
		{
			printf("We are doomed!!\n");
		}
		else
		{
			printf("%lld %lld\n", min_cost, min_damage);
		}
	}	
}