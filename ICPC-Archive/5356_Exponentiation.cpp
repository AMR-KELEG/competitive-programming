#include "bits/stdc++.h"
using namespace std;
//big integer
void findp(double r,int p,unsigned long long int& integer,double& floatingpoint)
{
	long long int one=1;
	integer=one;
	long long int mul=r;
	cout<<mul<<endl<<endl;
	for(int i=0;i<p;i++)
	{
		integer*=mul;
		cout<<integer<<endl;
	}
	r=r-int(r);
	floatingpoint=1;
	for(int i=0;i<p;i++)
		floatingpoint*=r;
}
int main()
{
	freopen("in.txt","r",stdin);
	double R;
	int n;
	unsigned long long int integer;
	double floatingpoint;
	//cin>>R>>n;
	double res;
	string out;
	while(cin>>R>>n)
	{
		//cin>>R>>n;
		//res=pow(R,n);

		findp(R,n,integer,floatingpoint);
		std::ostringstream s;
		s<<std::fixed<<setprecision(65);
		s<<floatingpoint;
		//s>>out;
		cout<<integer<<endl;
		out=s.str();
		//cout<<out<<endl;
		s.flush();
	
	}
	
	
	return 0;
}