#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("A-large.in","r",stdin);
	freopen("a.txt","w",stdout);
	long long int test;
	cin>>test;
	long long int n;
	set<char>val;
	for(long long int t=1;t<=test;t++)
	{
		val.clear();
		cin>>n;
		if(n==0)
		{
			cout<<"Case #"<<t<<": INSOMNIA\n";
		}
		else
		{
			long long int m=n;
			while(val.size()<10)
			{
				for(long long int i=m;i>0;i/=10)
				{
					val.insert(i%10);
				}
				m+=n;
			}
			cout<<"Case #"<<t<<": "<<m-n<<endl;
		}
	}	
}