// AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	string s;
	while(cin>>s)
	{
		int a=0,b=0;
		int indx =0;
		bool a_turn = 1;
		int i=0;
		for (;i<s.size();i++)
		{
			if (a_turn)
			{
				a += s[i]-'0';
			}
			else
			{
				b += s[i]-'0';	
			}
			a_turn = !a_turn;
			
			if(i<9)
			{
				int rema = floor(0.5*(9-i));
				int remb = ceil(0.5*(9-i));
				if (a>b && (a>remb+b))
					break;
				if (b>a && (b>rema+a))
					break;
			}
			else if (i%2)
			{
				if (a!=b)
					break;
			}
		}
		if (a==b)
			printf("TIE\n");
		else if(a>b)
			printf("TEAM-A %d\n", i+1);
		else
			printf("TEAM-B %d\n", i+1);
	}

	return 0;
}