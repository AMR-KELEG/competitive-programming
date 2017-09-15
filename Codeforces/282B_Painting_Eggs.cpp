#include "bits/stdc++.h"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin>>n;
	long long int a=0,g=0;
	int ap,gp;
	char out[1000000]={};
	for(int i=0;i<n;i++)
	{
		cin>>ap>>gp;
		if(abs((a+ap)-g)<=abs((g+gp)-a))
		{
			a+=ap;
			out[i]='A';
		}
		else
		{

			g+=gp;
			out[i]='G';
		}

	}

	if(abs(a-g)<=500)
	{
		for(int i=0;i<n;i++)
		cout<<out[i];
	}
	else
	{
		//cout<<"a: "<<a<<" g: "<<g<<" "<<out;
		cout<<-1;
	}

	return 0;
}