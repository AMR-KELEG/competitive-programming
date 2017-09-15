#include "bits/stdc++.h"
using namespace std;
std::vector<int> nos;

bool check()
{
	int n = nos.size();
	for(int f =0;f<n;f++)
	{
		for(int s=f+1;s<n;s++)
		{
			for(int t=s+1;t<n;t++)
			{
				if(nos[f]-nos[s]==nos[s]-nos[t])
				{
					cout<<nos[f]<<" "<<nos[s]<<" "<<nos[t]<<endl;
					return 0;
				}
			}
		}
	}
	return 1;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	// for(int n=3;n<11;n++)
	// {
	// 	cout<<"For "<<n<<endl;
	// 	nos = std::vector<int> (n);
	// 	for(int i=0;i<n;i++) nos[i]=i;
	// 	do 
	// 	{
	// 		// if(nos[0]!=0)
	// 		// 	continue;
	// 		if(check())
	// 		{
	// 			for(int i=0;i<n;i++)
	// 				cout<<nos[i]<<" ";
	// 			cout<<endl;
	// 		}
	// 	}
	// 	while(next_permutation(nos.begin(), nos.end()));
	// 	cout<<endl<<endl;
	// }	
	int n;
	cin>>n;
	while(n)
	{
		bool up =1;
		bool inc = 1;
		bool first = 1;
		int no =0;
		int count =0;
		list<int> l;
		auto it1 = l.begin();
		auto it2 = l.begin();
		while(no<=n)
		{	
			if(up)
			{
				if(count == 2)
				{
					count =0;
					if(1)
					{
						it1++;
						it1++;
						it2--;
						it2--;	
						if (first)
						{
							it1--;
							it2++;
							first = 0;
						}
					}
					// else
					// {
					// 	it1--;
					// 	it1--;
					// 	it2++;
					// 	it2++;	
					// }
					inc = !inc;
				}
				it1 = l.insert(it1,no);
			}
			else
			{
				count++;
				it2 = l.insert(it2,no);
				it2++;
			}
			up = !up;
			no+=2;
			for (auto c:l)
				cout<<c<<" ";
			cout<<endl;
		}
		for (auto c:l)
		{
			cout<<c<<" ";
			nos.push_back(c);
		}
		cout<<endl;
		if(check())
			cout<<"OKAYYY";
		cin>>n;
	}
}