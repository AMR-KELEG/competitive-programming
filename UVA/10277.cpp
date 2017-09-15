//AC
#include "bits/stdc++.h"
#define EPS 0.0000000001
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	unsigned long long int p,q;
	cin>>p>>q;
	while(p!=0 || q!=0)
	{
		unsigned long long int g = __gcd(p,q);
		p/=g;
		q/=g;
		if(p==0)
		{
			cout<<"0 2"<<endl;
			cin>>p>>q;
			continue;
		}
		unsigned long long int R=0,B=0;
		bool found = 0;
		for(long long int nr=2;nr<=50000;nr++)
		{
			long double nb= (0.5-nr);
			long double q1= sqrt(p);
			long double a = p*0.25;
			long double q2= sqrt(1+((q/a)*nr*(nr-1)));
			nb+=q2*0.5;
			if(abs(round(nb)-nb)<=EPS)
			{
				if(!found && nr+round(nb)<=50000)
				{
					R=nr;
					B=round(nb);
					found=1;
				}
				else if(found)
				{
					if(nr+round(nb)<R+B)
					{
						R=nr;
						B=round(nb);		
					}
				}
			}
		}
		if(found)
		{
			cout<<R<<" "<<B<<endl;
		}
		else
			cout<<"impossible\n";
		cin>>p>>q;
	}	
}