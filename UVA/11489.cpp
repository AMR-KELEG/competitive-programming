/* AC
- S always wins with single digit N.

- Digits 3,6,9 can be removed freely.
- Single Digit of value = total_sum%3 must be available as a first move 
except for the total_sum%3==0 case
*/
#include "bits/stdc++.h"
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	scanf("%d", &T);
	for (int t=1;t<=T;t++)
	{
		printf("Case %d: ", t);
		string s;
		cin>>s;
		if (s.size()==1)
		{
			printf("S\n");
			continue;
		}
		int c[3]={0,0,0};
		int total_sum = 0;
		for (int i=0;i<s.size();i++)
		{
			int val = (s[i]-'0')%3;
			c[val]++;
			total_sum += val;
		}
		if (c[total_sum%3])
		{
			if (total_sum%3 !=0)
				c[0]++;
			if (c[0]%2)
				printf("S\n");
			else
				printf("T\n");
		}
		else
		{
			printf("T\n");
		}

	}	
}