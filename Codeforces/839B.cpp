//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int R,G;
	cin>>R>>G;
	int four = R;
	int two = 2*R;
	int one = 0;
	bool imp =0 ;

	// evens are good
	// 1 3 5 7

	std::vector<int> a(G);
	for(int i=0;i<G;i++)
	{
		cin>>a[i];
	}
	sort(a.rbegin(), a.rend());
	int i=0;
	while(four && i<G)
	{
		if(a[i]>=4)
		{
			a[i]-=4;
			i--;
			four--;
		}
		i++;
	}

	// for(i=0;i<G;i++)
	// {
	// 	cout<<a[i]<<" ";
	// }
	// cout<<endl;
	two += four;
	one = four;
	four = 0;

	for(i=0;i<G;i++)
	{
		while(two && a[i]>=2)
		{
			a[i]-=2;
			two--;
		}
		if(a[i]==1)
		{
			if(one)
			{
				one--;
				a[i]=0;
			}
			else if(two)
			{
				two--;
				a[i]=0;
			}
		}
		while(one && a[i])
		{
			a[i]--;
			one--;
		}
		if(a[i])
			break;
	}


	for(i=0;i<G;i++)
	{
		if(a[i]>0)
		{
			cout<<"no";
			return 0;
		}
	}

	cout<< "yes";

}