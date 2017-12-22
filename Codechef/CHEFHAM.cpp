// AC
#include "bits/stdc++.h"
using namespace std;
const int N = 100001;
int a[N];
int b[N];
int c[N]={};
bool done[N]={};
#define COUNT second
#define VAL first

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%d", &n);
		queue<int>q;
		for (int i=0;i<n;i++)
		{
			scanf("%d", &a[i]);
			q.push(a[i]);
			c[a[i]]++;
		}
		for (int _=0;_<2;_++)
		{
			for (int i=0;i<n;i++)
			{
				if (_==0 && c[a[i]]==1)
					continue;
				if (done[i])
					continue;
				done[i] = 1;
				if (a[i]!=q.front())
				{
					b[i] = q.front();
					q.pop();
				}
				else
				{
					// SEARCH FOR DIFF VAL
					queue<int> q2;
					while(!q.empty() && q.front()==a[i])
					{
						q2.push(q.front());
						q.pop();
					}
					if(!q.empty())
					{
						b[i]=q.front();
						q.pop();
					}
					else
					{
						b[i] = q2.front();
						q2.pop();
					}
					while(!q2.empty())
					{
						q.push(q2.front());
						q2.pop();
					}
				}
			}
		}
		int ham = 0;
		for (int i=0;i<n;i++)
		{
			ham += (a[i]!=b[i]);
			c[a[i]] = 0;
			done[i] = 0;
		}
		printf("%d\n", ham);
		for (int i=0;i<n;i++)
		{
			printf("%d ", b[i]);
		}
		printf("\n");

	}	
}