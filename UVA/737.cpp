//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	while(n)
	{
		std::vector<int> min_c(3),max_c(3);
		
		for (int j=0;j<3;j++)
		{
			cin>>min_c[j];
		}
		int side_len;
		cin>>side_len;
		for (int j=0;j<3;j++)
			max_c[j] = min_c[j]+side_len;

		for (int i=1;i<n;i++)
		{
			std::vector<int> cur_c(3);
			for (int j=0;j<3;j++)
			{
				cin>>cur_c[j];
				min_c[j] = max(min_c[j], cur_c[j]);
			}
			cin>>side_len;
			for (int j=0;j<3;j++)
			{
				max_c[j] = min(max_c[j], cur_c[j]+side_len);
			}
		}
		int d [3];
		for (int j=0;j<3;j++)
		{
			d[j] = max(max_c[j] - min_c[j],0);
		} 
		cout<<d[0]*d[1]*d[2]<<endl;
		cin>>n;
	}	
}