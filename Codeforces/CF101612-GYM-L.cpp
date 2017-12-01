// AC
#include "bits/stdc++.h"
using namespace std;
#define Answer pair<long long int, pair<int,int> >
#define EPS 1e-9
int main()
{
	#ifdef ONLINE_JUDGE
		freopen("little.in","r",stdin);
		freopen("little.out","w",stdout);
	#endif
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	// cout<<fixed<<round(pow(2,30)*pow(3,15));
	// return 0;
	std::vector<long long int> powers_of_two;
	long long int val = 1;
	while(val <2000000000000000000LL)
	{
		powers_of_two.push_back(val);
		val*=2;
	}
	long long int n;
	cin>>n;
	for (auto t:powers_of_two)
	{
		if (n==t)
		{
			printf("-1");
			return 0;
		}
	}
	vector<Answer> ans;
	ans.push_back({n,{1,0}});

	long long int det = round(sqrt(1 + (4*n)));
	if (det*det == (1+4*n))
	{
		det ++;
		if (det%2==0)
		{
			long long int a = det/2;
			ans.push_back({a,{1,1}});
		}
	}

	det = round(sqrt(n));
	if (det*det == n)
	{
		ans.push_back({det,{2,0}});
	}
	
	long double one = 1;
	for (int terms = 3; terms<64;terms++)
	{
		int lim = 1 + round(pow(n,one/terms));
		// cout<<lim<<endl<<endl;
		for (int a = lim;a>=2;a--)
		{
			for (int x=1;x<=terms;x++)
			{
				long long int a1 = 1;
				long long int a2 = 1;
				int i=0;
				for (;i<x && a1<n;i++)
				{
					a1 *= a;
				}
				if (i!=x)
					continue;
				i = 0;
				for (;i<terms-x && a2<n;i++)
				{
					a2 *= a-1;
				}
				if (i!= terms-x)
					continue;
				if (a1*a2 == n)
				{
					ans.push_back({a,{x,terms-x}});
				}
			}
			// long long int a1 = 1;
			// long long int a2 = 1;
			// int c1 = 0;
			// int c2 = 0;
			// int i;
			// for (i=0;i<terms && a1<n;i++)
			// {
			// 	a1 *= a;
			// 	c1++;
			// }
			// for (;i<terms && a2<n;i++)
			// {
			// 	a2 *= a-1;
			// 	c2++;
			// }
			// if (a1*a2 == n && c1==c2)
			// {
			// 	// ok 
			// 	ans.push_back({a,{c1,c2}});
			// }
			// else
			// {
			// 	while(c1>1)
			// 	{
			// 		a1/=a;
			// 		a2 *= a-1;
			// 		c1--;
			// 		c2++;
			// 		cout<<a<<" : "<<(a1*a2)-n<<endl;
			// 		if (a1*a2 ==n)
			// 		{
			// 			ans.push_back({a,{c1,c2}});			
			// 		}
			// 		else if (a1*a2 <n)
			// 		{
			// 			break;
			// 		}
			// 	}
			// }
		}
	}
	printf("%d\n", (int)ans.size());
	for (auto a:ans)
	{
		printf("%d ", a.second.first+a.second.second);
		for (int i=0;i<a.second.first;i++)
		{
			printf("%I64d ", a.first);
		}
		for (int i=0;i<a.second.second;i++)
		{
			printf("%I64d ", a.first -1);
		}
		printf("\n");
	}

}