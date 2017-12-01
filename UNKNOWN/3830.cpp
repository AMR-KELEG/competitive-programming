// AC
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		bool lessThanTwo=1;
		int xorSum=0;
		int no;
		while(n--)
		{
			cin>>no;
			xorSum^=no;
			lessThanTwo&=(no<2);
		}
		if(!lessThanTwo)
		{
			if(xorSum)
				cout<<"John\n";
			else
				cout<<"Brother\n";
		}
		else
		{
			if(xorSum==0)
				cout<<"John\n";
			else
				cout<<"Brother\n";
		}

	}
}
