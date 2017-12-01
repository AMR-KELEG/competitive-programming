/* AC
   Brute Force
*/

#include "bits/stdc++.h"
using namespace std;
#define EPS 1e-9

bool equal(long double val, int x)
{
	return abs(x-val)<EPS;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int total_dis, obst, bounce;
	scanf("%d %d %d", &total_dis, &obst, &bounce);
	std::vector<int> obs_x(obst);
	std::vector<int> obs_y(obst);
	for (int i=0,x,y;i<obst;i++)
	{
		scanf("%d %d", &x,&y);
		obs_x[i] =x;
		obs_y[i] =y;
	}
	std::vector<long double> Vx,Vy;
	for (int n_b = 1; n_b<=bounce + 1; n_b++)
	{
		long double L = ((long double) total_dis)/n_b;
		long double min_x = 0;
		long double max_x = L;
		// cout<<min_x<<" "<<max_x<<endl;
		int cur_obst =0;
		bool vx_set = 0;
		long double min_vx = 0;
		while(abs(min_x - total_dis)>EPS)
		{
			for (;cur_obst< obst;)
			{
				bool ok =(equal(min_x, obs_x[cur_obst]) || obs_x[cur_obst]>min_x) && 
						(equal(max_x, obs_x[cur_obst]) || obs_x[cur_obst]<max_x); 
				if (ok)
				{
					// process
					long double norm_x = obs_x[cur_obst] - min_x;
					long double cur_vx = 0.5 * norm_x * ((L - norm_x) / obs_y[cur_obst]);
					if (!vx_set)
					{
						vx_set = 1;
						min_vx = cur_vx;
					}
					else
						min_vx = min(min_vx, cur_vx);
					cur_obst++;
				}
				else
				{
					break;
				}
			}
			min_x += L;
			max_x += L;
		}
		long double max_attained_vx = sqrt(min_vx);
		long double min_v_vx = pow((0.25*L*L),0.25);
		if (max_attained_vx > min_v_vx || equal(max_attained_vx, min_v_vx))
		{
			// take min_v_vx
			Vx.push_back(min_v_vx);
			Vy.push_back(L*0.5/Vx.back());
		}
		else
		{
			Vx.push_back(max_attained_vx);
			Vy.push_back(L*0.5/Vx.back());
		}
		
	}
	long double ans = hypot(Vx[0], Vy[0]);
	for (int i=1;i<Vx.size();i++)
	{
		ans = min (ans , hypot(Vx[i], Vy[i]));
	}
	printf("%0.9LF\n", ans);
}