//AC
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
	for(int t=1;t<=T;t++)
	{
		int n;
		std::vector<int> terms;
		cin>>n;
		for (int p = 30;p>=0 && n;p--)
		{
			if (n >= (1LL<<p) )
			{
				n-= (1LL<<p);	
				terms.push_back(p);
			}
		}
		printf("%d %d ", t,int(terms.size()));
		for(int i=0;i<terms.size();i++)
		{
			if(i==0)
				printf("[%d,0]", terms[i]);
			else
				printf(" [%d,0]", terms[i]);
		}
		printf("\n");
	}	
}