//AC
#include "bits/stdc++.h"
using namespace std;
#define EPS 0.0000000000001
#define Point complex<long double>
#define dis(a) abs(a)

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	do 
	{
		/*
			In the case n = 3, 20 cells contain segments of the circle.
			There are 12 cells completely contained in the circle.
		*/
		int dr[] = {0,0,1,1};
		int dc[] = {0,1,0,1};
		long double R = n - 0.5;
		Point center(n,n);
		int in = 0;
		int com = 0;
		for (int i=0;i<2*n;i++)
		{
			for (int j=0;j<2*n;j++)
			{
				// cout<<"Pts \n";
				int in_points = 0;
				for (int t=0;t<4;t++)
				{
					Point p(i + dr[t], j+ dc[t]);
					// cout<<i + dr[t]<<" "<<j+ dc[t]<<endl;
					long double d = dis(p- center);
					if (d<=R || abs(d-R)<=EPS)
						in_points++;
				}
				if (in_points == 4)
					com++;
				else if(in_points)
					in++;
			}
		}
		printf("In the case n = %d, %d cells contain segments of the circle.\n",n,in);
		printf("There are %d cells completely contained in the circle.\n", com);
		if (cin>>n)
			printf("\n");
		else
			break;
	}while(n);
}