/* AC
   Basic Probabilities - Already Solved in Div2!
*/
#include "bits/stdc++.h"
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int team_mem, dep, herr_dep;
	scanf("%d %d %d", &team_mem, &dep, &herr_dep);
	herr_dep--;
	int total_mem =0;
	std::vector<int> dep_mem(dep);	
	for (int i=0,_;i<dep;i++)
	{
		scanf("%d", &_);
		dep_mem[i] = _;
		total_mem += _;
	}
	if (total_mem<team_mem)
	{
		printf("-1\n");
	}
	else
	{
		long double ans = 0;
		if (total_mem - dep_mem[herr_dep] < team_mem-1)
		{
			ans = 1;
		}
		else
		{
			ans = 1;
			int num1 = total_mem - dep_mem[herr_dep];
			int num2 = total_mem - team_mem;
			int den1 = total_mem - 1;
			int den2 = num1 - team_mem + 1;
			while (num1>1 || num2>1 || den1>1 || den2>1)
			{
				if (ans<1)
				{
					if (num1 > 1)
					{
						ans *= num1--;
					}
					else if (num2>1)
					{
						ans*= num2--;
					}
				}
				if (den1>1)
				{
					ans/=den1--;
				}
				else if (den2>1)
				{
					ans/=den2--;
				}
			}
			ans = 1 - ans;	
		}
		printf("%0.9LF\n", ans);
	}

}