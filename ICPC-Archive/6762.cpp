/* AC
   Kadane's algorithm: 
   http://www.geeksforgeeks.org/dynamic-programming-set-27-max-sum-rectangle-in-a-2d-matrix/
   
   Running Time: 6 Sec
   Time Limit: 20 Sec !!
*/
#include "bits/stdc++.h"
using namespace std;
int grid[1000][1000];
int arr[1000];
int N,M;

int find_max_interval()
{
	int max_s = arr[0];
	int cur_s = arr[0];
	for (int c=1;c<M;c++)
	{
		if (cur_s<0)
			cur_s = arr[c];
		else
			cur_s += arr[c];
		max_s = max(max_s, cur_s);
	}
	return max_s;	
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &N, &M);
		int no;
		for(int i=0;i<N;i++)
		{
			for (int j=0;j<M;j++)
			{
				scanf("%d", &no);
				grid[i][j] = no;
			}
		}
		int ans = -2000000000;
		for (int rs=0;rs<N;rs++)
		{
			for (int c=0;c<M;c++)
			{
				arr[c] = grid[rs][c];
			}
			ans = max(ans, find_max_interval());
			for (int re=rs+1;re<N;re++)
			{
				for (int c=0;c<M;c++)
				{
					arr[c] += grid[re][c];
				}
				ans = max(ans, find_max_interval());
			}
		}
		printf("%d\n", ans);

	}	
}