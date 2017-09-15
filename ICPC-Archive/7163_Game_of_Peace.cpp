#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ui;
ui gcd(ui a,ui b)
{
	 if (b == 0)
       return a;
    else
       return gcd(b, a % b);
}
int main()
{
	//freopen("in.txt","r",stdin);
	int T;
	ui x,y,n,m;
	cin>>T;
	int c=1;
	vector<unsigned long long int>fib;
	fib.push_back(0);
	fib.push_back(1);
	for(int i=2;i<=75;i++)
	{
		fib.push_back(fib[i-1]+fib[i-2]);
	}
	while(c<=T)
	{
		cin>>x>>n>>y>>m;
		if(n==0)
		{
			cout<<"Case "<<c<<": "<<x+y<<endl;
		}
		else 
		{
			//cout<<x*fib[n+1]+y<<" "<<x*fib[n]<<endl;
			cout<<"Case "<<c<<": "<<gcd(x*fib[n+1]+y,x*fib[n])<<endl;
		}
		c++;
	}

	return 0;
}