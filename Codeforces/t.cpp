#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n=100;
	cout<<1<<endl;
	cout<<n<<" "<<30<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if (abs(i-j)==1)
			{
				cout<<"Y";
			}
			else
				cout<<"N";
		}
		cout<<endl;
	}	
	cout<<99<<endl;
	for(int i=0;i<99;i++)
	{
		cout<<i+1<<" "<<(i+50)%100<<" "<<30<<endl;
	}
}