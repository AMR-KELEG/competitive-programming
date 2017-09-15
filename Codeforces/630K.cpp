#include "bits/stdc++.h"
using namespace std;
long long int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
long long int lcm(int a,int b)
{
	return a*b/gcd(a,b);
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int n;
	cin>>n;
	long long int count=0;
	long long int d;
	long long int ones,sign;
	for(int id2=0;id2<2;id2++)
	{
		for(int id3=0;id3<2;id3++)
		{
			for(int id4=0;id4<2;id4++)
			{
				for(int id5=0;id5<2;id5++)
				{
					for(int id6=0;id6<2;id6++)
					{
						for(int id7=0;id7<2;id7++)
						{
							for(int id8=0;id8<2;id8++)
							{
								for(int id9=0;id9<2;id9++)
								{
									for(int id10=0;id10<2;id10++)
									{
										d=1;
										if(id2)
											d=lcm(d,2);
										if(id3)
											d=lcm(d,3);
										if(id4)
											d=lcm(d,4);
										if(id5)
											d=lcm(d,5);
										if(id6)
											d=lcm(d,6);
										if(id7)
											d=lcm(d,7);
										if(id8)
											d=lcm(d,8);
										if(id9)
											d=lcm(d,9);
										if(id10)
											d=lcm(d,10);
										ones=id2+id3+id4+id5+id6+id7+id8+id9+id10;
										sign=(ones%2)?1:-1;
										if(ones==0)
											continue;
										count+=(sign)*(n/d);
									}
								}
							}
						}
					}
				}

			}
		}		
	}
	cout<<n-count;
}