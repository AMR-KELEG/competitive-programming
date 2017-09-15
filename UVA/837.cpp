// AC
// 11:03 - 11:23
#define EPS 0.0000000001
#define INF 1000000000000000000LL
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		if (n==0)
		{
			printf("1\n-inf +inf 1.000\n");
		}
		else
		{
			priority_queue<pair<long double , int> >q;// -x and indx
			std::vector<long double> c(n);
			for (int i=0;i<n;i++)
			{
				long double x1,y1,x2,y2;
				cin>>x1>>y1>>x2>>y2>>c[i];

				if (x2<x1)
					swap(x2,x1);
				q.push({-x1,i});
				q.push({-x2,i});	
			}
			std::vector<bool> isIn;
			long double last_x = -INF;
			std::vector<bool> is_in(n,0);
			int no_zero = 0;
			long double last_t = 1;
			long double cur_t = 1;
			std::vector<long double> st;
			std::vector<long double> en;
			std::vector<long double> tran;
			while(!q.empty())
			{
				long double cur_x = -q.top().first;
				int indx = q.top().second;
				q.pop();
				st.push_back(last_x);
				en.push_back(cur_x);
				if (no_zero)
				{
					tran.push_back(0);
				}
				else
				{
					tran.push_back(last_t);
				}
				
				if (!is_in[indx])
				{
					is_in[indx] = 1;
					if (abs(c[indx])<EPS)
					{
						no_zero++;
					}
					else
					{
						cur_t *= c[indx];
					}
				}
				else
				{
					is_in[indx] = 0;
					if (abs(c[indx])<EPS)
					{
						no_zero++;
					}
					else
					{
						cur_t /= c[indx];
					}
				}
				last_t = cur_t;
				last_x = cur_x;
			}

			st.push_back(last_x);
			en.push_back(INF);
			tran.push_back(1);
			printf("%d\n", st.size());
			for (int i=0;i<st.size();i++)
			{
				if(abs(st[i]+INF)<EPS)
				{
					printf("-inf ");
				}
				else
				{
					printf("%0.3LF ", st[i]);
				}
				if(abs(en[i]-INF)<EPS)
				{
					printf("+inf ");
				}
				else
				{
					printf("%0.3LF ", en[i]);
				}
				printf("%0.3LF\n", tran[i]);
			}
		}
		if (T)
			printf("\n");
	}
}